
#ifndef __ESONG_JSON_WRAPPER_H_INC__
#define __ESONG_JSON_WRAPPER_H_INC__

#include "Any.hpp"

#include <stdio.h>
#include <string>
#include <map>
#include <list>
#include <type_traits>
#include <sstream>


namespace ESong
{
	class JsonWrapper
	{
	public:
		static std::string MakeJson(std::map<std::string, Any> dictionary)
		{
			return MakeJsonByDictionary(dictionary);
		}

		static std::map<std::string, Any> ReadJson(const std::string& json)
		{
			auto index = 0U;
			auto dictionary = ReadDictionary(json, index);
			if(index != json.size())
				throw "Json Illegal";

			return dictionary;
		}

	private:
		static std::string MakeJsonByDictionary(std::map<std::string, Any> dictionary)
		{
			std::string ret = "{";
			for(std::map<std::string, Any>::iterator itor = dictionary.begin(); itor != dictionary.end(); ++itor)
			{
				if(itor != dictionary.begin())
					ret += ", ";

				ret += "\"" + itor->first + "\": ";
				
				if (itor->second.type() == typeid(std::string))
					ret += MakeJsonByString(AnyCast<std::string>(itor->second));
				else if (itor->second.type() == typeid(int))
					ret += MakeJsonByValue(AnyCast<int>(itor->second));
				else if (itor->second.type() == typeid(unsigned))
					ret += MakeJsonByValue(AnyCast<unsigned>(itor->second));
				else if(itor->second.type() == typeid(double))
					ret += MakeJsonByDouble(AnyCast<double>(itor->second));
				else if(itor->second.type() == typeid(std::list<Any>))
					ret += MakeJsonByArray(AnyCast<std::list<Any>>(itor->second));
				else if(itor->second.type() == typeid(std::map<std::string, Any>))
					ret += MakeJsonByDictionary(AnyCast<std::map<std::string, Any>>(itor->second));
				else
					throw "unknown typeid";
			}

			ret += "}";
			return ret;
		}

		static std::string MakeJsonByArray(std::list<Any> lst)
		{
			std::string ret = "[";
			for(std::list<Any>::iterator itor = lst.begin(); itor != lst.end(); ++itor)
			{
				if(itor != lst.begin())
					ret += ", ";

				if(itor->type() == typeid(std::string))
					ret += MakeJsonByString(AnyCast<std::string>(*itor));
				else if(itor->type() == typeid(std::list<Any>))
					ret += MakeJsonByArray(AnyCast<std::list<Any>>(*itor));
				else if(itor->type() == typeid(std::map<std::string, Any>))
					ret += MakeJsonByDictionary(AnyCast<std::map<std::string, Any>>(*itor));
				else
					throw "unknown typeid";
			}

			ret += "]";
			return ret;
		}

		static std::string MakeJsonByString(std::string str)
		{
			std::string ret = "\"";
			for(std::string::iterator itor = str.begin(); itor != str.end(); ++itor)
			{
				if(*itor == '\"')
					ret += "\\\"";
				else if(*itor == '\\')
					ret += "\\\\";
				else
					ret += *itor;
			}
			ret += "\"";
			return ret;
		}

		template<class T>
		static std::string MakeJsonByValue(T value)
		{
			static_assert(std::is_integral<T>::value, "Integral required.");
			std::stringstream ss;
			ss << value;
			return ss.str();
		}

		static std::string MakeJsonByDouble(double d)
		{
			char buf[1024];
			sprintf(buf, "%0.8lf", d);

			return buf;
		}

		static std::map<std::string, Any> ReadDictionary(const std::string& json, unsigned& index)
		{
			if(json.at(index++) != '{')
				throw "Json Illegal";

			std::map<std::string, Any> dictionary;
			bool isFirst = true;
			while(index < json.size())
			{
				ReadSpaces(json, index);
				if(json.at(index) == '}')
				{
					++index;
					return dictionary;
				}

				if(!isFirst)
				{
					ReadSpaces(json, index);
					if(json.at(index++) != ',')
						throw "Json Illegal";
				}
				isFirst = false;

				ReadSpaces(json, index);
				auto key = ReadString(json, index);

				ReadSpaces(json, index);
				if(json.at(index++) != ':')
					throw "Json Illegal";

				ReadSpaces(json, index);
				auto val = ReadValue(json, index);

				dictionary[key] = val;
			}

			throw "Json Illegal";
		}

		static std::list<Any> ReadArray(const std::string& json, unsigned& index)
		{
			if(json.at(index++) != '[')
				throw "Json Illegal";

			std::list<Any> lst;
			bool isNeedEnd = false;
			while(index < json.size())
			{
				ReadSpaces(json, index);
				if(json.at(index) == ']')
				{
					++index;
					return lst;
				}

				if(isNeedEnd)
					throw "Json Illegal";

				ReadSpaces(json, index);
				auto val = ReadValue(json, index);

				lst.push_back(val);

				ReadSpaces(json, index);
				if(json.at(index) == ',')
					++index;
				else
					isNeedEnd = true;
			}

			throw "Json Illegal";
		}

		static Any ReadValue(const std::string& json, unsigned& index)
		{
			char ch = json.at(index);
			if(ch == '\"')
				return ReadString(json, index);
			else if(ch == '{')
				return ReadDictionary(json, index);
			else if(ch == '[')
				return ReadArray(json, index);
			else if((ch >= '0' && ch <= '9') || ch == '-')
				return ReadInt(json, index);
			else
				throw "Json Illegal";
		}

		static void ReadSpaces(const std::string& json, unsigned& index)
		{
			while(index < json.size())
			{
				char ch = json.at(index);
				if(ch != ' ' && ch != '\n')
					return;

				++index;
			}
		}

		static std::string ReadString(const std::string& json, unsigned& index)
		{
			if(json.at(index++) != '\"')
				throw "Json Illegal";

			std::string ret = "";
			bool isEscape = false;
			while(index < json.size())
			{
				char ch = json.at(index++);

				if(isEscape)
				{
					ret += ch;
					isEscape = false;
					continue;
				}

				if(ch == '\\')
					isEscape = true;
				else if(ch == '\"')
					return ret;
				else
					ret += ch;
			}

			throw "Json Illegal";
		}

		static int ReadInt(const std::string& json, unsigned& index)
		{
			int multi = 1;
			if(json.at(index) == '-')
			{
				multi = -1;
				++index;
			}
			
			int ret = 0;
			while(index < json.size())
			{
				char ch = json.at(index);
				
				if(ch < '0' || ch > '9')
					return ret * multi;

				ret = ret * 10 + ch - '0';
				++index;
			}

			throw "Json Illegal";
		}
	};
}

#endif