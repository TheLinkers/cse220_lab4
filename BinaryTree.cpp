/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 BinaryTree.cpp
 Lab4 */

#include "BinaryTree.h"

BinaryTree(Token* root, Token newToken);
~BinaryTree();

void treeIterate(Token* parent);		// keeps track of grandparent, parent, and children. Use get methods to grab data members
void findAlpha(Token *parent);		// iterates through to find the top of the list (far leftChild [look for non-NULL nextLeftChild])

Token* getGrandParent(Token* parent);		// not sure about parameters. May not need them, as will simply access current grandParent. Could also iterate from the root to the point where the parent is, as a search function just in case
Token* getParent(Token* parent);
Token* getRightChild(Token* parent);
Token* getLeftChild(Token* parent);
void addRightChild(Token* parent);
void addLeftChild(Token* parent);




