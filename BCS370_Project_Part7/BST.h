#ifndef H_BCS370_BST
#define H_BCS370_BST
#include "LinkedList.h"
#include <string>
#include <map>
#include <iterator>
namespace farmingdale {

	class bst;
}
struct treeNode
{
	std::string info;
	int num;
	treeNode * leftChild;
	treeNode *	rightChild;


};
class farmingdale::bst {

private:
	treeNode * root;
	int count = 0;

public:
	bst();
	~bst();
	bst(const bst&);
	bool isEmpty();
	statusCode insert(std::string&, int);
	bool search(std::string&);
	statusCode removeFromTree(treeNode * &p);
	void destroy(treeNode * &tN);
	treeNode* copyTree(treeNode * copyMeTreeRoot);
	statusCode deleteNode(const std::string & deleteMe);
	statusCode enqueue(std::string&, int);
	statusCode dequeue(std::string&);
	statusCode top(std::string&);
	int getCount() { return count; }



};
#endif