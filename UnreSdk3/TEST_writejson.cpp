#include <fstream>
#include"stringOp.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include"logg.h"
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
#include"register.h"
using namespace std;


#include <cassert>
#include <locale>
#include <codecvt>

using namespace rapidjson;
using namespace unre;

int TEST_read_write_json()
{
	rapidjson::Document readRoot;
	readRoot.Parse<0>(unre::StringOP::parseJsonFile2str("register_default.json").c_str());
	const std::string&ele = readRoot["Items"][0]["name"].GetString();	
	LOG(INFO) << StringOP::utf8_2_mbs(ele);
	std::string lua = "C:/Users/Admin/Desktop/repo/UnreSdk3/x64/Debug/regImg/lilei1.png";


	auto xxx = unre::Register<float>::getRegister(512);
	auto yy = xxx->idx2ExternIdx;
	auto zz = xxx->idx2string;
	LOG(INFO) << StringOP::utf8_2_mbs(yy[0]);
	LOG(INFO) << StringOP::utf8_2_mbs(yy[1]);

	Document document;
	document.SetObject();
	Document::AllocatorType& allocator = document.GetAllocator();
	document.AddMember("featurelength", 512, allocator);
	rapidjson::Value Iterms(rapidjson::kArrayType);
	{
		rapidjson::Value onePerson(rapidjson::kObjectType);
		std::string externIndex = yy[0];
		std::string personName = zz[0];

		onePerson.AddMember("name", rapidjson::StringRef(yy[0].c_str()), allocator);
		onePerson.AddMember("string_key", rapidjson::StringRef(zz[0].c_str()), allocator);
		Iterms.PushBack(onePerson, allocator);
	}
	{
		rapidjson::Value onePerson(rapidjson::kObjectType);
		onePerson.AddMember("name", rapidjson::StringRef(yy[1].c_str()), allocator);
		onePerson.AddMember("string_key", rapidjson::StringRef(lua.c_str()), allocator);
		Iterms.PushBack(onePerson, allocator);
	}
	document.AddMember("Iterms", Iterms, allocator);
	

	StringBuffer jsonBuffer;
	Writer<StringBuffer> writer(jsonBuffer);
	document.Accept(writer);

	std::ofstream fout("write.json", std::ios::out);
	fout << jsonBuffer.GetString() << std::endl;
	fout.close();

	return 0;
}