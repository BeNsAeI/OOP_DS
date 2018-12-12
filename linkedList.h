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
		void push(struct Node * node);
		void popQueue();
		void popStack();
		void addAfter(struct Node * current, struct Node * newNode);
		void addBefore(struct Node * current, struct Node * newNode);
		void remove(struct Node * node);
		struct Node * Top();
		struct Node * Tail();
		struct Node * search(int value);
		struct Node * search(float value);
		struct Node * search(char value);
		struct Node * search(std::string value);
		~LinkedList();
		struct Sentinal * frontSentinal;
		struct Sentinal * backSentinal;
	private:
	protected:
	};
#endif
