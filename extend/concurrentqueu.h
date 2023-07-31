#ifndef __CONCURRENT_QUEUE_H__
#define __CONCURRENT_QUEUE_H__
#include <iostream>
#include <memory>
#include <utility>
#include "../concurrentqueue.h"

template<typename T>
class ConcurrentQueue : public moodycamel::ConcurrentQueue<T>
{
public:
	ConcurrentQueue() {}
	virtual ~ConcurrentQueue()
	{
	}

	bool push( T& object)
	{
		this->enqueue(object);
		return true;
	}

	bool try_pop(T& object)
	{
		return this->try_dequeue(object);
	}
};

#endif // __CONCURRENT_QUEUE_H__
