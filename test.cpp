#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "tree.h"
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
	printf(ANSI_COLOR_BLUE "Attempting to prune root...\n" ANSI_COLOR_RESET);
	myTree->prune(myTree->Root);
	printf(ANSI_COLOR_BLUE "Attempting to prune left branch (shouldn't be possible)...\n" ANSI_COLOR_RESET);
	std::cout << "Left branch pointer value before prune: " << (myTree->Root->left) << std::endl;
	myTree->prune(myTree->Root->left);
	std::cout << "Left branch pointer value after prune: " << (myTree->Root->left) << std::endl;
	printf(ANSI_COLOR_BLUE "Cleaning up...\n" ANSI_COLOR_RESET);
	delete(myTree);
	printf(ANSI_COLOR_GREEN "Done!\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "___\n\n" ANSI_COLOR_RESET);
	return 0;
}
