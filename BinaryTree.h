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
    Token *root;
    Token *grandParent;
    Token* parent;
    Token* leftChild;
    Token* rightChild;
    
public:
    BinaryTree(Token* root, Token newToken);
    ~BinaryTree();
    
    void treeIterate(Token* parent);		// keeps track of grandparent, parent, and children. Use get methods to grab data members
    void findAlpha(Token* parent);		// iterates through to find the top of the list (far leftChild [look for non-NULL nextLeftChild])
    
    Token* getGrandParent(Token* parent);		// not sure about parameters. May not need them, as will simply access current grandParent. Could also iterate from the root to the point where the parent is, as a search function just in case
    Token* getParent(Token* parent);
    Token* getRightChild(Token* parent);
    Token* getLeftChild(Token* parent);
    void addRightChild(Token* parent);
    void addLeftChild(Token* parent);
};


#endif /* defined(__cse220_lab4__BinaryTree__) */
