#ifndef __CONCURRENT_QUEUE_H__
#define __CONCURRENT_QUEUE_H__
#include "../concurrentqueue.h"

template<typename T>
class ConcurrentQueue : public moodycamel::ConcurrentQueue<T>
{
public:
	ConcurrentQueue() {}
	virtual ~ConcurrentQueue()
	{
	}

	bool push(const T&& object)
	{
		this->enqueue(std::forward<T>(object));
		return true;
	}

	bool try_pop(T& object)
	{
		return this->try_dequeue(object);
	}
};

#endif // __CONCURRENT_QUEUE_H__
