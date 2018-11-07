#ifndef _DEVICE_EXPLORER_H_
#define _DEVICE_EXPLORER_H_

#include<tuple>
#include<unordered_map>
#include<string>
#include<vector>
#include<mutex>
#include<condition_variable>

#include "logg.h"
#include "ringBuffer.h"
#include "jsonExplorer.h"
#include "device.h"


namespace unre
{


	class DeviceExplorer
	{
	public:
		DeviceExplorer() {};
		DeviceExplorer(
			const std::string&jsonFile,
			const std::vector<std::tuple<std::string, oneKindDevMap>>&devIndo)
			:jsonFile_(jsonFile), devIndo_(devIndo) {};
		int initialAllDev() ;
		int tryConnectAllDev() ;
		
		static std::vector<FrameRingBuffer<unsigned char>*> bufferVectP;

		int pushAllStream() ;
		int popAllFrame();
		unsigned char* popFrame(int deviceIdx);
	private:
		std::string jsonFile_;//this file is the init file, that is useful for modifying the intriParam
		
		std::vector<std::tuple<std::string, oneKindDevMap>>devIndo_;
		std::vector<std::tuple<std::string, std::string>>  configFilPath_;

		bool isDevicesInit{ false };
		bool isDevicesRunning{ false };

		std::unordered_map<std::string, bool> initOKmap;//[ip][isInitOK]
		std::unordered_map<std::string, std::tuple<bool, int>> connectOKmap;//[ip][isConnectOK,sessionHandle]
		
		std::vector<Device*>devices;
	};

}



#endif

