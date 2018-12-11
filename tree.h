#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include "Data.h"
#include "Node.h"
#ifndef TREE_H
#define TREE_H
	class Tree{
	public:
		Tree();
		struct Node * getLeft(struct Node * node);
		void setLeft(struct Node * parent, struct Node * child);
		struct Node * getRight(struct Node * node);
		void setRight(struct Node * parent, struct Node * child);
		struct Node * getParent(struct Node * node);
		bool isRoot(struct Node * node);
		struct Data getValue(struct Node * node);
		void prune(struct Node * index);
		struct Node * search(int value);
		struct Node * search(float value);
		struct Node * search(char value);
		struct Node * search(std::string value);
		struct Node * search(int value, struct Node * node);
		struct Node * search(float value, struct Node * node);
		struct Node * search(char value, struct Node * node);
		struct Node * search(std::string value, struct Node * node);
		~Tree();
		struct Node * Root;
	private:
	protected:
	};
#endif
