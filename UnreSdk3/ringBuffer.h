#ifndef _RINGBUFFER_H_
#define _RINGBUFFER_H_
#include < atomic >
#include < mutex >
#include <string>
#include <tuple>



class spinlock
{
	std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
	void lock() noexcept
	{
		while (flag.test_and_set(std::memory_order_acquire))
			;
	}
	void unlock() noexcept
	{
		flag.clear(std::memory_order_release);
	}
	bool try_lock() noexcept
	{
		return !flag.test_and_set(std::memory_order_acquire);
	}
};

#define MAX_QUEUE_SIZE (20)

namespace unre
{
	template < typename T >
	class FrameRingBuffer
	{
	public:
		typedef T Value_type;
		int height_;
		int width_;
		float channels_;
		int frameEleCnt_;

		explicit FrameRingBuffer(const int& height, const int& width, const float& channels);

		FrameRingBuffer(const FrameRingBuffer &other);
		FrameRingBuffer& operator=(const FrameRingBuffer &) = delete;

		~FrameRingBuffer();

		// pushes an item to FrameRingBuffer tail
		void push(const T*itemPtr);

		// pops an item from FrameRingBuffer head
		T* pop();

		// try to push an item to FrameRingBuffer tail
		bool try_and_push(const T* itemPtr);

		// try to pop and item from FrameRingBuffer head
		T* try_and_pop();

		bool full();
		bool empty();
		unsigned capacity() { return CAPACITY; }
		unsigned count();

	protected:
		spinlock lock_;
		const unsigned CAPACITY;  // FrameRingBuffer capacity
		T *data_;                  // array to store the items
		unsigned cnt_;             // FrameRingBuffer count
		unsigned head_;            // also the readIndex
		unsigned tail_;            // also the writeIndex
	};


	template < typename T >
	FrameRingBuffer< T >::FrameRingBuffer(const int& height, const int& width, const float& channels) :
		CAPACITY(MAX_QUEUE_SIZE), height_(height), width_(width), channels_(channels), cnt_(0), head_(0), tail_(0)
	{
		frameEleCnt_ = height_ * width_*channels_;
		data_ = new T[frameEleCnt_*CAPACITY];
	}

	template < typename T >
	FrameRingBuffer< T >::FrameRingBuffer(const FrameRingBuffer &other)
	{
		std::lock_guard< spinlock > lg(lock_);
		CAPACITY = other.CAPACITY;
		cnt_ = other.cnt_;
		head_ = other.head_;
		tail_ = other.tail_;
		height_ = other.height_;
		width_ = other.width_;
		channels_ = other.channels_;
		frameEleCnt_ = other.frameEleCnt_;
		data_ = new T[frameEleCnt_*CAPACITY];
		memcpy(data_, other.data_, height_*width_*channels_*CAPACITY * sizeof(T));
	}

	template < typename T >
	FrameRingBuffer< T >::~FrameRingBuffer()
	{
		//LOG(INFO) << "FrameRingBuffer DESTROYED";
		delete[] data_;
	}

	template < typename T >
	void FrameRingBuffer< T >::push(const T*itemPtr)
	{
		while (!try_and_push(itemPtr))
			;
	}

	template < typename T >
	T* FrameRingBuffer< T >::pop()
	{
		thread_local T* ptr;
		while ((ptr = try_and_pop()) == nullptr)
			;
		return ptr;
	}

	template < typename T >
	bool FrameRingBuffer< T >::try_and_push(const T *itemPtr)
	{
		std::lock_guard< spinlock > lg(lock_);
		if (cnt_ == CAPACITY)
			return false;    // full
		++cnt_;
		memcpy(data_ + frameEleCnt_ * tail_, itemPtr, frameEleCnt_ * sizeof(T));
		tail_++;
		if (tail_ == CAPACITY)
			tail_ -= CAPACITY;
		return true;
	}

	template < typename T >
	T* FrameRingBuffer< T >::try_and_pop()
	{
		std::lock_guard< spinlock > lg(lock_);
		if (cnt_ == 0)
			return nullptr;    // empty
		--cnt_;
		unsigned idx = head_;
		++head_;
		if (head_ == CAPACITY)
			head_ -= CAPACITY;
		return data_ + frameEleCnt_ * idx;
	}

