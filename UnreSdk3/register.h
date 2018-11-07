#ifndef _REGISTER_H_
#define _REGISTER_H_
#include <vector>
#include <string>
#include <list>
#include <tuple>
#include <fstream>
#include "logg.h"
#include"iofile.h"
#include"stringOp.h"
#include "jsonExplorer.h"
#include "rwLock.h"

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
//template<typename FeatureType>
//struct baseFeature
//{
//	Dtype* this_feature()
//	{
//		return *static_cast<Dtype*>(this);
//	}
//};
//template<typename Dtype, int FEATURELENGTH=512>
//struct Feature
//{
//	Dtype value[FEATURELENGTH];
//};

namespace unre
{


	template<typename Dtype>
	class Register
	{
	private:
		std::string theInitFile_;
		int featureLength_{-1};
		Register() {};
		explicit Register(const int&featureLength);
		~Register() {};
		
		int readRegisterJson(const std::string&path);
		rapidjson::Document docRoot;
		ReadWriteLock lcker;
	public:
		std::list < std::tuple<int, std::string, std::vector<Dtype>>> idx2feature{};
		////这个是人的名字
		std::vector<std::string> idx2string{};
		////这个是人的编号，编号有可能不是纯数字
		std::vector<std::string> idx2ExternIdx{};


		int writeRegisterJsonBack(const std::string&path);
		int addItem(const std::string&name, const std::string&externIndex, const std::string&imgPath, const std::vector<Dtype>feature);

		bool isRegisterInit() { return featureLength_ > 0; }
		int getFeatureLength() { return featureLength_; }
		int deleteItem(const std::string&externIndex);
		static Register*singleton;
		static Register* getRegister(const int&featureLength)
		{
			if (singleton == NULL)
			{
				singleton = new Register<Dtype>(featureLength);
			}
			return singleton;
		}
	};

	template<typename Dtype> Register<Dtype>* Register<Dtype>::singleton{NULL};

	template<typename Dtype>
	Register<Dtype>::Register(const int&featureLength)
	{
		featureLength_ = featureLength;
		if (UNRE_FUNCTION_SUCCESS!=readRegisterJson(""))
		{
			LOG(FATAL) << "UNRE_READ_JSON_FAILED";
		};
	}

	template<typename Dtype>
	int Register<Dtype>::readRegisterJson(const std::string&path)
	{		
		if (FileOP::FileExist("register.json"))
		{
			theInitFile_ = "register.json";
		}
		else if (FileOP::FileExist("register_default.json"))
		{
			theInitFile_ = "register_default.json";
		}
		else
		{
			theInitFile_ = "register_default.json";
			LOG(WARNING) << "no register json, even config_default.json!";
			return UNRE_READ_JSON_FAILED;
		}
		docRoot.Parse<0>(unre::StringOP::parseJsonFile2str(theInitFile_.c_str()).c_str());
		int config_featureLength = JsonExplorer::getValue<int>(docRoot, "FeatureLength");
		CHECK(config_featureLength == featureLength_) << "ERR! The feature length is not match!!!";
		if (!docRoot.HasMember("Items"))
		{
			LOG(WARNING) << "Though register json exist, there is no item in it!";
			return UNRE_READ_JSON_FAILED;
		}
		auto&items = docRoot["Items"];
		if (!items.IsArray())
		{
			LOG(ERROR) << "the register file err, not a array!!!";
			return UNRE_READ_JSON_FAILED;
		}
		else
		{
			int personCnt = items.Size();
			for (int personIdx = 0; personIdx < personCnt; personIdx++)
			{
				auto&this_person = items[personIdx];
				const std::string&this_personName = JsonExplorer::getValue<std::string>(this_person, "name");
				const std::string&this_personExternIdx = JsonExplorer::getValue<std::string>(this_person, "Index");
				LOG(INFO) << StringOP::utf8_2_mbs(this_personName);
				LOG(INFO) << StringOP::utf8_2_mbs(this_personExternIdx);
				if (idx2ExternIdx.end() != std::find(idx2ExternIdx.begin(), idx2ExternIdx.end(), this_personExternIdx))
				{
					LOG(ERROR) << "Register json file error! there exist 2 person shared same index, which is forbidden!!!";
					return UNRE_READ_JSON_FAILED;
				}
				idx2string.emplace_back(this_personName);//**
				idx2ExternIdx.emplace_back(this_personExternIdx);//**
				CHECK(this_person.HasMember("Features")) << "register json err! the person has no feature!";
				CHECK(this_person["Features"].IsArray()) << "register json err! the person feature not array!";
				int this_personFeatureCnt = this_person["Features"].Size();
				for (int this_personFeatureIdx = 0; this_personFeatureIdx < this_personFeatureCnt; this_personFeatureIdx++)
				{
					auto&oneFeature = this_person["Features"][this_personFeatureIdx];
					const std::string&regImgPath = JsonExplorer::getValue<std::string>(oneFeature, "regImgPath");
					CHECK(FileOP::FileExist(regImgPath)) << "The regImgPath[ " << regImgPath << " ] not exist";
					const std::vector<Dtype> theRegImgFeature = JsonExplorer::getValue<std::vector<Dtype>>(oneFeature, "Feature", featureLength_);
					idx2feature.push_back(std::make_tuple(idx2ExternIdx.size() - 1, regImgPath, theRegImgFeature));//**
				}
			}
		}
		LOG(INFO) << "Recovered from json file.";
		return UNRE_FUNCTION_SUCCESS;
	}
	
