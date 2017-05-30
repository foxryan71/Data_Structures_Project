#include<new>
#include "stlQueue.h"
#include <cassert>
#pragma once
using namespace std;


farmingdale::stlQueue::stlQueue() {
	//	queue<string> q3;
}


farmingdale::stlQueue::stlQueue(const stlQueue& copyMe)
	: q3(copyMe.q3)
{
}



farmingdale::statusCode farmingdale::stlQueue::enqueue(string addMe) {
	try {
		q3.push(addMe);
	}
	catch (...) {
		return FAILURE;
	}
	return SUCCESS;
}

farmingdale::statusCode farmingdale::stlQueue::dequeue(string &returnedElement) {

	if (q3.empty())
		return FAILURE;


	returnedElement = q3.front();

	q3.pop();


	return SUCCESS;


}

farmingdale::statusCode farmingdale::stlQueue::top(string &returnedElement) const {

	if (q3.empty())
		return FAILURE;


	returnedElement = q3.front();




	return SUCCESS;


}