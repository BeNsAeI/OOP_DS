#include <iostream>
#include "Data.h"
#include "Node.h"
#include "tree.h"
Tree::Tree(){
	
}
struct Node * Tree::getLeft(struct Node * node){
	return (node->left);
}
struct Node * Tree::getRight(struct Node * node){
	return (node->right);
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
Tree::~Tree(){
	
}