	template<typename Dtype>
	int Register<Dtype>::writeRegisterJsonBack(const std::string&path)
	{
		if (idx2string.size() != idx2ExternIdx.size())
		{
			LOG(FATAL) << "idx2ExternIdx & idx2string not match!!!";
			return UNRE_REGISTER_FATAL_ERROR;
		}
		//template<typename Dtype> std::list < std::tuple<int, std::string, std::vector<Dtype>>> Register<Dtype>::idx2feature{};
		//template<typename Dtype> std::vector<std::string> Register<Dtype>::idx2string;
		//template<typename Dtype> std::vector<std::string> Register<Dtype>::idx2ExternIdx;
		rapidjson::Document document;
		document.SetObject();
		rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
		document.AddMember("FeatureLength", featureLength_, allocator);
		rapidjson::Value Iterms(rapidjson::kArrayType);
		for (size_t i = 0; i < idx2ExternIdx.size(); i++)
		{
			rapidjson::Value onePerson(rapidjson::kObjectType);
			const std::string&externIndex = idx2ExternIdx[i];//写的时候不能把这个内容赋值或者拷贝到别的string中，因为观察到会在原内容前加入一些别的字符，导致写到json中乱码
			const std::string&personName = idx2string[i];//写的时候不能把这个内容赋值或者拷贝到别的string中，因为观察到会在原内容前加入一些别的字符，导致写到json中乱码
			LOG(INFO) << StringOP::utf8_2_mbs(externIndex);
			LOG(INFO) << StringOP::utf8_2_mbs(personName);
			onePerson.AddMember("Index", rapidjson::StringRef(externIndex.c_str()), allocator);
			onePerson.AddMember("name", rapidjson::StringRef(personName.c_str()), allocator);
			rapidjson::Value onePersonFeatures(rapidjson::kArrayType);
			for (auto&feature : idx2feature)
			{
				int internalIdx = std::get<0>(feature);
				const std::string&regImgPath = std::get<1>(feature);//写的时候不能把这个内容赋值或者拷贝到别的string中，因为观察到会在原内容前加入一些别的字符，导致写到json中乱码
				std::vector<Dtype> Feature = std::get<2>(feature);
				if (internalIdx == i)
				{
					rapidjson::Value oneFeature(rapidjson::kObjectType);
					//thePersonFeatureVect.emplace_back(feature);
					oneFeature.AddMember("regImgPath", rapidjson::StringRef(regImgPath.c_str()), allocator);
					rapidjson::Value featureList(rapidjson::kArrayType);
					for (int f_idx = 0; f_idx < Feature.size(); f_idx++)
					{
						featureList.PushBack(Feature[f_idx], allocator);
					}
					oneFeature.AddMember("Feature", featureList, allocator);
					onePersonFeatures.PushBack(oneFeature, allocator);
				}
			}
			onePerson.AddMember("Features", onePersonFeatures, allocator);
			
			Iterms.PushBack(onePerson, allocator);
		}
		document.AddMember("Items", Iterms, allocator);

		rapidjson::StringBuffer jsonBuffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(jsonBuffer);
		document.Accept(writer);
		std::ofstream fout(theInitFile_, std::ios::out);
		fout << jsonBuffer.GetString() << std::endl;
		fout.close();
		return 0;
	}

