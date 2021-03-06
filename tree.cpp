#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cstring>
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
struct Node * Tree::search(int value){
	if (this->Root->data.INT == value)
		return (this->Root);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(this->Root->left != NULL)
		left = this->search(value, this->Root->left);
	if(this->Root->right != NULL)
		right = this->search(value, this->Root->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
struct Node * Tree::search(float value){
	if (this->Root->data.FLOAT == value)
		return (this->Root);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(this->Root->left != NULL)
		left = this->search(value, this->Root->left);
	if(this->Root->right != NULL)
		right = this->search(value, this->Root->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
struct Node * Tree::search(char value){
	if (this->Root->data.CHAR == value)
		return (this->Root);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(this->Root->left != NULL)
		left = this->search(value, this->Root->left);
	if(this->Root->right != NULL)
		right = this->search(value, this->Root->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
struct Node * Tree::search(std::string value){
	if (this->Root->data.STRING == value)
		return (this->Root);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(this->Root->left != NULL)
		left = this->search(value, this->Root->left);
	if(this->Root->right != NULL)
		right = this->search(value, this->Root->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
struct Node * Tree::search(int value, struct Node * node){
	if (node->data.INT == value)
		return (node);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(node->left != NULL)
		left = this->search(value, node->left);
	if(node->right != NULL)
		right = this->search(value, node->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
struct Node * Tree::search(float value, struct Node * node){
	if (node->data.FLOAT == value)
		return (node);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(node->left != NULL)
		left = this->search(value, node->left);
	if(node->right != NULL)
		right = this->search(value, node->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
struct Node * Tree::search(char value, struct Node * node){
	if (node->data.CHAR == value)
		return (node);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(node->left != NULL)
		left = this->search(value, node->left);
	if(node->right != NULL)
		right = this->search(value, node->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
struct Node * Tree::search(std::string value, struct Node * node){
	if (node->data.STRING == value)
		return (node);
	struct Node * left = NULL;
	struct Node * right = NULL;
	if(node->left != NULL)
		left = this->search(value, node->left);
	if(node->right != NULL)
		right = this->search(value, node->right);
	if (left != NULL)
		return (left);
	else
		return (right);
}
Tree::~Tree(){
	if(Root->left != NULL)
		this->prune(Root->left);
	if(Root->right != NULL)
		this->prune(Root->right);
	delete(Root);
}
