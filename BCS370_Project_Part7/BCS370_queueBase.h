#ifndef H_BCS370_QUEUEBASE
#define H_BCS370_QUEUEBASE
#include <new>
#include "randomStream.h"
#include <queue>



namespace farmingdale {

	enum statusCode { SUCCESS, FAILURE };
	class queue;




}

class farmingdale::queue {

private:
	static const int INITAL_QUEUE_SIZE = 16;
	std::string *data;
	int oldestIndex; //index of the oldest element in the queue
	int bufferSize;
	int nextInsertIndex; // next spot empty in queue

	inline int queueCapacity() const { return bufferSize; } // returnts the current capicty
	inline int advanceIndex(int index) const { return((index + 1) % queueCapacity()); } // gives address of the next index


public:
	queue();

	~queue();
	queue(const queue& copyMe);

	//returns the min size without reallocation of memory. used for testing
	inline int minQueueSize() { return queueCapacity() - 1; }
	inline bool isEmpty() const { return(oldestIndex == nextInsertIndex); }
	inline bool isFull() { return(advanceIndex(nextInsertIndex) == oldestIndex); }
	statusCode enqueue(std::string addMe);
	statusCode dequeue(std::string &returnedElement);
	statusCode top(std::string &returnedElement) const;

};

#endif // H_BCS370_QUEUEBASE#pragma once
