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
#include "IntegerList.h"
#include "IntegerNode.h"


using namespace std;

class Token;

class BinaryTree
{
private:
    Token* root;
    Token* grandParent;
    Token* parent;
    Token* leftChild;
    Token* rightChild;
    Token* currentToken;
    
public:
    BinaryTree(Token* root, Token newToken);
    ~BinaryTree();
    
    void treeIterate(Token* currentToken);		// keeps track of grandparent, parent, and children. Use get methods to grab data members
    void findAlpha(Token* currentToken);		// iterates through to find the top of the list (far leftChild [look for non-NULL nextLeftChild])
    
    Token* getFirstToken();						// TODO: Implement this
    Token* getGrandParent(Token* currentToken);		// not sure about parameters. May not need them, as will simply access current grandParent. Could also iterate from the root to the point where the parent is, as a search function just in case
    Token* getParent(Token* currentToken);
    Token* getRightChild(Token* currentToken);
    Token* getLeftChild(Token* currentToken);
    Token* getCurrentToken();
    Token* next(Token* currentToken);			// needs to change the parent/family fields
    bool isNotDone(Token* currentToken);		// boolean returns false only when all members of the tree have been used
    void addRightChild(Token* currentToken);
    void addLeftChild(Token* currentToken);
    
};


#endif /* defined(__cse220_lab4__BinaryTree__) */
