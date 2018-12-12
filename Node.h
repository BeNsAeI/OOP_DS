#include "Data.h"
#ifndef NODE_H
#define NODE_H

	struct Node{
		struct Data data;
		int index;
		unsigned int id;
		struct Node * next;
		struct Node * previous;
		struct Node * left;
		struct Node * right;
		struct Node * parent;
	};
	struct Sentinal{
		struct Node * next;
		struct Node * previous;
	};
#endif
