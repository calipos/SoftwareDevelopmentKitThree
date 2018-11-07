
#include<set>
#include<thread>
#include"stringOp.h"
#include"deviceExplorer.h"
//#include"dataExplorer.h"
#include"ringBuffer.h"

#include "ES_Decoder.h"
#include "IpcSdk.h"
#include "SDL.h"
#include "JsonWrapper.h"
#include "Any.hpp"
using ESong::JsonWrapper;
using ESong::AnyCast;


namespace unre
{

	int DeviceExplorer::initialAllDev()
	{		
		for (auto&dev : devIndo_)
		{
			const std::string &deviceType = std::get<0>(dev);
			if (deviceType.compare("KH1")==0)
			{
				LOG(INFO) << "ES_Version :" << ES_GetVersion();
				bool isThisInitOK = true;
				auto ret = ES_InitSdk("EFGHFDBJKIIMGPJEEBHLFGEKHINCHBNLGFFDBMCJAPJILBLNDBACCOPGGJLNINLOANMKKGDNOOMGBMCMJNNHJN");
				LOG(INFO) << "[ES_InitSdk] ret = " << ret;
				if (ret != 0)
				{
					isThisInitOK = false;
					LOG(WARNING) << " ES_InitSdk err!";
				}
				if (0 != ES_SetLogCallback([](ES_LOG_LEVEL level, const char* log, void *pUser)
				{
					LOG(INFO) << "ipcLOG :" << pUser << "|" << log;
				}, this))
				{
					isThisInitOK = false;
					LOG(WARNING) << " ES_AddDeviceStateCallback err!";
				}
				if (0 != ES_AddDeviceStateCallback([](int hSession, ES_DEVICE_STATE state, void *pUser)
				{
					LOG(INFO) << "pUser :" << pUser;
					LOG(INFO) << "hSession :" << hSession;
					LOG(INFO) << "state :" << state;
				}, this))
				{
					isThisInitOK = false;
					LOG(WARNING) << " ES_AddDeviceStateCallback err!";
				}
				auto iRet = SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
				LOG(INFO) << "[SDL_Init] ret = " << iRet;
				if (0 != iRet)
				{
					isThisInitOK = false;
					LOG(WARNING) << " SDL_Init err!";
				}
				if (!isThisInitOK)
				{
					continue;
				}
				const oneKindDevMap &KH1map = std::get<1>(dev);
				for (auto&camera : KH1map)
				{
					std::vector<std::string> segs = StringOP::splitString(std::get<0>(camera), ":");//单纯为了一机多开
					std::string this_ip = segs[0];//单纯为了一机多开
					const int this_port = atoi(segs[1].c_str());//单纯为了一机多开
					const std::string&frinedname = std::get<0>(std::get<1>(camera));//单纯为了一机多开
					const std::string&username = std::get<1>(std::get<1>(camera));//单纯为了一机多开
					const std::string&password = std::get<2>(std::get<1>(camera));//单纯为了一机多开
					const std::string&extrafilepath = std::get<3>(std::get<1>(camera));//单纯为了一机多开
					//std::vector<std::string> segs = StringOP::splitString(camera.first, ":");
					//std::string this_ip = segs[0];
					//const int this_port = atoi(segs[1].c_str());
					//const std::string&frinedname = std::get<0>(camera.second);
					//const std::string&username = std::get<1>(camera.second);
					//const std::string&password = std::get<2>(camera.second);
					//const std::string&extrafilepath = std::get<3>(camera.second);
				}
			}
		}
		return 0;
	}


	int DeviceExplorer::tryConnectAllDev()
	{		
		for (auto&dev : devIndo_)
		{
			const std::string &deviceType = std::get<0>(dev);
			if (deviceType.compare("KH1") == 0)
			{
				const oneKindDevMap &KH1map = std::get<1>(dev);
				for (auto&camera : KH1map)
				{
					std::vector<std::string> segs = StringOP::splitString(std::get<0>(camera), ":");//单纯为了一机多开
					std::string this_ip = segs[0];//单纯为了一机多开
					const int this_port = atoi(segs[1].c_str());//单纯为了一机多开
					const std::string&frinedname = std::get<0>(std::get<1>(camera));//单纯为了一机多开
					const std::string&username = std::get<1>(std::get<1>(camera));//单纯为了一机多开
					const std::string&password = std::get<2>(std::get<1>(camera));//单纯为了一机多开
					const std::string&extrafilepath = std::get<3>(std::get<1>(camera));//单纯为了一机多开
					//std::vector<std::string> segs = StringOP::splitString(camera.first, ":");
					//std::string this_ip = segs[0];
					//const int this_port = atoi(segs[1].c_str());
					//const std::string&frinedname = std::get<0>(camera.second);
					//const std::string&username = std::get<1>(camera.second);
					//const std::string&password = std::get<2>(camera.second);
					//const std::string&extrafilepath = std::get<3>(camera.second);

					devices.emplace_back(new Device(this_ip, this_port, username, password, extrafilepath));
					devices[devices.size() - 1]->tryConnectDev();
				}
			}
		}
		return 0;
	}
	
	int DeviceExplorer::pushAllStream()
	{
		int ret = 0;
		for (auto dev : devices)
		{
			dev->pushStream();
		}
		return ret;
	}

	unsigned char* DeviceExplorer::popFrame(int deviceIdx)
	{
		return devices[deviceIdx]->popFrame();
	}

	int DeviceExplorer::popAllFrame()
	{
		int ret = 0;
		while (true)
		{
			for (auto dev : devices)
			{
				auto popedData = dev->popFrame();
			}
		}
		
		
		
		return ret;
		return 0;
	}


}
