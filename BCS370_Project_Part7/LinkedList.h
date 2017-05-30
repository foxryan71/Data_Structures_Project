#ifndef H_BCS370_LinkedList
#define H_BCS370_LinkedList

#include <iostream>
#include <string>
#include "BCS370_queueBase.h"
#include <cassert>
#include <new>
namespace farmingdale {

	template<typename TYPE> class linkedList;

}


template<typename TYPE>
class::farmingdale::linkedList {

	struct node
	{
		TYPE info;
		node * link;
		node * backLink;
	};
private:

	int listLength;
	node * first;
	node * last;

public:

	linkedList();
	linkedList(const linkedList & copyMe);
	~linkedList();
	statusCode insert_back(TYPE); // aka insertLast
	statusCode insert_front(TYPE); // aka insertFirst
	statusCode remove_front(TYPE & returnedValue);
	statusCode remove_back(TYPE & returnedValue);
	bool contains(TYPE);
	statusCode remove(TYPE);
	TYPE front(TYPE &returnValue);
	TYPE back(TYPE &returnValue);
	void destroyList();
	int length() { return listLength; }
	statusCode enqueue(TYPE &addme);
	statusCode dequeue(TYPE &deleteMe);
	statusCode insert(TYPE &addMe);
	statusCode top(TYPE &returnValue);


	void print()const;

};



