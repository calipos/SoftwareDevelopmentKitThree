#include<algorithm>
#include"jsonExplorer.h"
#include"stringOp.h"
#include"logg.h"

namespace unre
{
	template<>
	int JsonExplorer::getValue<int>(const rapidjson::Value&node, const char*key)
	{
		if (node.HasMember(key))
		{
			return node[key].GetInt();
		}
		else
		{
			LOG(FATAL) << "the json node:" << &node << ", has no member " << key << "!!!";
			return -1;
		}
	}
	template<>
	float JsonExplorer::getValue<float>(const rapidjson::Value&node, const char*key)
	{
		if (node.HasMember(key))
		{
			return node[key].GetFloat();
		}
		else
		{
			LOG(FATAL) << "the json node:" << &node << ", has no member " << key << "!!!";
			return -1;
		}
	}
	template<>
	double JsonExplorer::getValue<double>(const rapidjson::Value&node, const char*key)
	{
		if (node.HasMember(key))
		{
			return node[key].GetDouble();
		}
		else
		{
			LOG(FATAL) << "the json node:" << &node << ", has no member " << key << "!!!";
			return -1;
		}
	}
	template<>
	std::string JsonExplorer::getValue<std::string>(const rapidjson::Value&node, const char*key)
	{
		if (node.HasMember(key))
		{
			return node[key].GetString();
		}
		else
		{
			LOG(FATAL) << "the json node:" << &node << ", has no member " << key << "!!!";
			return "";
		}
	}
	template<>
	std::vector<float> JsonExplorer::getValue<std::vector<float>>(const rapidjson::Value&node, const char*key, const int&length)
	{
		CHECK(node.HasMember(key)) << "the json node:" << &node << ", has no member " << key << "!!!";
		CHECK(node[key].IsArray()) << "the json node:" << &node << ", " << key << " IS NOT A ARRAY!!!";
		if (node[key].Size() != length)
		{
			LOG(WARNING) << "the json feature length not match the config";
		}
		std::vector<float> value(length,(float)0);
		for (int i = 0; i < node[key].Size() &&i < length; i++)
		{
			value[i] = node[key][i].GetFloat();
		}
		return value;
	}
	template<>
	std::vector<double> JsonExplorer::getValue<std::vector<double>>(const rapidjson::Value&node, const char*key, const int&length)
	{
		CHECK(node.HasMember(key)) << "the json node:" << &node << ", has no member " << key << "!!!";
		CHECK(node[key].IsArray()) << "the json node:" << &node << ", " << key << " IS NOT A ARRAY!!!";
		if (node[key].Size() != length)
		{
			LOG(WARNING) << "the json feature length not match the config";
		}
		std::vector<double> value(length, (double)0);
		for (int i = 0; i < node[key].Size() &&i < length; i++)
		{
			value[i] = node[key][i].GetDouble();
		}
		return value;
	}

	JsonExplorer::JsonExplorer(const char*jsonFilePath)
	{
		docRoot.Parse<0>(unre::StringOP::parseJsonFile2str(jsonFilePath).c_str());
		if (!docRoot.IsArray())
		{
			LOG(FATAL) << "the json file err, not a array!!!";
		}
		cameraCnt = docRoot.Size();
		if (cameraCnt < 1)
		{
			LOG(FATAL) << "the json file err, just 1 sensor?!!!";
		}
		for (size_t i = 0; i < cameraCnt; i++)
		{
			std::string this_deviceType = getValue<std::string>(docRoot[i], "deviceType");
			std::string this_ip = getValue<std::string>(docRoot[i], "ip");
			if (!StringOP::isLegalIP(this_ip))
			{
				LOG(WARNING) << StringOP::utf8_2_mbs(this_ip) << " is illegal IP, so this config item will ignore!!!";
				continue;
			}
			int this_port = getValue<int>(docRoot[i], "port");
			if (this_port<0|| this_port>65534)//the rapid json not support uint16,so i read as int and judge it.
			{
				LOG(WARNING) << this_port << " is illegal port, so this config item will ignore!!!";
				continue;
			}
			std::string friendName = getValue<std::string>(docRoot[i], "friendName");
			std::string userName = getValue<std::string>(docRoot[i], "userName");
			std::string passWord = getValue<std::string>(docRoot[i], "passWord");
			std::string extraConfigFile = getValue<std::string>(docRoot[i], "extraConfigFile");
			if (devInfo.end() == std::find_if(devInfo.begin(), devInfo.end(), [&](auto&item) {
				const std::string& this_itemDevType = std::get<0>(item);
				if (this_itemDevType.compare(this_deviceType)==0)
				{
					//std::get<1>(item)[this_ip + ":" + std::to_string(this_port)] = std::make_tuple(friendName, userName, passWord, extraConfigFile);
					std::get<1>(item).emplace_back(
						std::make_tuple(
							this_ip + ":" + std::to_string(this_port), 
							std::make_tuple(friendName, userName, passWord, extraConfigFile)
						)
					);//单纯为了一机多开
					//LOG(INFO) << "deviceType:" << this_deviceType << "; " << this_ip << ":" << this_port << " has been registered.";
					return true;
				}
				return false;
			}))
			{
				devInfo.emplace_back(std::make_tuple(
					this_deviceType,
					oneKindDevMap{ std::make_tuple(this_ip + ":" + std::to_string(this_port),std::make_tuple(friendName, userName, passWord, extraConfigFile)) }
				));//单纯为了一机多开
				//devInfo.emplace_back(std::make_tuple(
				//	this_deviceType,
				//	oneKindDevMap{ {this_ip + ":" + std::to_string(this_port),std::make_tuple(friendName, userName, passWord, extraConfigFile)} }
				//));
			}
		}
	}

	JsonExplorer::JsonExplorer(const JsonExplorer&other)
	{
		cameraCnt = other.cameraCnt;
		devInfo = other.devInfo;
	}


	JsonExplorer & JsonExplorer::operator=(const JsonExplorer& other)
	{
		cameraCnt = other.cameraCnt;
		devInfo = other.devInfo;
		return *this;
	}

	const std::vector<std::tuple<std::string, oneKindDevMap>>& JsonExplorer::getDevInfo()
	{
		return devInfo;
	}

}