	template<typename Dtype>
	int Register<Dtype>::deleteItem(const std::string&externIndex)
	{
		//template<typename Dtype> std::list < std::tuple<int, std::string, std::vector<Dtype>>> Register<Dtype>::idx2feature{};
		//template<typename Dtype> std::vector<std::string> Register<Dtype>::idx2string;
		//template<typename Dtype> std::vector<std::string> Register<Dtype>::idx2ExternIdx;
		lcker.write_lock();
		int internalIdx = -1;
		int originalSize = idx2ExternIdx.size();
		for (auto it = idx2ExternIdx.begin(); it != idx2ExternIdx.end();)
		{
			internalIdx++;
			if (externIndex.compare(*it)==0) 
			{
				it = idx2ExternIdx.erase(it);    //删除元素，返回值指向已删除元素的下一个位置    
				break;
			}
			else
				++it;    //指向下一个位置
		}
		if (originalSize == idx2ExternIdx.size())
		{
			lcker.write_unlock();
			return UNRE_REGISTER_NO_SUCH_ITEM;
		}
		int stringInternalIdx = -1;
		int originalStringCnt = idx2string.size();
		for (auto it = idx2string.begin(); it != idx2string.end();)
		{
			stringInternalIdx++;
			if (internalIdx == stringInternalIdx) 
			{
				it = idx2string.erase(it);    //删除元素，返回值指向已删除元素的下一个位置    
				break;
			}
			else
				++it;    //指向下一个位置
		}
		if (stringInternalIdx == idx2string.size())
		{
			lcker.write_unlock();
			LOG(FATAL) << "idx2ExternIdx & idx2string not match!!!";
			return UNRE_REGISTER_FATAL_ERROR;
		}
		if (idx2string.size()!= idx2ExternIdx.size())
		{
			lcker.write_unlock();
			LOG(FATAL) << "idx2ExternIdx & idx2string not match!!!";
			return UNRE_REGISTER_FATAL_ERROR;
		}
		for (auto it = idx2feature.begin(); it != idx2feature.end();)
		{
			if (internalIdx == std::get<0>(*it)) 
			{
				it = idx2feature.erase(it);    //删除元素，返回值指向已删除元素的下一个位置    
			}
			else if(internalIdx < std::get<0>(*it))
			{
				std::get<0>(*it)--;
				++it;    //指向下一个位置
			}
			else
				++it;    //指向下一个位置
		}
		lcker.write_unlock();
		return UNRE_FUNCTION_SUCCESS;
	}

	template<typename Dtype>
	int Register<Dtype>::addItem(const std::string&name, const std::string&externIndex,
		const std::string&imgPath, const std::vector<Dtype>feature)
	{
		lcker.write_lock();
		//template<typename Dtype> std::list < std::tuple<int, std::string, std::vector<Dtype>>> Register<Dtype>::idx2feature{};
		//template<typename Dtype> std::vector<std::string> Register<Dtype>::idx2string;
		//template<typename Dtype> std::vector<std::string> Register<Dtype>::idx2ExternIdx;
		int theItemInternalIdx = -1;
		for (int i = 0; i < idx2ExternIdx.size(); i++)
		{
			if (idx2ExternIdx[i].compare(externIndex)==0)
			{
				theItemInternalIdx = i;
				break;
			}
		}
		if (theItemInternalIdx<0)//new person
		{
			CHECK(feature.size() == featureLength_)<<"err feature";
			LOG(INFO) << "New person will be added : " << name << " ( " << externIndex << " ) ";
			theItemInternalIdx = idx2ExternIdx.size();
			idx2ExternIdx.push_back(externIndex);
			idx2string.push_back(name);
			idx2feature.push_back(std::make_tuple(theItemInternalIdx,imgPath, feature));
		}
		else
		{
			if (name.compare(idx2string[theItemInternalIdx]) != 0)
			{
				lcker.write_unlock();
				LOG(INFO) << "added person name err!";
				return UNRE_REGISTER_ADD_ERRPR;
			}			
			idx2feature.push_back(std::make_tuple(theItemInternalIdx, imgPath, feature));
		}
		lcker.write_unlock();
		return UNRE_FUNCTION_SUCCESS;
	}
}
#endif