#include "register.h"


int TEST_register()
{
	auto xxx = unre::Register<float>::getRegister(512);
	xxx->writeRegisterJsonBack("");
	xxx->deleteItem(u8"川R00001");  //注意这里删除需要传入utf8的字符
	//xxx->writeRegisterJsonBack("");
	xxx->addItem("JIM",u8"川R00003","C:/Users/Admin/Desktop/repo/UnreSdk3/x64/Debug/regImg/jim1.png",std::vector<float>(512,1));
	xxx->writeRegisterJsonBack("");
	return 0;
}