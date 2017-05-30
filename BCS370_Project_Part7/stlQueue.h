#ifndef H_stlQueue
#define H_stlQueue

#include <iostream>
#include <string>
#include <queue>
#include "BCS370_queueBase.h"




namespace farmingdale {

	class stlQueue;
}


class::farmingdale::stlQueue {
public:

	stlQueue();

	stlQueue(const stlQueue& copyMe);



	statusCode enqueue(std::string addMe);
	statusCode dequeue(std::string &returnedElement);
	statusCode top(std::string &returnedElement) const;
	inline int isEmpty()const { return q3.empty(); }
private:
	std::queue<std::string> q3;

	inline int queueCapacity() const { return q3.size(); }




};

#endif

















