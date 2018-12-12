#include <string.h>
#include <string>
#include <cstring>
#include "Data.h"
#include "Node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
	class LinkedList{
	public:
		LinkedList();
		void pushQueue(struct Node * node);
		void popQueue(struct Node * node);
		void pushStack(struct Node * node);
		void popStack(struct Node * node);
		void addAfter(struct Node * current, struct Node * newNode);
		void addBefore(struct Node * current, struct Node * newNode);
		void remove(struct Node * node);
		struct Node * search(int value);
		struct Node * search(float value);
		struct Node * search(char value);
		struct Node * search(std::string value);
		~LinkedList();
		struct Node * frontSentinal;
		struct Node * backSentinal;
	private:
	protected:
	};
#endif