	template < typename T >
	bool FrameRingBuffer< T >::full()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_ == CAPACITY;
	}

	template < typename T >
	bool FrameRingBuffer< T >::empty()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_ == 0;
	}

	template < typename T >
	unsigned FrameRingBuffer< T >::count()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_;
	}




	template < typename HeadType, typename DataType, typename ExtraInfoType>
	class StreamRingBuffer
	{
	public:
		int height_;
		int width_;
		float channels_;
		int frameEleCnt_;
		int dataBodyLegth_;

		explicit StreamRingBuffer(const int& height, const int& width, const float& channels);

		StreamRingBuffer(const StreamRingBuffer &other);
		StreamRingBuffer& operator=(const StreamRingBuffer &) = delete;

		~StreamRingBuffer();
		void push(const HeadType*dataHead, const DataType*dataBody, const ExtraInfoType*extraInfo, const int&dataBodySize);
		std::tuple<HeadType*, DataType*, ExtraInfoType*> pop();
		int popAndCopy(DataType*initializedMen);
		bool try_and_push(const HeadType*dataHead, const DataType*dataBody, const ExtraInfoType*extraInfo, const int&dataBodySize);
		std::tuple<HeadType*, DataType*, ExtraInfoType*> try_and_pop();
		int try_and_popAndCopy(DataType*initializedMen);

		bool full();
		bool empty();
		unsigned capacity() { return CAPACITY; }
		unsigned count();

	protected:
		spinlock lock_;
		const unsigned CAPACITY;  // FrameRingBuffer capacity
		DataType *data_;                  // 必须是char
		unsigned cnt_;             // FrameRingBuffer count
		unsigned head_;            // also the readIndex
		unsigned tail_;            // also the writeIndex
	};


	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	StreamRingBuffer< HeadType, DataType, ExtraInfoType >::StreamRingBuffer(const int& height, const int& width, const float& channels) :
		CAPACITY(MAX_QUEUE_SIZE), height_(height), width_(width), channels_(channels), cnt_(0), head_(0), tail_(0)
	{
		dataBodyLegth_ = height * width * channels;
		frameEleCnt_ = sizeof(HeadType) + sizeof(DataType)*dataBodyLegth_ + sizeof(ExtraInfoType);
		data_ = new DataType[frameEleCnt_*CAPACITY];
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	StreamRingBuffer< HeadType, DataType, ExtraInfoType >::StreamRingBuffer(const StreamRingBuffer &other)
	{
		std::lock_guard< spinlock > lg(lock_);
		CAPACITY = other.CAPACITY;
		cnt_ = other.cnt_;
		head_ = other.head_;
		tail_ = other.tail_;
		height_ = other.height_;
		width_ = other.width_;
		channels_ = other.channels_;
		frameEleCnt_ = other.frameEleCnt_;
		dataBodyLegth_ = other.dataBodyLegth_;
		data_ = new DataType[frameEleCnt_*CAPACITY];;
		memcpy(data_, other.data_, frameEleCnt_*CAPACITY);
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	StreamRingBuffer< HeadType, DataType, ExtraInfoType >::~StreamRingBuffer()
	{
		//LOG(INFO) << "FrameRingBuffer DESTROYED";
		delete[] data_;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	void StreamRingBuffer< HeadType, DataType, ExtraInfoType >::
		push(const HeadType*dataHead, const DataType*dataBody, const ExtraInfoType*extraInfo, const int&currenStreamSize)
	{
		while (!try_and_push(dataHead, dataBody, extraInfo, currenStreamSize))
			;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	std::tuple<HeadType*, DataType*, ExtraInfoType*> StreamRingBuffer< HeadType, DataType, ExtraInfoType >::pop()
	{
		thread_local std::tuple<HeadType*, DataType*, ExtraInfoType*> ret;		
		while (1)
		{
			ret = try_and_pop();
			if (std::get<0>(ret) != (HeadType*)0)
			{
				break;
			}
		}
		return ret;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	int StreamRingBuffer< HeadType, DataType, ExtraInfoType >::popAndCopy(DataType*initializedMem)
	{
		thread_local int ret;
		while (1)
		{
			ret = try_and_popAndCopy(initializedMem);
			if (ret == 0)
			{
				break;
			}
		}
		return ret;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	bool StreamRingBuffer< HeadType, DataType, ExtraInfoType >::
		try_and_push(const HeadType*dataHead, const DataType*dataBody, const ExtraInfoType*extraInfo, const int&currenStreamSize)
	{
		std::lock_guard< spinlock > lg(lock_);
		if (cnt_ == CAPACITY)
			return false;    // full
		++cnt_;
		memcpy(data_ + frameEleCnt_ * tail_, dataHead, sizeof(HeadType));
		memcpy(data_ + sizeof(HeadType) + frameEleCnt_ * tail_, dataBody, currenStreamSize);
		memcpy(data_ + sizeof(HeadType) + dataBodyLegth_ * sizeof(char) + frameEleCnt_ * tail_, extraInfo, sizeof(ExtraInfoType));
		tail_++;
		if (tail_ == CAPACITY)
			tail_ -= CAPACITY;
		return true;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	std::tuple<HeadType*, DataType*, ExtraInfoType*> StreamRingBuffer< HeadType, DataType, ExtraInfoType >::try_and_pop()
	{
		std::lock_guard< spinlock > lg(lock_);
		if (cnt_ == 0)
			return std::make_tuple((HeadType*)0, (DataType*)0, (ExtraInfoType*)0);    // empty
		--cnt_;
		unsigned idx = head_;
		++head_;
		if (head_ == CAPACITY)
			head_ -= CAPACITY;
		return std::make_tuple(
			(HeadType*)(data_ + frameEleCnt_ * idx),
			(DataType*)(data_ + sizeof(HeadType) + frameEleCnt_ * idx),
			(ExtraInfoType*)(data_ + sizeof(HeadType) + dataBodyLegth_ * sizeof(char) + frameEleCnt_ * idx)
		);
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	int StreamRingBuffer< HeadType, DataType, ExtraInfoType >::try_and_popAndCopy(DataType*initilizedMem)
	{
		std::lock_guard< spinlock > lg(lock_);
		if (cnt_ == 0)
			return -1;    // empty
		--cnt_;
		unsigned idx = head_;
		++head_;
		if (head_ == CAPACITY)
			head_ -= CAPACITY;
		memcpy(initilizedMem, data_ + frameEleCnt_ * idx, frameEleCnt_);
		return 0;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	bool StreamRingBuffer< HeadType, DataType, ExtraInfoType >::full()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_ == CAPACITY;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	bool StreamRingBuffer< HeadType, DataType, ExtraInfoType >::empty()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_ == 0;
	}

	template <  typename HeadType, typename DataType, typename ExtraInfoType >
	unsigned StreamRingBuffer< HeadType, DataType, ExtraInfoType >::count()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_;
	}


	template <typename DataType, typename ExtraInfoType>
	class FrameExtraBuufer
	{
	public:
		typedef DataType Value_type;//完全为了照顾uchar和char的转换
		int height_;
		int width_;
		float channels_;
		int frameEleCnt_;
		int dataBodyLegth_;

		explicit FrameExtraBuufer(const int& height, const int& width, const float& channels);

		FrameExtraBuufer(const FrameExtraBuufer &other);
		FrameExtraBuufer& operator=(const FrameExtraBuufer &) = delete;

		~FrameExtraBuufer();
		void push(const DataType*dataBody, const ExtraInfoType*extraInfo);
		int popAndCopy(DataType*initializedMen);
		bool try_and_push(const DataType*dataBody, const ExtraInfoType*extraInfo);
		int try_and_popAndCopy(DataType*initializedMen);

		bool full();
		bool empty();
		unsigned capacity() { return CAPACITY; }
		unsigned count();

	protected:
		spinlock lock_;
		const unsigned CAPACITY;  // FrameRingBuffer capacity
		DataType *data_;                  // 必须是char
		unsigned cnt_;             // FrameRingBuffer count
		unsigned head_;            // also the readIndex
		unsigned tail_;            // also the writeIndex
	};


	template <  typename DataType, typename ExtraInfoType >
	FrameExtraBuufer< DataType, ExtraInfoType >::FrameExtraBuufer(const int& height, const int& width, const float& channels) :
		CAPACITY(MAX_QUEUE_SIZE), height_(height), width_(width), channels_(channels), cnt_(0), head_(0), tail_(0)
	{
		dataBodyLegth_ = height * width * channels;
		frameEleCnt_ = sizeof(DataType)*dataBodyLegth_ + sizeof(ExtraInfoType);
		data_ = new DataType[frameEleCnt_*CAPACITY];
	}

	template <  typename DataType, typename ExtraInfoType >
	FrameExtraBuufer< DataType, ExtraInfoType >::FrameExtraBuufer(const FrameExtraBuufer &other)
	{
		std::lock_guard< spinlock > lg(lock_);
		CAPACITY = other.CAPACITY;
		cnt_ = other.cnt_;
		head_ = other.head_;
		tail_ = other.tail_;
		height_ = other.height_;
		width_ = other.width_;
		channels_ = other.channels_;
		frameEleCnt_ = other.frameEleCnt_;
		dataBodyLegth_ = other.dataBodyLegth_;
		data_ = new DataType[frameEleCnt_*CAPACITY];;
		memcpy(data_, other.data_, frameEleCnt_*CAPACITY);
	}

	template <  typename DataType, typename ExtraInfoType >
	FrameExtraBuufer< DataType, ExtraInfoType >::~FrameExtraBuufer()
	{
		//LOG(INFO) << "FrameRingBuffer DESTROYED";
		delete[] data_;
	}

	template <  typename DataType, typename ExtraInfoType >
	void FrameExtraBuufer< DataType, ExtraInfoType >::
		push(const DataType*dataBody, const ExtraInfoType*extraInfo)
	{
		while (!try_and_push(dataBody, extraInfo))
			;
	}

	template <  typename DataType, typename ExtraInfoType >
	int FrameExtraBuufer< DataType, ExtraInfoType >::popAndCopy(DataType*initializedMem)
	{
		thread_local int ret;
		while (1)
		{
			ret = try_and_popAndCopy(initializedMem);
			if (ret == 0)
			{
				break;
			}
		}
		return ret;
	}

	template <  typename DataType, typename ExtraInfoType >
	bool FrameExtraBuufer< DataType, ExtraInfoType >::
		try_and_push(const DataType*dataBody, const ExtraInfoType*extraInfo)
	{
		std::lock_guard< spinlock > lg(lock_);
		if (cnt_ == CAPACITY)
			return false;    // full
		++cnt_;
		memcpy(data_ + frameEleCnt_ * tail_, dataBody, dataBodyLegth_ * sizeof(char));
		memcpy(data_ + dataBodyLegth_ * sizeof(char) + frameEleCnt_ * tail_, extraInfo, sizeof(ExtraInfoType));
		tail_++;
		if (tail_ == CAPACITY)
			tail_ -= CAPACITY;
		return true;
	}


	template <  typename DataType, typename ExtraInfoType >
	int FrameExtraBuufer< DataType, ExtraInfoType >::try_and_popAndCopy(DataType*initilizedMem)
	{
		std::lock_guard< spinlock > lg(lock_);
		if (cnt_ == 0)
			return -1;    // empty
		--cnt_;
		unsigned idx = head_;
		++head_;
		if (head_ == CAPACITY)
			head_ -= CAPACITY;
		memcpy(initilizedMem, data_ + frameEleCnt_ * idx, frameEleCnt_);
		return 0;
	}

	template <  typename DataType, typename ExtraInfoType >
	bool FrameExtraBuufer< DataType, ExtraInfoType >::full()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_ == CAPACITY;
	}

	template <  typename DataType, typename ExtraInfoType >
	bool FrameExtraBuufer< DataType, ExtraInfoType >::empty()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_ == 0;
	}

	template <  typename DataType, typename ExtraInfoType >
	unsigned FrameExtraBuufer< DataType, ExtraInfoType >::count()
	{
		std::lock_guard< spinlock > lg(lock_);
		return cnt_;
	}



}
#endif