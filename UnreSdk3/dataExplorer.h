#ifndef _DATAEXPLORER_H_
#define _DATAEXPLORER_H_

#include<vector>
#include"ringBuffer.h"
#include"jsonExplorer.h"
#include"deviceExplorer.h"

#ifdef WIN32
//#include "afxwin.h"
#endif

namespace unre
{
	class DataExplorer
	{
	public:
		DataExplorer(DataExplorer&de) = delete;
		DataExplorer(DataExplorer&&de) = delete;
		explicit DataExplorer();
		int getExactStreamCnt();
		~DataExplorer() {};
		
		
		int getBuffer_fortest();
		const std::vector<FrameRingBuffer<unsigned char>*>&getBufferVecP();
	private:
		std::vector<FrameRingBuffer<unsigned char>*> bufferVecP;//this member wrap the ringbuffer,and the ring buffer never std::move
		std::vector<void*> constBuffer = { 0 };//the ringbuffer will copy to there
		JsonExplorer je;
		DeviceExplorer* dev_e;
		int exactStreamCnt = 0;
		bool isConnectted{ false };
	};
}

#endif // !_DATAEXPLORER_H_
