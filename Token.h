/*
 Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 //  Token.h
 //  Lab4
 //
 //  Created by Bryce Holton.
 */

#ifndef __Lab4__Token__
#define __Lab4__Token__

#include <iostream>
#include "common.h"
#include "BinaryTree.h"
#include "IntegerNode.h"

using namespace std;

class IntegerList;

/**************
 this is a valid Pascal token.  A token must have a literal type,
 a literal value, and a token code.
 ***************/
class Token
{
private:
    TokenCode code;
    LiteralType type;
    union
    {
    int integer;
    float real;
    char *stringLiteral;
    }
    literal;
    string tokenString;
    
    Token *grandparent;		// grandparent in binaryTree: set when added to tree structure
    Token *parent;			// parent in binaryTree: set when added to binary tree
    Token *leftChild;		// children in the binaryTree structure
    Token *rightChild;
    IntegerList* list;		// forward declaration only allows declarations of pointers
    
    
public:
    Token();
    ~Token();
    void setCode(TokenCode newCode);
    TokenCode getCode();
    void setType(LiteralType newType);
    LiteralType getType();
    void setLiteral(int newInteger);
    int getIntLiteral();
    void setLiteral(float newReal);
    float getRealLiteral();
    void setLiteral(string newString);
    string getStringLiteral();
    void setTokenString(string s);
    string getTokenString();
    
    Token* getLeftChild();			// necessary methods for binaryTree organization
    Token* getRightChild();
    Token* getParent();
    Token* getGrandparent();
    void setRightChild(Token*);
    void setLeftChild(Token*);
    void setParent(Token*);
    void setGrandparent(Token*);
    
    void addLineToList(int value);	// for adding current line number to a specified integerlist
    void printList();					// loops through integerList in Token and direcly couts the contents
};

#endif /* defined(__Lab4__Token__) */