template<typename TYPE>
farmingdale::linkedList<TYPE>::linkedList()
	:
	first(NULL),
	last(NULL),
	listLength(0)
{

}
template<typename TYPE>
farmingdale::linkedList<TYPE>::linkedList(const linkedList &copyMe) {

	node * newNode;
	node * current;

	if (first != NULL) {

		destroyList();
	}
	if (copyMe.first == NULL) {

		first = NULL;
		last = NULL;
		listlength = 0;
	}
	else {
		current = copyMe.first;
		listLength = copyMe.listLength;

		first = new node;
		first->info = current->info;
		first->link = current->link;
		//first->backLink = current->backLink; dont need this because first->backLink should already be null.
		last = first;
		current = current->link;



		while (current != NULL) {
			newNode = new node;
			newNode->info = current->info;
			last->link = newNode;
			newNode->backLink = last;
			last = newNode;
			current = current->link;
			listLength++;

		}
	}
}
template<typename TYPE>
void farmingdale::linkedList<TYPE>::destroyList() {

	node *temp;

	while (first != NULL) {

		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	listLength = 0;


}
template<typename TYPE>
farmingdale::linkedList<TYPE>::~linkedList() {

	destroyList();
}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::insert_front(TYPE addMe) {


	node * newNode;

	try {
		newNode = new node;
	}
	catch (std::bad_alloc) {

		return FAILURE;
	}
	newNode->info = addMe;
	newNode->link = NULL;
	newNode->backLink = NULL;

	if (first == NULL) {

		first = newNode;
		last = newNode;
		listLength++;

	}
	else {
		newNode->link = first;
		first->backLink = newNode;
		first = newNode;
		listLength++;
	}



	return SUCCESS;

}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::insert_back(TYPE addMe) {

	node * newNode;

	try {
		newNode = new node;
	}
	catch (std::bad_alloc) {

		return FAILURE;
	}
	newNode->info = addMe;
	newNode->link = NULL;
	newNode->backLink = NULL;

	if (last == NULL) {
		newNode->backLink = NULL;
		first = newNode;
		last = newNode;
		listLength++;

	}
	else {
		newNode->backLink = last;
		last->link = newNode;
		last = newNode;
		listLength++;
	}



	return SUCCESS;
}

template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::remove_front(TYPE & removeMe) {

	node * delNode = first;

	if (first == NULL) {


		return FAILURE;
	}

	if (first->link != NULL) {

		first = delNode->link;
		first->backLink = NULL;
		removeMe = delNode->info;
		delete delNode;

	}
	else {

		last = NULL;
		first = NULL;
		removeMe = delNode->info;
		delete delNode;


	}

	listLength--;

	return SUCCESS;

}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::remove_back(TYPE & removeMe) {
	node * delNode = last;

	if (last == NULL) {


		return FAILURE;
	}

	if (last->backLink != NULL) {

		last = delNode->backLink;
		last->link = NULL;
		removeMe = delNode->info;
		delete delNode;
	}
	else {

		last = delNode->backLink;
		first = NULL;
		removeMe = delNode->info;
		delete delNode;
	}









	listLength--;

	return SUCCESS;
}
template<typename TYPE>
bool farmingdale::linkedList<TYPE>::contains(TYPE foundMe)
{

	node * current = first;
	int count = 0;
	while (0 != current)
	{

		if (current->info == foundMe)

			return true;

		current = current->link;


		++count;
	}

	return false;


}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::remove(TYPE removeMe) {

	node * current;
	node * trail;
	bool found;
	if (first == NULL) {
		return FAILURE;
	}
	else if (first->info == removeMe) {

		current = first;
		first = first->link;

		if (first != NULL) {
			first->backLink = NULL;
		}
		else {
			last = NULL;
		}
		listLength--;
		delete current;
		return SUCCESS;
	}
	else {
		current = first;
		found = false;

		while (current != NULL && !found) {
			if (current->info >= removeMe) {

				found = true;
			}
			else {
				current = current->link;
			}
		}

		if (current == NULL) {

			return FAILURE;
		}
		else if (current->info == removeMe) {

			trail = current->backLink;
			trail->link = current->link;

			if (current->link != NULL) {
				current->link->backLink = trail;
			}
			if (current == last) {
				last = trail;
			}
			listLength--;
			delete current;
			return SUCCESS;
		}

	}


}




template<typename TYPE>
TYPE farmingdale::linkedList<TYPE>::front(TYPE &returnValue) {


	if (first != NULL) {

		returnValue = first->info;
		return returnValue;

	}
	else {

		returnValue = "List is Empty!";
		return returnValue;
	}

}
template<typename TYPE>
TYPE farmingdale::linkedList<TYPE>::back(TYPE & returnValue) {

	node * newNode = last;


	if (newNode != NULL) {

		return last->info;

	}
	else {
		returnValue = "List is empty!";
		return returnValue;
	}

}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::enqueue(TYPE &addMe) {



	return insert_front(addMe);


}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::dequeue(TYPE &deleteMe) {


	return remove_back(deleteMe);
}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::top(TYPE &returnedValue) {

	if (last == NULL) {

		return FAILURE;
	}
	else {

		returnedValue = back(returnedValue);
		return SUCCESS;
	}

}
template <typename TYPE>
void farmingdale::linkedList<TYPE>::print() const {

	node *current;
	current = first;

	while (current != NULL) {

		std::cout << current->info << "\n";
		current = current->link;
	}

}
template<typename TYPE>
farmingdale::statusCode farmingdale::linkedList<TYPE>::insert(TYPE &addMe) {

	node * current;
	node * trail = NULL;
	node * newNode;
	bool found;
	newNode = new node;
	newNode->info = addMe;
	newNode->link = NULL;
	newNode->backLink = NULL;

	if (first == NULL) {
		first = newNode;
		last = newNode;
		listLength++;

	}
	else {
		found = false;
		current = first;

		while (current != NULL && !found)
		{
			if (current->info >= addMe)
			{
				found = true;
			}
			else
			{
				trail = current;
				current = current->link;
			}

		}

		if (current == first)
		{
			first->backLink = newNode;
			newNode->link = first;
			first = newNode;
			listLength++;
		}
		else
		{
			if (current != NULL)
			{
				trail->link = newNode;
				newNode->backLink = trail;
				newNode->link = current;
				current->backLink = newNode;
			}
			else
			{
				trail->link = newNode;
				newNode->backLink = trail;
				last = newNode;
			}
			listLength++;
		}
	}

	return SUCCESS;

}


































#endif

