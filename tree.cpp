#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "Data.h"
#include "Node.h"
#include "tree.h"
Tree::Tree(){
	Root = new struct Node;
	Root->data.INT = 0;
	Root->data.FLOAT = 0;
	Root->data.CHAR = 0;
	Root->data.STRING = "";
	Root->id = 0;
	Root->next = NULL;
	Root->previous = NULL;
	Root->left = NULL;
	Root->right = NULL;
	Root->parent=NULL;
}

struct Node * Tree::getLeft(struct Node * node){
	return (node->left);
}
struct Node * Tree::getRight(struct Node * node){
	return (node->right);
}
void Tree::setLeft(struct Node * parent, struct Node * child){
	parent->left = child;
	child->parent = parent;
}
void Tree::setRight(struct Node * parent, struct Node * child){
	parent->right = child;
	child->parent = parent;
}
struct Node * Tree::getParent(struct Node * node){
	return (node->parent);
}
bool Tree::isRoot(struct Node * node){
	return (node->parent==NULL);
}
struct Data Tree::getValue(struct Node * node){
	return (node->data);
}
void Tree::prune(struct Node * index){
	if (index->parent == NULL)
		printf(ANSI_COLOR_RED "Cannot prune root!\n" ANSI_COLOR_RESET);
	else{
		if (index->left != NULL){
			this->prune(index->left);
		}
		if (index->right != NULL){
			this->prune(index->right);
		}
		if (index->parent->left == index){
			index->parent->left = NULL;
		}else{
			index->parent->right = NULL;
		}
		delete(index);
	}
}
Tree::~Tree(){
	delete(Root);
}
