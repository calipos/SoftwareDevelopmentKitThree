
#include<set>
#include<thread>
#include"logg.h"

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include "ES_Decoder.h"
#include "IpcSdk.h"
#include "SDL.h"
#include "JsonWrapper.h"
#include "Any.hpp"
using ESong::JsonWrapper;
using ESong::AnyCast;
class IpcCamera
{
public:
	IpcCamera(const std::string &ip, const unsigned int&port);
	std::string ip_;
	unsigned int port_;
	int sessionHandle_;
	void ConnetIP();
	void OpenChannel();
	static void StreamDataCallback_V2(int hSession, const char* frame, const char* stream, int size, void *pUser);
	void DoStreamDataCallback_V2(int hSession, const char* frame, const char* stream, int size);

	
};
IpcCamera::IpcCamera(const std::string &ip, const unsigned int&port)
{
	auto ret = ES_InitSdk("EFGHFDBJKIIMGPJEEBHLFGEKHINCHBNLGFFDBMCJAPJILBLNDBACCOPGGJLNINLOANMKKGDNOOMGBMCMJNNHJN");
	LOG(INFO) << ret;

	ret = ES_AddDeviceStateCallback([](int hSession, ES_DEVICE_STATE state, void *pUser) {
		LOG(INFO) << "hSession : " << hSession << " Device State : " << state;
	}, this);
	LOG(INFO) << ret;

	auto iRet = SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
	LOG(INFO) << ret;

	ip_ = ip;
	port_ = port;
}
void IpcCamera::ConnetIP()
{	
	int zone = 8 * 60 * 60;
	auto ret = ES_ConnectIP(ES_DEVICE_TYPE_K20, ip_.c_str(), (uint16_t)port_, zone, &sessionHandle_);
	LOG(INFO) << ret;
	std::this_thread::sleep_for(std::chrono::seconds(2));
}
void IpcCamera::OpenChannel()
{
	auto ret = ES_OpenChannel_V2(sessionHandle_, ES_ST_HD, &IpcCamera::StreamDataCallback_V2, this);
	
	if (ret!=0)
	{
		LOG(FATAL) << ret;
	}
}

void IpcCamera::StreamDataCallback_V2(int hSession, const char* frame, const char* stream, int size, void *pUser)
{
	//IpcCamera* pThis = (IpcCamera *)pUser;
	//pThis->DoStreamDataCallback_V2(hSession, frame, stream, size);
}

void IpcCamera::DoStreamDataCallback_V2(int hSession, const char* frame, const char* stream, int size)
{
	auto ma = JsonWrapper::ReadJson(frame);
	auto type = AnyCast<std::string>(ma["type"]);
	if (type == "audio")
	{

	}
	else if (type == "video")
	{
		std::unique_ptr<char[]> ptr(new char[size + sizeof(ES_Frame)]);
		memcpy(ptr.get() + sizeof(ES_Frame), stream, size);
		auto pFrame = (ES_Frame *)ptr.get();
		memset(pFrame, 0, sizeof(ES_Frame));
		pFrame->frame_type = AnyCast<int>(ma["frame_type"]);
		pFrame->width = AnyCast<int>(ma["width"]);
		pFrame->height = AnyCast<int>(ma["height"]);
		pFrame->fps_base = AnyCast<int>(ma["fps"]);
		pFrame->size = AnyCast<int>(ma["size"]);

	}
}


int TEST_Ipc()
{
	IpcCamera test_ipc("192.168.2.90",5000);
	test_ipc.ConnetIP();
	test_ipc.OpenChannel();
	std::this_thread::sleep_for(std::chrono::seconds(500));
	return 0;
}