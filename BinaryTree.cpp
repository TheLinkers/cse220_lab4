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
#include "Token.h"
#include "IntegerList.h"


    // creation method
BinaryTree::BinaryTree(Token* root) {
    this->root = root;
}
BinaryTree::~BinaryTree() {
    
}

    // adding methods: need to compare strings of tokens
    // stores values of family tokens into tokens as they go: just create each family member as temporary token pointers in method
void BinaryTree::addToken(Token* newToken) {
    Token* grandParent = root;
    Token* parent = root;
    bool notYetHome = true;
    string tokenString = newToken->getTokenString();
    string leafString = root->getTokenString();

    while (notYetHome) {			// once token has been placed, set to false
	if (tokenString < leafString) {
		// move to left
	    
	    
	} else if (tokenString > leafString) {
		// move to right
	} else {
	    cout << "Tree addition error\n";
	}
    }
    
    
}



    // sifting methods
void BinaryTree::treeIterate(Token* currentToken) {
	// idea here is to be able to call one method from print to go to the next alphabetical member of the tree
    	// will need to keep track of the token family members in order to go in the right order
    	// some interesting cases will come up when the tree is incomplete in some ways
	// also need to avoid calling the same token more than once
    	// perhaps some sort of deallocate/shrink functionality that makes the remaining children "jump" up a generation or something
    
    
} // keeps track of grandparent, parent, and children. Use get methods to grab data members
void BinaryTree::findAlpha(Token *currentToken) {
    
} // iterates through to find the top of the list (far leftChild [look for non-NULL nextLeftChild])
