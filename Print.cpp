/*
 Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 //  Print.cpp
 //  Lab4
 //
 //  Created by Bryce Holton.
 */

#include "Print.h"
#include "Token.h"
#include "BinaryTree.h"
#include "IntegerList.h"

const char* const SYMBOL_STRINGS[] =
{
    "<no token>", "<IDENTIFIER>", "<NUMBER>", "<STRING>",
    "^","*","(",")","-","+","=","[","]",":",";",
    "<",">",",",".","/",":=","<=",">=","<>","..",
    "<END OF FILE>", "<ERROR>",
    "AND","ARRAY","BEGIN","CASE","CONST","DIV","DO","DOWNTO",
    "ELSE","END","FILE","FOR","FUNCTION","GOTO","IF","IN",
    "LABEL","MOD","NIL","NOT","OF","OR","PACKED","PROCEDURE",
    "PROGRAM","RECORD","REPEAT","SET","THEN","TO","TYPE","UNTIL",
    "VAR","WHILE","WITH",
};

Print::Print(char source_name[], char date[])
{
    this->sourceFileName = string(source_name);
    this->currentDate = string(date);
    this->pageNumber = 0;
}
Print::~Print()
{
    
}
void Print::printLine(char line[])
{
    char save_ch = '\0';
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        printPageHeader();
        line_count = 1;
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH)
    {
        save_chp = &line[MAX_PRINT_LINE_LENGTH];
    }
    if (save_chp)
    {
        save_ch = *save_chp;
        *save_chp = '\0';
    }
    printf("%s", line);
    if (save_chp)
    {
        *save_chp = save_ch;
    }
}
void Print::printPageHeader()
{
    putchar(FORM_FEED_CHAR);
    printf("Page    %d  %s  %s\n\n", ++pageNumber, sourceFileName.c_str(), currentDate.c_str());
}
void Print::printToken(Token *token)
{
    char line[MAX_SOURCE_LINE_LENGTH + 32];
    const char *symbol_string = SYMBOL_STRINGS[token->getCode()];
    
    switch (token->getCode())
    {
        case NUMBER:
            if (token->getType() == INTEGER_LIT)
            {
                sprintf(line, "    >> %-16s %d (integer)\n", symbol_string, token->getIntLiteral());
            }
            else
            {
                sprintf(line, "    >> %-16s %g (real)\n", symbol_string, token->getRealLiteral());
            }
            break;
        case STRING:
            sprintf(line, "    >> %-16s %-s\n", symbol_string, token->getStringLiteral().c_str());
            break;
        default:
            sprintf(line, "    >> %-16s %-s\n", symbol_string, token->getTokenString().c_str());
            break;
    }
    printLine(line);
}

void Print::printTree(Token* root, BinaryTree tree) {
	// starts with the root of the BinaryTree and prints in alphabetical order
	// happens at the end of printing all the tokens in the usual manner
    cout << "\n\nCross Reference Information\nIdentifier\t\t\tLine Numbers\n-----------\t\t\t------------\n";
    string tokenString;
    Token* token;
    
	/* Pseudocode
	 1. Print header (above)
	 2. Find first token (alphabetically) and print its string
	 3. Tab over
	 4. Access token's integerList and increment through linked list printing ints until NULL
	 5. New line
	 6. Print next token (alphabetically [parent in tree])
	 7. Repeat process of printing respective integerList
	 8. Continue until BinaryTree is completed (NULL)
	 */
	
    token = tree.getFirstToken();
    tokenString = token->getTokenString();
    cout << tokenString << "\t\t";

    while (tree.isNotDone) {			// checks boolean for whether end of binaryTree has been reached
	token = tree.next(token);		// grabs next token in the binaryTree
	tokenString = token->getTokenString();
	cout << tokenString << "\t\t";
    }
   
    
    
    
}




