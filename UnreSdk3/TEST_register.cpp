#include "register.h"


int TEST_register()
{
	auto xxx = unre::Register<float>::getRegister(512);
	xxx->writeRegisterJsonBack("");
	xxx->deleteItem(u8"��R00001");  //ע������ɾ����Ҫ����utf8���ַ�
	//xxx->writeRegisterJsonBack("");
	xxx->addItem("JIM",u8"��R00003","C:/Users/Admin/Desktop/repo/UnreSdk3/x64/Debug/regImg/jim1.png",std::vector<float>(512,1));
	xxx->writeRegisterJsonBack("");
	return 0;
}