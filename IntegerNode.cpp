/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 IntegerNode.cpp
 Lab4 */

#include "IntegerNode.h"

IntegerNode::IntegerNode(int value, IntegerNode* previous) {
    this->value = value;
    this->previous = previous;
    this->next = NULL;
}

IntegerNode::~IntegerNode() {
    this->previous = NULL;
    this->next = NULL;
}

int IntegerNode::getValue() {
    return this->value;
}

IntegerNode* IntegerNode::getNext() {
    return this->next;
}

IntegerNode* IntegerNode::getPrevious() {
    return this->previous;
}

void IntegerNode::setNext(IntegerNode* node) {
    this->next = node;
}

void IntegerNode::setPrevious(IntegerNode* node) {
    this->previous = node;
}
