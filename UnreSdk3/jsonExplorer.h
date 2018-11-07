#ifndef _JSON_EXPLORER_H_
#define _JSON_EXPLORER_H_
#include <vector>
#include <tuple>
#include <unordered_map>
#include <string>

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

namespace unre
{	
	//包括friendName，用户密码，额外配置
	using baseDevInfo = std::tuple<std::string, std::string, std::string, std::string>;
	//using oneKindDevMap = std::unordered_map<std::string, baseDevInfo>;
	using oneKindDevMap = std::vector<std::tuple<std::string, baseDevInfo>>;//单纯为了一机多开

	class JsonExplorer
	{
	public:
		JsonExplorer() {};
		explicit JsonExplorer(const char*jsonFilePath);
		explicit JsonExplorer(const JsonExplorer&other);
		JsonExplorer & operator=(const JsonExplorer& other);
		~JsonExplorer() {};
		template<typename Dtype>
		inline static Dtype getValue(const rapidjson::Value &node, const char*key);
		template<typename Dtype>
		inline static Dtype getValue(const rapidjson::Value &node, const char*key,const int&valueCnt);

		////                       [ip:port][<friendName,userName,passWord,extraConfigFile>]
		////*deviceType* [ip:port][<friendName,userName,passWord,extraConfigFile>]
		////                       [ip:port][<friendName,userName,passWord,extraConfigFile>]
		const std::vector<std::tuple<std::string, oneKindDevMap>>& getDevInfo();

	private:
		rapidjson::Document docRoot;
		int cameraCnt;	
		
		////                       [ip:port][<friendName,userName,passWord,extraConfigFile>]
		////*deviceType* [ip:port][<friendName,userName,passWord,extraConfigFile>]
		////                       [ip:port][<friendName,userName,passWord,extraConfigFile>]
		std::vector<std::tuple<std::string, oneKindDevMap>> devInfo;
	};
}
#endif // !_JSON_EXPLORER_H_
