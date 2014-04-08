/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 IntegerTree.cpp
 Lab4 */

#include "IntegerList.h"

IntegerList::IntegerList(int value) {
    this->appendToList(value);
}

IntegerList::IntegerList(IntegerNode node) {
    this->appendToList(node);
}

IntegerList::~IntegerList() {
    IntegerNode *temp = this->head;
    while (this->head != NULL){
		temp = (is_heap)-> next;
		free(head);
		this->head = temp;
	}
}

IntegerNode* IntegerList::getHead() {
    return this->head;
} // allows us to find the beginning of the integerlist for printing/deallocating

IntegerNode* IntegerList::getTail() {
    return this->tail;
} 


void IntegerList::appendToList(int value) {
    this->tail = IntegerNode(value, this->tail);
    if(this->numberOfNodes == NULL){
	numberOfNodes = 1;
    }
    else{
	++numberOfNodes;
    }
}

void IntegerList::appendToList(IntegerNode node) {
    this->tail = value;
    if(this->numberOfNodes == NULL){
	numberOfNodes = 1;
    }
    else{
	++numberOfNodes;
    }
}