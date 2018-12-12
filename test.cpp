#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "tree.h"
#include "linkedList.h"
int main( int argc, char** argv)
{
	printf(ANSI_COLOR_BLUE "initiating tests...\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "Tree Structure:\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_BLUE "Making a Tree...\n" ANSI_COLOR_RESET);
	Tree * myTree = new Tree();
	printf(ANSI_COLOR_BLUE "Adding a left branch...\n" ANSI_COLOR_RESET);
	struct Node * newNode = new struct Node;
	newNode->data.INT = 15;
	std::cout << myTree->Root->data.INT << std::endl;
	myTree->setLeft(myTree->Root, newNode);
	printf(ANSI_COLOR_BLUE "Testing left branch...\n" ANSI_COLOR_RESET);
	std::cout << myTree->Root->left->data.INT << std::endl;
	printf(ANSI_COLOR_BLUE "checking if the leaf is a root node...\n" ANSI_COLOR_RESET);
	std::cout << bool(myTree->isRoot(myTree->Root->left)) << std::endl;
	printf(ANSI_COLOR_BLUE "Testing search function...\n" ANSI_COLOR_RESET);
	std::cout << "Pass 1: Target: "<< myTree->Root << std::endl;
	std::cout << "Pass 1: search returned: "<< myTree->search(int(0)) << std::endl;
	std::cout << "Pass 2: Target: "<< myTree->Root->left << std::endl;
	std::cout << "Pass 2: search returned: "<< myTree->search(int(15)) << std::endl;
	std::cout << "searching a non existing value: "<< myTree->search(int(1)) << std::endl;
	printf(ANSI_COLOR_BLUE "Attempting to prune root (shouldn't be possible)...\n" ANSI_COLOR_RESET);
	myTree->prune(myTree->Root);
	printf(ANSI_COLOR_BLUE "Attempting to prune left branch...\n" ANSI_COLOR_RESET);
	std::cout << "Left branch pointer value before prune: " << (myTree->Root->left) << std::endl;
	myTree->prune(myTree->Root->left);
	std::cout << "Left branch pointer value after prune: " << (myTree->Root->left) << std::endl;
	printf(ANSI_COLOR_BLUE "Cleaning up...\n" ANSI_COLOR_RESET);
	delete(myTree);
	printf(ANSI_COLOR_GREEN "Done!\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "___\n\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "Linked list Structure:\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_BLUE "Making a list...\n" ANSI_COLOR_RESET);
	LinkedList * myList = new LinkedList();
	printf(ANSI_COLOR_BLUE "Generating 5 test nodes...\n" ANSI_COLOR_RESET);
	struct Node * tmp0 = new Node;
	tmp0->data.INT = 0;
	struct Node * tmp1 = new Node;
	tmp1->data.INT = 1;
	struct Node * tmp2 = new Node;
	tmp2->data.INT = 15;
	struct Node * tmp3 = new Node;
	struct Node * tmp4 = new Node;
	struct Node * tmp5 = new Node;
	printf(ANSI_COLOR_BLUE "Testing push(tmp1)...\n" ANSI_COLOR_RESET);
	myList->push(tmp1);
	std::cout << "Top of the linked list is: " << myList->Top() << " (should be: " << tmp1 << ")" << std::endl;
	printf(ANSI_COLOR_BLUE "Adding tmp0 before tmp1...\n" ANSI_COLOR_RESET);
	myList->addBefore(myList->Top(),tmp0);
	std::cout << "Top of the linked list is: " << myList->Top() << " (should be: " << tmp0 << ")" << std::endl;
	printf(ANSI_COLOR_BLUE "Adding tmp2, tmp3, tmp4 and tmp5 after tmp1...\n" ANSI_COLOR_RESET);
	myList->addAfter(myList->Tail(),tmp2);
	myList->addAfter(myList->Tail(),tmp3);
	myList->addAfter(myList->Tail(),tmp4);
	myList->addAfter(myList->Tail(),tmp5);
	printf(ANSI_COLOR_BLUE "Poping stack...\n" ANSI_COLOR_RESET);
	myList->popStack();
	std::cout << "Top of the linked list is: " << myList->Top() << " (should be: " << tmp1 << ")" << std::endl;
	printf(ANSI_COLOR_BLUE "Poping Queue...\n" ANSI_COLOR_RESET);
	myList->popQueue();
	std::cout << "Tail of the linked list is: " << myList->Tail() << " (should be: " << tmp4 << ")" << std::endl;
	printf(ANSI_COLOR_BLUE "Searching a value...\n" ANSI_COLOR_RESET);
	struct Node * found = myList->search(int(15));
	std::cout << "Search returned: " << found << " should be: " << tmp2 << std::endl;
	printf(ANSI_COLOR_BLUE "Deleting tmp1...\n" ANSI_COLOR_RESET);
	myList->remove(tmp1);
	std::cout << "Top returned: " << myList->Top() << " should be: " << tmp2 << std::endl;
	printf(ANSI_COLOR_BLUE "Attempting to delete the front and back sentinel...\n" ANSI_COLOR_RESET);
	myList->remove(tmp2->previous);
	myList->remove(tmp4->next);
	printf(ANSI_COLOR_BLUE "Empty out the list...\n" ANSI_COLOR_RESET);
	myList->popStack();
	myList->popStack();
	myList->popStack();
	printf(ANSI_COLOR_BLUE "PopStack after List is empty...\n" ANSI_COLOR_RESET);
	myList->popStack();
	printf(ANSI_COLOR_BLUE "PopQueue after List is empty...\n" ANSI_COLOR_RESET);
	myList->popQueue();
	printf(ANSI_COLOR_BLUE "Cleaning up...\n" ANSI_COLOR_RESET);
	delete(myList);
	printf(ANSI_COLOR_GREEN "Done!\n" ANSI_COLOR_RESET);
	return 0;
}
