#ifndef _STRING_OP_H_
#define _STRING_OP_H_
#include <string>
#include <fstream>
#include <codecvt>
#include <locale>
#include <cassert>
#include "iofile.h"
#if defined(_DEBUG) || defined(DEBUG)
#define ASSERT(p) assert(p)
#else 
#define ASSERT( p ) (void)0;
#endif // DEBUG
namespace unre
{
	class StringOP
	{
	public:
		static std::string parseJsonFile2str(const char*jsonFilePath)
		{
			if (!FileOP::FilesExist(jsonFilePath))
			{
				return "";
			}
			else
			{
				std::fstream fi(jsonFilePath, std::ios::in);
				string stringFromStream;
				string line;
				while (std::getline(fi, line))
				{
					stringFromStream.append(line + "\n");
				}
				fi.close();
				return std::move(stringFromStream);
			}
		}
		static std::vector<std::string> splitString(const std::string& src, const std::string &symbols, bool repeat = false)
		{
			std::vector<std::string> result;
			int startIdx = 0;
			for (int i = 0; i < src.length(); i++)
			{
				bool isMatch = false;
				for (int j = 0; j < symbols.length(); j++)
				{
					if (src[i] == symbols[j])
					{
						isMatch = true;
						break;
					}
					if (!repeat)
					{
						break;
					}
				}
				if (isMatch)
				{
					std::string sub = src.substr(startIdx, i - startIdx);
					startIdx = i + 1;
					if (sub.length() > 0)
					{
						result.push_back(sub);
					}
				}
				if (i + 1 == src.length())
				{
					std::string sub = src.substr(startIdx, src.length() - startIdx);
					startIdx = i + 1;
					if (sub.length() > 0)
					{
						result.push_back(sub);
					}

				}
			}
			return std::move(result);
		}
		static bool isLegalIP(const std::string&IP)
		{
			auto sges = splitString(IP,".");
			if (sges.size()!=4)
			{
				return false;
			}
			std::string copyIP = "";
			for (int i = 0; i < 4; i++)
			{
				if (i == 0)
				{
					copyIP += std::to_string(atoi(sges[i].c_str()));
				}
				else
				{
					copyIP += ".";
					copyIP += std::to_string(atoi(sges[i].c_str()));
				}
			}
			if (copyIP.compare(IP)!=0)
			{
				return false;
			}
			return true;
		}
		
		/*convert unicode string to mbcs*/
		static inline std::string wstombs(const std::wstring &src)
		{
			setlocale(LC_ALL, "chs");// 设置为中文环境，不然可能会转换失败
			std::vector<char> dst(src.size() * 2 + 1, '\0');
			size_t count = std::wcstombs(&dst[0], src.c_str(), dst.size() - 1);
			ASSERT(count > 0 && count < dst.size());
			setlocale(LC_ALL, "");
			return std::string(&dst[0]);
		}

		/*convert mbcs to unicode string*/
		static inline std::wstring mbstows(const std::string &src)
		{
			setlocale(LC_ALL, "chs");// 设置为中文环境，不然可能会转换失败
			std::vector<wchar_t> dst(src.size() + 1, L'\0');
			size_t count = std::mbstowcs(&dst[0], src.c_str(), dst.size() - 1);
			ASSERT(count > 0 && count < dst.size());
			setlocale(LC_ALL, "");
			return std::wstring(&dst[0]);
		}

		/*convert unicode string to utf8*/
		static inline std::string wstoutf8(const std::wstring &src)
		{
			return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(src);
		}

		/*convert utf8 string to unicode string*/
		static inline std::wstring utf8tows(const std::string&src_utf8)
		{
			return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(src_utf8);
		}

		/*convert multi byte string(mbcs) to utf8 string*/
		static inline std::string mbstoutf8(const std::string& src_mbcs)
		{
			return wstoutf8(mbstows(src_mbcs));
		}

		/*convert utf8 string to mbcs*/
		static inline std::string utf8tombs(const std::string& src_utf8)
		{
			return wstombs(utf8tows(src_utf8));
		}

		static inline std::string utf8_2_mbs(const std::string&src_utf8)
		{
			return wstombs(utf8tows(src_utf8));
		}
	};


}
#endif // !_STRING_OP_H_
