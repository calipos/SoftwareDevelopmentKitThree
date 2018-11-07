#include "device.h"

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

int m_hDecoder = 0;

namespace unre
{

	int Device::pushStream()
	{
		int ret = -1;
		ret = ES_OpenChannel_V2(sesssionHandle_, ES_ST_HD, &Device::StreamDataCallback_V2, this);
		return ret;
	}
	unsigned char* Device::popFrame()
	{
		Stream2RGB();
		frameBufferP->popAndCopy((FrameExtraBuufer<unsigned char, UnreRectS>::Value_type*)framePopedData);
		memcpy(rgbShow.data, framePopedData, frameBufferP->dataBodyLegth_*sizeof(char));
		UnreRectS*extraInfo = (UnreRectS*)(framePopedData + frameBufferP->dataBodyLegth_ * sizeof(char));
		for (size_t i = 0; i < extraInfo->currentFaceNum; i++)
		{
			
			cv::Rect rect(extraInfo->UnreRect[i].x*0.192, extraInfo->UnreRect[i].y*0.108, extraInfo->UnreRect[i].w*0.192, extraInfo->UnreRect[i].h*0.108);
			cv::rectangle(rgbShow,rect,cv::Scalar(0,0,255),3);
			LOG(INFO) << rect.x << " " << rect.y << " " << rect.width << " " << rect.height;
		}
		cv::imshow("123", rgbShow);
		cv::waitKey(10);
		return 0;
	}
	int Device::Stream2RGB()
	{
		int ret = -1;

		auto reusltStruct = streamBufferP->popAndCopy(streamPopedData);
		if (m_hDecoder == 0)
		{
			m_hDecoder = ES_DECODER_Open(ES_DECODE_TYPE_YUV);
		}
		ES_DECODER_PushData(m_hDecoder, streamPopedData, ((ES_Frame*)streamPopedData)->size + sizeof(ES_Frame), decodeYUV, &decode_length);
		memcpy(matYuv.data, decodeYUV, ((ES_Frame*)streamPopedData)->height * 3 / 2 * ((ES_Frame*)streamPopedData)->width);
		cv::cvtColor(matYuv, rgbImg, CV_YUV2RGB_I420);
		frameBufferP->push(rgbImg.data, (UnreRectS*)(streamPopedData+ sizeof(ES_Frame)+ streamBufferP->dataBodyLegth_*sizeof(char)));

		//auto reusltStruct = streamBufferP->pop();
		//ES_Frame*headData = std::get<0>(reusltStruct);
		//char*bodyData = std::get<1>(reusltStruct);
		//UnreRectS*tailData = std::get<2>(reusltStruct);
		//if (m_hDecoder == 0)
		//{
		//	m_hDecoder = ES_DECODER_Open(ES_DECODE_TYPE_YUV);
		//}
		//ES_DECODER_PushData(m_hDecoder, (char*)headData, headData->size + sizeof(ES_Frame), decodeYUV, &decode_length);
		//memcpy(matYuv.data, decodeYUV, headData->height * 3 / 2 * headData->width);
		//cv::Mat rgbImg;
		//cv::cvtColor(matYuv, rgbImg, CV_YUV2RGB_I420);
		//frameBufferP->push(rgbImg.data);
			   
		//cv::imshow("123", rgbImg);
		//cv::waitKey(11);

		return ret;
	}

	void Device::StreamDataCallback_V2(int hSession, const char* frame, const char* stream, int size, void *pUser)
	{
		Device* pThis = (Device *)pUser;
		pThis->DoStreamDataCallback_V2(hSession, frame, stream, size, pThis->streamBufferP);
	}

