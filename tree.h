#include <iostream>
#include "Data.h"
#include "Node.h"
#ifndef TREE_H
#define TREE_H
	class Tree{
	public:
		Tree();
		struct Node * getLeft(struct Node * node);
		struct Node * getRight(struct Node * node);
		struct Node * getParent(struct Node * node);
		bool isRoot(struct Node * node);
		struct Data getValue(struct Node * node);
		~Tree();
	private:
		Node * Root;
	protected:
	};
#endif
