/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 IntegerNode.cpp
 Lab4 */
Put /home/dmart/Documents/CSE_220/cse220_lab4/IntegerNode.cpp

#include "IntegerNode.h"

IntegerNode::IntegerNode(int value, IntegerNode* previous) {
    this->value = value;
    this->previous = previous;
}

IntegerNode::~IntegerNode() {
    this->previous = NULL;
    this->next = NULL;
}

int IntegerNode::getValue() {
    return this.value;
}

IntegerNode* IntegerNode::getNext() {
    return this.next;
}

IntegerNode* IntegerNode::getPrevious() {
    return this.previous;
}