	void Device::DoStreamDataCallback_V2(int hSession, const char* frame, const char* stream, int size, StreamRingBuffer<ES_Frame, char, UnreRectS>*&bufferP)
	{
		auto ma = ESong::JsonWrapper::ReadJson(frame);
		auto type = ESong::AnyCast<std::string>(ma["type"]);
		if (type == "audio"){}
		else if (type == "video")
		{
			tempDataHead->frame_type = AnyCast<int>(ma["frame_type"]);
			tempDataHead->width = AnyCast<int>(ma["width"]);
			tempDataHead->height = AnyCast<int>(ma["height"]);
			tempDataHead->fps_base = AnyCast<int>(ma["fps"]);
			tempDataHead->size = AnyCast<int>(ma["size"]);
			
			auto lst = AnyCast<std::list<Any>>(ma["rect"]);
			if (lst.size()==0)
			{
				tempUnreRectS->currentFaceNum = 0;
			}
			else
			{
				tempUnreRectS->currentFaceNum = 0;
				for (auto item : lst)
				{					
					auto val = AnyCast<std::map<std::string, Any>>(item);
					tempUnreRectS->UnreRect[tempUnreRectS->currentFaceNum].idx = -1;
					tempUnreRectS->UnreRect[tempUnreRectS->currentFaceNum].x = AnyCast<int>(val["x"]);
					tempUnreRectS->UnreRect[tempUnreRectS->currentFaceNum].y = AnyCast<int>(val["y"]);
					tempUnreRectS->UnreRect[tempUnreRectS->currentFaceNum].w = AnyCast<int>(val["w"]);
					tempUnreRectS->UnreRect[tempUnreRectS->currentFaceNum].h = AnyCast<int>(val["h"]);
					tempUnreRectS->currentFaceNum++;
				}
			}
			
			streamBufferP->push(tempDataHead, stream, tempUnreRectS, size);

			//char*tempMem = (char*)malloc(sizeof(ES_Frame)+ size);
			//memcpy(tempMem, tempDataHead, sizeof(ES_Frame));
			//memcpy(tempMem+ sizeof(ES_Frame), stream, size);
			//if (m_hDecoder == 0)			
			//	m_hDecoder = ES_DECODER_Open(ES_DECODE_TYPE_YUV);			
			//int nDest = tempDataHead->width * tempDataHead->height * 3 / 2;
			//std::unique_ptr<char[]> pDest(new char[nDest]);
			//ES_DECODER_PushData(m_hDecoder, tempMem, size + sizeof(ES_Frame), pDest.get(), &nDest);
			//cv::Mat matYuv = cv::Mat(tempDataHead->height * 3 / 2, tempDataHead->width, CV_8UC1, pDest.get());
			//cv::imshow("123", matYuv);
			//cv::waitKey(10);

			return;
		}
	}

	int Device::tryConnectDev()
	{	
		int zone = 8 * 60 * 60;//time zone
		int ret = -1;
		if (userName_.compare("") == 0 || userName_.compare("") == 0)
		{
			ret = ES_ConnectIP(ES_DEVICE_TYPE_K20, ip_.c_str(), (uint16_t)port_, zone, &sesssionHandle_);
		}
		else
		{
			//ES_ConnectPP ²»»á					
		}			
		std::this_thread::sleep_for(std::chrono::seconds(1));//for callback
		if (ret==0)
		{			
			int img_h = 1080;
			int img_w = 1920;
			streamBufferP = new StreamRingBuffer<ES_Frame, char, UnreRectS>(img_h, img_w,1.);
			frameBufferP = new FrameExtraBuufer<unsigned char, UnreRectS>(img_h, img_w, 3);
			tempDataHead = new ES_Frame;
			memset((void*)tempDataHead, 0 ,sizeof(ES_Frame));
			tempUnreRectS = new UnreRectS;
			decodeYUV = (char*)malloc(img_h * 3 / 2 * img_w * sizeof(char));
			streamPopedData = (char*)malloc(sizeof(ES_Frame)+sizeof(UnreRectS)+img_h * img_w * sizeof(char));
			framePopedData = (char*)malloc( sizeof(UnreRectS) + img_h * img_w * 3*sizeof(char));
			matYuv = cv::Mat::zeros(img_h * 3 / 2, img_w, CV_8UC1);
			int decode_length = img_w * img_h * 3 / 2;
			rgbShow = cv::Mat::zeros(img_h, img_w, CV_8UC3);
		}
		return 0;
	}


}