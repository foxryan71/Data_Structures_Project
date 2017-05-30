#ifndef H_testStack
#define H_testStack

#include "randomStream.h"
#include"BCS370_queueBase.h"
#include "stlQueue.h"
#include "LinkedList.h"
#include "BST.h"

using namespace farmingdale;
using farmingdale::SUCCESS;
using farmingdale::FAILURE;

class testStack {

private:
	randomStream f1;







public:
	void randomStream();
	int testStream(std::ifstream& fileName);
	testStack();
	statusCode enqueue(std::string&, int, std::map<std::string, int>&);
	statusCode dequeue(std::string&, std::map<std::string, int>&);
	statusCode search(std::string&, std::map<std::string, int>&);


};
#endif#pragma once
