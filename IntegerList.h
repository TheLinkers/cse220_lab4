/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 IntegerList.h
 Lab4 */

#ifndef __cse220_lab4__IntegerList__
#define __cse220_lab4__IntegerList__

#include <iostream>
#include "common.h"
#include "Token.h"
#include "BinaryTree.h"

using namespace std;

class IntegerList
{
private:
    int value;
    int* nextValue;
    string identifier;		// one list created for each unique identifier in program
    
public:
    IntegerList(int value, int* nextValue);
    ~IntegerList();

    int getValue(int* address);
    void setValue(int value, int* address);

};



#endif /* defined(__cse220_lab4__IntegerList__) */
