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
	delete this->root;
}

    // adding methods: need to compare strings of tokens
    // stores values of family tokens into tokens as they go: just create each family member as temporary token pointers in method
void BinaryTree::addToken(Token* newToken) {
    this->seekLeft = true;
    Token* grandParent = root;
    Token* parent = root;
    bool notYetHome = true;
    string tokenString = newToken->getTokenString();
    string leafString = root->getTokenString();
	// perhaps name one of these the treePointer for the current location searching for
    
    /* Tree addition logic:
     1. Start at root
     2. Grab root string
     3. Check IF token string is less or greater than root string
     4. Move left or right, respectively
     5. If child doesn't exist in the spot, then fill it in (set newToken equal to the child)
     6. Set notYetHome equal to false
     7. Else navigate to that child and set the string equal to leafstring and check again
     */
    
    
    while (notYetHome) {			// once token has been placed, set to false
	if (tokenString < leafString) {
		// move to leftChild
	    if (parent->getLeftChild() != NULL) {		// check to make sure that the left child exists
		grandParent = parent;					// not sure if this means grandparent always points to parent, even if parent moves
		parent = parent->getLeftChild();
	    } else {
		parent->setLeftChild(newToken);
		newToken->setParent(parent);
		newToken->setGrandparent(grandParent);
		notYetHome = false;
	    }
	    
	} else if (tokenString > leafString) {
		// move to right
	    if (parent->getRightChild() != NULL) {			// check to make sure that the right child exists
		grandParent = parent;
		parent = parent->getRightChild();
	    } else {
		parent->setRightChild(newToken);
		newToken->setParent(parent);
		newToken->setGrandparent(grandParent);
		notYetHome = false;
	    }
	    
	}
	else{ //newToken = currentToken
		parent->addLineToList(newToken->getFirstOccurrence());
		delete newToken;
		notYetHome = false;
	}
	leafString = parent->getTokenString();
    }
}

Token* BinaryTree::getFirstToken(){
	return this->root;
}

    // sifting methods
Token* BinaryTree::treeIterate(Token* currentToken) {
	// idea here is to be able to call one method from print to go to the next alphabetical member of the tree
    	// will need to keep track of the token family members in order to go in the right order
    	// some interesting cases will come up when the tree is incomplete in some ways
	// also need to avoid calling the same token more than once
    	// perhaps some sort of deallocate/shrink functionality that makes the remaining children "jump" up a generation or something
    
    /* Alphabetical Iterate Logic
     1. Have a "case" integer that designates what family member was just pulled (0 for leftChild, 1 for parent, etc.)
     2. Move-> bottom left child, parent, bottom left child of right child, parent (right child), etc.
     3. Return token with each iterate
     */
    Token* returnToken = root;
    
    if (currentToken->getLeftChild() != NULL && currentToken->hasLeftCalled() == false) {
	returnToken = findAlpha(currentToken);		// make sure to have condition for if already in the far left
	currentToken->setLeftCalled(true);
	return returnToken;
    } else if (currentToken->getRightChild() != NULL && currentToken->hasLeftCalled() == true) {
	currentToken = currentToken->getRightChild();
	if (currentToken->getLeftChild() != NULL) {
		// needs to seek far left inside first, then will loop back through anyhow
	    returnToken = findAlpha(currentToken);
	}
	return returnToken;
    } else if (currentToken->getLeftChild() == NULL && currentToken->getRightChild() == NULL) {	// at the end of a leaf
    	currentToken = root;		// start at root and find where first unused parent is
	if (root->hasLeftCalled() == false) {
	    do {
		currentToken = currentToken->getLeftChild();	// increments through unused parents
	    } while (currentToken->hasLeftCalled() == false && currentToken->getLeftChild() != NULL);
	} else if (root->hasRightCalled()) {		// may have some bugs in here
	    return root;
	} else {
	    currentToken = root->getRightChild();
	}

    } else {
	returnToken = currentToken->getParent();
	return returnToken;
    }
    return returnToken;
}

bool BinaryTree::isNotDone(Token *root) {
    Token* checkToken = root;
    bool isNotFinished = true;
    while (checkToken->getRightChild() != NULL) {
	    // statement navigates to far right child (end of list) to see if called
	checkToken = checkToken->getRightChild();
    }
    if (checkToken->hasRightCalled() == true) {
	isNotFinished = false;
	    // returns false if far right child has been called, meaning that the end of the alphabet has been reached
    }
    
    return isNotFinished;
}

    // keeps track of grandparent, parent, and children. Use get methods to grab data members
Token* BinaryTree::findAlpha(Token* currentToken) {
    Token *treePointer = currentToken;
    
    while (treePointer->getLeftChild() != NULL) {
	treePointer = treePointer->getLeftChild();
    }
    
    return treePointer;
    
} // iterates through to find the top of the list (far leftChild [look for non-NULL nextLeftChild])

/*void recursiveDelete(Token** node){
	Token* current = *node;
	if(current->getLeftChild() != NULL){
		recursiveDelete(*(current->getLeftChild()));
	}
	
	if(current->getRightChild() != NULL){
		recursiveDelete(*(current->getRightChild()));
	}
	delete current;
	*node = NULL;
}*/
