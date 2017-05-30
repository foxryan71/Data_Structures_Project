#include "BCS370_queueBase.h"
#include<cassert>
using namespace std;
#pragma once
//ctor
farmingdale::queue::queue()
	:
	nextInsertIndex(0),
	oldestIndex(0),
	bufferSize(INITAL_QUEUE_SIZE)
{
	data = new string[bufferSize];
}

//copy ctor
farmingdale::queue::queue(const queue& copyMe)
	:
	oldestIndex(0),
	bufferSize(copyMe.bufferSize)


{
	data = new string[bufferSize];
	assert(queueCapacity() == copyMe.queueCapacity());
	int j = 0;

	// starts at oldest index, as long as i is not equal to the next insert index, advance to next position and copy.
	for (int i = copyMe.oldestIndex; i != copyMe.nextInsertIndex; i = copyMe.advanceIndex(i)) {
		data[j] = copyMe.data[i];
		j++;
	}
	nextInsertIndex = j;
}

//destructor
farmingdale::queue::~queue() {
	delete[] data;

}


farmingdale::statusCode farmingdale::queue::enqueue(string addMe) {

	// if is full we must allocate more memory
	if (isFull()) {
		// create temp pointer variable
		string *tempData;
		int currentBufferSize = bufferSize;

		try {
			// try to get more memory
			tempData = new string[bufferSize * 2];
		}
		catch (bad_alloc) {

			return FAILURE;
		}
		// copy data array to temp array

		// create counter
		int j = 0;

		for (int i = oldestIndex; (i % bufferSize) != nextInsertIndex; ++i) {

			tempData[j] = data[i % bufferSize];

			j++;
		}
		// set oldest back to 0
		oldestIndex = 0;

		//  example: if 16 is current buffersize the nextinsert would b element [15] 
		nextInsertIndex = bufferSize - 1;


		// delete old array

		delete[] data;

		// set new array, has more space and the old data still in it
		data = tempData;
		// double buffer size
		bufferSize *= 2;
		// says older buffersize and the new buffer size
		cerr << "\t Reallocating buffer-old size = " << currentBufferSize << ", new size =  " << bufferSize << " \n" << endl;
	}
	//inserts new data
	data[nextInsertIndex] = addMe;

	nextInsertIndex = advanceIndex(nextInsertIndex); // advance and roll over if end-of-array
	return SUCCESS;
}

farmingdale::statusCode farmingdale::queue::dequeue(string &returnedElement) {
	if (isEmpty()) {
		return FAILURE;
	}
	else {
		returnedElement = data[oldestIndex];

		oldestIndex = advanceIndex(oldestIndex);
		return SUCCESS;
	}

}

farmingdale::statusCode farmingdale::queue::top(string &returnedElement) const {
	if (isEmpty())
		return FAILURE;


	returnedElement = data[oldestIndex];

	return SUCCESS;


}



