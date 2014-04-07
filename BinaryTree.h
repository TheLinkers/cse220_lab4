/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 BinaryTree.h
 Lab4 */

#ifndef __cse220_lab4__BinaryTree__
#define __cse220_lab4__BinaryTree__

#include <iostream>
#include "common.h"
#include "Token.h"

using namespace std;

class BinaryTree
{
private:
    Token* rootPtr;
    
public:
    BinaryTree(Token* root, Token newToken);
    ~BinaryTree();
    
    Token* getRightChild(Token* token);
    Token* getLeftChild(Token* token);
    void addRightChild(Token* token);
    void addLeftChild(Token* token);
};


#endif /* defined(__cse220_lab4__BinaryTree__) */
