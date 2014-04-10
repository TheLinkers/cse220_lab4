/*
 Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 //  Token.cpp
 //  Lab4
 //
 //  Created by Bryce Holton.
 */

#include "Token.h"
#include "BinaryTree.h"
#include "IntegerList.h"

Token::Token()
{
    leftChild = NULL;
    rightChild = NULL;
	leftCalled = false;
	rightCalled = true;
	//What code do I need here to initialize everything.
}
Token::~Token()
{
	//What code do I need here to free memory
    
    
}
void Token::setCode(TokenCode newCode)
{
    this->code = newCode;
}
TokenCode Token::getCode()
{
    return this->code;
}
void Token::setType(LiteralType newType)
{
    this->type = newType;
}
LiteralType Token::getType()
{
    return this->type;
}
void Token::setLiteral(int newInteger)
{
    this->literal.integer = newInteger;
}
int Token::getIntLiteral()
{
    return this->literal.integer;
}
void Token::setLiteral(float newReal)
{
    this->literal.real = newReal;
}
float Token::getRealLiteral()
{
    return this->literal.real;
}
void Token::setLiteral(string newString)
{
	this->literal.stringLiteral = (char*)malloc(sizeof(char) * newString.length() + 1);
    strcpy(this->literal.stringLiteral, newString.c_str());
}
string Token::getStringLiteral()
{
    return string(this->literal.stringLiteral);
}
void Token::setTokenString(string s)
{
    this->tokenString = s;
}
string Token::getTokenString()
{
    return this->tokenString;
}
void Token::addLineToList(int value)
{
    this->list->appendToList(value);
}

Token* Token::getLeftChild() {
    return leftChild;
}
Token* Token::getRightChild() {
    return rightChild;
}
void Token::setRightChild(Token* token) {
    rightChild = token;
}
void Token::setLeftChild(Token* token) {
    leftChild = token;
}

void Token::printList() {
    int printValue;
    IntegerNode* currentNode = list->getHead();	// first IntegerNode from list
    
    while (currentNode)  {						// when currentNode != NULL (may need to change to satisfy boolean
	printValue = currentNode->getValue();		// grabs first int from the list
	cout << printValue << "\t";
	currentNode = currentNode->getNext();		// increments to next IntegerNode to print
    }
    
    cout << "\n";	// end of line
    
}// loops through integerList in Token and direcly couts the contents



    // Method to check for existing tokens
/*boolean Token::isEqual()
 {
 // check if string from token is equal to the one in the binary tree
 // may not need this method here, but elsewhere
 // I'll leave this commented in case this is a good home for it
 
 
 }
 What methods am I missing to implement a binary tree.*/
