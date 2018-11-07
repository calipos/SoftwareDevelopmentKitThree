#ifndef _DEVICE_H_
#define _DEVICE_H_

#include<tuple>
#include<unordered_map>
#include<string>
#include<vector>
#include<mutex>
#include<condition_variable>

#include "logg.h"
#include "ringBuffer.h"

#include "opencv2/opencv.hpp"

#include "ES_Decoder.h"
#include "IpcSdk.h"
#include "SDL.h"
#include "JsonWrapper.h"
#include "Any.hpp"
using ESong::JsonWrapper;
using ESong::AnyCast;
using ESong::Any;


struct UnreRect
{
	int idx;
	int x;
	int y;
	int w;
	int h;
};
#define MAX_FACEDETEC (20)
struct UnreRectS
{
	int currentFaceNum;
	UnreRect UnreRect[MAX_FACEDETEC];
};

namespace unre
{


	class Device
	{
	public:
		Device() {};
		Device(const std::string&ip, const int &port,const std::string userName, std::string passWord, const std::string&extraConfigPath):
			ip_(ip), port_(port), userName_(userName), passWord_(passWord), extraConfigPath_(extraConfigPath){};

		StreamRingBuffer<ES_Frame,char, UnreRectS>* streamBufferP;
		FrameExtraBuufer<unsigned char, UnreRectS>* frameBufferP;
		
		int tryConnectDev();
		int pushStream();
		int Stream2RGB();//should be private
		unsigned char* popFrame();

		static void StreamDataCallback_V2(int hSession, const char *frame, const char *stream, int size, void *pUser);
		void DoStreamDataCallback_V2(int hSession, const char* frame, const char* stream, int size, StreamRingBuffer<ES_Frame, char, UnreRectS>*&bufferP);
	private:
		std::string  ip_;
		int port_;
		std::string  userName_{""};
		std::string  passWord_{ "" };
		std::string  extraConfigPath_;
		int sesssionHandle_{-1};
		bool isDevicesInit{ false };
		bool isDevicesRunning{ false };
		////这是为push stream服务，push的数据：head body extraINFO是分开的，当push的时候会把他们memcpy到连续的空间
		ES_Frame*tempDataHead;
		////这是为push stream服务，push的数据：head body extraINFO是分开的，当push的时候会把他们memcpy到连续的空间
		UnreRectS*tempUnreRectS;
		////暂存解出的yuv一帧数据
		char*decodeYUV;
		////之前从buffer pop的数据并没有拷走，而是直接在原地计算，这可能出现问题，因此有了它，专门从streamBuffer拷走数据
		char*streamPopedData;
		////之前从buffer pop的数据并没有拷走，而是直接在原地计算，这可能出现问题，因此有了它，专门从frameBuffer拷走数据
		char*framePopedData;
		////原厂的解码函数需要int*传入这个yuv的长度*3/2
		int decode_length;
		////流解码出来的内容会copy到这个matYuv，然后转到下一行的rgbImg，
		////等于用opencv的转换函数会把数据多copy几回
		////TODO用别的转换函数例如gpu，
		////stream pop出老来的东西已经copy到decodeYUV，所以不用担心ringbuf
		cv::Mat matYuv;
		////仅仅用来接受yuv转换
		cv::Mat rgbImg;
		////仅仅用show Frame 的pop
		cv::Mat rgbShow;

	};

}



#endif

