/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 IntegerNode.h
 Lab4 */

#ifndef __cse220_lab4__IntegerNode__
#define __cse220_lab4__IntegerNode__

#include <iostream>
#include "common.h"
#include "Token.h"
#include "BinaryTree.h"
#include "IntegerList.h"

using namespace std;

class IntegerNode
{
private:
    int value;
    IntegerNode* next;
    IntegerNode* previous;
    
public:
    IntegerNode(int value, IntegerNode* previous) ;
    ~IntegerNode();
    int getValue();
    IntegerNode* getNext();
    IntegerNode* getPrevious();
    void setNext(IntegerNode* node);
    void setPrevious(IntegerNode* node);
};

#endif /* defined(__cse220_lab4__IntegerNode__) */


