#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include "color.h"
#include "Data.h"
#include "Node.h"
#include "linkedList.h"

LinkedList::LinkedList(){
	frontSentinal = new Sentinal;
	backSentinal = new Sentinal;
	frontSentinal->next = backSentinal;
	frontSentinal->previous = NULL;
	backSentinal->previous = frontSentinal;
	backSentinal->next = NULL;
}
void LinkedList::push(struct Node * node){
	node->next = frontSentinal->next;
	node->previous = frontSentinal;
	node->next->previous = node;
	node->previous->next = node;
}
void LinkedList::popQueue(){
	struct Node * tmp = backSentinal->previous;
	if(tmp == frontSentinal){
		printf(ANSI_COLOR_RED "Queue is empty.\n" ANSI_COLOR_RESET);
	}else{
		backSentinal->previous = tmp->previous;
		tmp->previous->next = backSentinal;
		delete(tmp);
	}
}
void LinkedList::popStack(){
	struct Node * tmp = frontSentinal->next;
	if(tmp == backSentinal){
		printf(ANSI_COLOR_RED "Stack is empty.\n" ANSI_COLOR_RESET);
	}else{
		frontSentinal->next = tmp->next;
		tmp->next->previous = frontSentinal;
		delete(tmp);
	}
}
void LinkedList::addAfter(struct Node * current, struct Node * node){
	if(current == backSentinal){
		printf(ANSI_COLOR_RED "Cannot add after back Sentinal.\n" ANSI_COLOR_RESET);
	}else{
		node->next = current->next;
		node->previous = current;
		node->next->previous = node;
		node->previous->next = node;
	}
}
void LinkedList::addBefore(struct Node * current, struct Node * node){
	if(current == frontSentinal){
		printf(ANSI_COLOR_RED "Cannot add before front Sentinal.\n" ANSI_COLOR_RESET);
	}else{
		node->next = current;
		node->previous = current->previous;
		node->next->previous = node;
		node->previous->next = node;
	}
}
void LinkedList::remove(struct Node * node){
	if(node == frontSentinal || node == backSentinal){
		printf(ANSI_COLOR_RED "Cannot delete sentinals.\n" ANSI_COLOR_RESET);
	}else{
		node->next->previous = node->previous;
		node->previous->next = node->next;
		delete(node);
	}
}
struct Node * LinkedList::Top(){
	return frontSentinal->next;
}
struct Node * LinkedList::Tail(){
	return backSentinal->previous;
}
struct Node * LinkedList::search(int value){
	struct Node * index = frontSentinal;
	while(index != backSentinal){
		index = index->next;
		if(index->data.INT == value)
			return index;
	}
	return NULL;
}
struct Node * LinkedList::search(float value){
	struct Node * index = frontSentinal;
	while(index != backSentinal){
		index = index->next;
		if(index->data.FLOAT == value)
			return index;
	}
	return NULL;
}
struct Node * LinkedList::search(char value){
	struct Node * index = frontSentinal;
	while(index != backSentinal){
		index = index->next;
		if(index->data.CHAR == value)
			return index;
	}
	return NULL;
}
struct Node * LinkedList::search(std::string value){
	struct Node * index = frontSentinal;
	while(index != backSentinal){
		index = index->next;
		if(index->data.STRING == value)
			return index;
	}
	return NULL;
}
LinkedList::~LinkedList(){
	struct Node * index = frontSentinal;
	while (index != backSentinal){
		index = index->next;
		if(index != backSentinal && index != frontSentinal){
			delete(index);
		}
	}
	delete(frontSentinal);
	delete(backSentinal);
}
