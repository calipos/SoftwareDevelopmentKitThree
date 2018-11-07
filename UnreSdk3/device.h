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
		////����Ϊpush stream����push�����ݣ�head body extraINFO�Ƿֿ��ģ���push��ʱ��������memcpy�������Ŀռ�
		ES_Frame*tempDataHead;
		////����Ϊpush stream����push�����ݣ�head body extraINFO�Ƿֿ��ģ���push��ʱ��������memcpy�������Ŀռ�
		UnreRectS*tempUnreRectS;
		////�ݴ�����yuvһ֡����
		char*decodeYUV;
		////֮ǰ��buffer pop�����ݲ�û�п��ߣ�����ֱ����ԭ�ؼ��㣬����ܳ������⣬�����������ר�Ŵ�streamBuffer��������
		char*streamPopedData;
		////֮ǰ��buffer pop�����ݲ�û�п��ߣ�����ֱ����ԭ�ؼ��㣬����ܳ������⣬�����������ר�Ŵ�frameBuffer��������
		char*framePopedData;
		////ԭ���Ľ��뺯����Ҫint*�������yuv�ĳ���*3/2
		int decode_length;
		////��������������ݻ�copy�����matYuv��Ȼ��ת����һ�е�rgbImg��
		////������opencv��ת������������ݶ�copy����
		////TODO�ñ��ת����������gpu��
		////stream pop�������Ķ����Ѿ�copy��decodeYUV�����Բ��õ���ringbuf
		cv::Mat matYuv;
		////������������yuvת��
		cv::Mat rgbImg;
		////������show Frame ��pop
		cv::Mat rgbShow;

	};

}



#endif

