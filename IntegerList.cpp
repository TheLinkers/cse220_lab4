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
    tail = new IntegerNode(value, NULL);
    this->head = this->tail;
	this->numberOfNodes = 1;
}

IntegerList::IntegerList(IntegerNode node) {
    this->tail = &node;
    this->head = this->tail;
	this->numberOfNodes = 1;
}

IntegerList::~IntegerList() {
    IntegerNode *temp = this->head;
    while (this->head != NULL){
		temp = head->getNext();
		delete head;
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
    IntegerNode *newTail = new IntegerNode(value, this->tail);
    this->tail->setNext(newTail);
    this->tail = newTail;
	++numberOfNodes;
}

void IntegerList::appendToList(IntegerNode node) {
    this->tail = &node;
	++numberOfNodes;
}
