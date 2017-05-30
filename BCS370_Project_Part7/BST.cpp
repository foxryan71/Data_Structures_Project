#include "BST.h"


farmingdale::bst::bst()

{
	root = NULL;
}


farmingdale::bst::~bst() {


	destroy(root);

}

void farmingdale::bst::destroy(treeNode * &tN) {

	if (tN != NULL) {

		destroy(tN->leftChild);
		destroy(tN->rightChild);
		delete tN;
		tN = NULL;

	}

}

treeNode* farmingdale::bst::copyTree(treeNode * copyMeTreeRoot) {
	treeNode * nn;

	if (NULL == copyMeTreeRoot) {

		return 0;
	}
	else {


		try {
			nn = new treeNode;
		}
		catch (std::bad_alloc) {

			std::cerr << "Bad allocation \n";
		}
		nn = NULL;
		nn->info = copyMeTreeRoot->info;
		nn->num = copyMeTreeRoot->num;
		nn->leftChild = copyTree(copyMeTreeRoot->leftChild);
		nn->rightChild = copyTree(copyMeTreeRoot->rightChild);

		return nn;


	}
}


farmingdale::bst::bst(const bst &copy) {

	root = copyTree(copy.root);


}


bool farmingdale::bst::isEmpty() {


	if (NULL == root) {


		return true;

	}
	else {


		return false;
	}




}

farmingdale::statusCode farmingdale::bst::insert(std::string& addWord, int addNum) {

	treeNode * current = NULL;
	treeNode * newParent = NULL;
	treeNode * nn = NULL;

	try
	{
		nn = new treeNode;
	}
	catch (std::bad_alloc)
	{
		return FAILURE;
	}

	nn->info = addWord;
	nn->num = addNum;
	nn->leftChild = NULL;
	nn->rightChild = NULL;
	if (NULL == root)
	{
		// If root is null set root to the new node means the list is empty.
		root = nn;
		return SUCCESS;
	}
	else {
		current = root;
		while (current != NULL)
		{

			newParent = current;
			if (current->info == addWord) {
				delete nn;
				nn = NULL;
				newParent = NULL;
				current = NULL;

				return FAILURE;
			}

			if (current->info < addWord) {
				current = current->rightChild;

			}
			else {

				current = current->leftChild;
			}


		}//end while

		if (newParent->info < addWord)
		{
			newParent->rightChild = nn;

		}
		//else info is greater then add word so must go to left child.
		else
		{
			newParent->leftChild = nn;

		}

		return SUCCESS;

	}//end else




}

bool farmingdale::bst::search(std::string &word) {

	treeNode * current = root;

	while (current != NULL) {

		if (current->info == word) {

			return true;
		}
		if (current->info < word) {

			current = current->rightChild;
		}
		else {

			current = current->leftChild;
		}

	}// end while

	return false;
}

farmingdale::statusCode farmingdale::bst::removeFromTree(treeNode * &p) {

	treeNode * current;
	treeNode * trailCurrent;
	treeNode * temp;

	if (NULL == p) {

		return FAILURE;
	}


	// this says this only has one thing in the tree which is root
	else if (p->leftChild == NULL && p->rightChild == NULL) {

		temp = p;
		delete temp;
		temp = NULL;
		p = NULL;

	}

	// if treeNode left child is null set p to rightChild
	else if (p->leftChild == NULL) {
		temp = p;
		p = temp->rightChild;
		delete temp;
		temp = NULL;

	}
	else if (p->rightChild == NULL) {
		temp = p;
		p = temp->leftChild;
		delete temp;
		temp = NULL;


	}
	else {

		current = p->leftChild;
		trailCurrent = NULL;

		while (current->rightChild != NULL) {
			trailCurrent = current;
			current = current->rightChild;
		}//end while

		 //copies data from current  which will be deleted
		p->info = current->info;
		p->num = current->num;
		//connects
		if (NULL == trailCurrent) {
			p->leftChild = current->leftChild;

		}
		else {
			trailCurrent->rightChild = current->leftChild;

		}

		delete current;


	}//end else


	current = NULL;

	temp = NULL;

	return SUCCESS;
}//end deleteFromTree


farmingdale::statusCode farmingdale::bst::deleteNode(const std::string & deleteMe) {

	treeNode * current;
	treeNode * trailCurrent;
	bool found = false;
	if (NULL == root)
	{

		return FAILURE;

	}
	else {

		current = root;
		trailCurrent = root;

		while (current != NULL && !found) {

			if (current->info == deleteMe) {

				found = true;

			}



			else {
				trailCurrent = current;
				if (current->info < deleteMe)
				{
					current = current->rightChild;
				}
				else
				{

					current = current->leftChild;

				}
			}

		}//end while

		if (current == NULL) {
			trailCurrent = NULL;
			return FAILURE;
		}
		else if (found) {
			if (current == root) {
				if (removeFromTree(root) == SUCCESS) {
					current = NULL;
					trailCurrent = NULL;
					return SUCCESS;
				}//end if
			}//end if for root
			else if (trailCurrent->info > deleteMe) {
				if (removeFromTree(trailCurrent->leftChild) == SUCCESS) {
					current = NULL;
					trailCurrent = NULL;
					return SUCCESS;
				}//end if
			}//end else if
			else if (removeFromTree(trailCurrent->rightChild) == SUCCESS) {
				current = NULL;
				trailCurrent = NULL;
				return SUCCESS;
			}

			else {
				current = NULL;
				trailCurrent = NULL;
				return FAILURE;
			}

		}//end else

	}

	;
}// end removeNode


farmingdale::statusCode farmingdale::bst::enqueue(std::string& word, int num)
{

	if (insert(word, num) == SUCCESS) {
		count++;

		return SUCCESS;

	}
	else {

		return FAILURE;
	}







}// end of enqueue





farmingdale::statusCode farmingdale::bst::top(std::string &word) {



	if (search(word) == true) {

		return SUCCESS;
	}
	else {

		return FAILURE;
	}


}

farmingdale::statusCode farmingdale::bst::dequeue(std::string &deleteMe) {

	if (deleteNode(deleteMe) == SUCCESS) {
		return SUCCESS;
	}
	else
	{
		return FAILURE;

	}


}

