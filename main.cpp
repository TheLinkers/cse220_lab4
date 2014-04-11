/*
 Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 8 Apr 2014
 CSE 220
 10:30am T Th
 
 //  main.cpp
 //  Lab4
 //
 //  Created by Bryce Holton.
 */

#include <iostream>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Token.h"
#include "BinaryTree.h"
#include "IntegerList.h"

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Token *list);
void add_token_to_list(Token *list, Token *new_token);

int main(int argc, const char * argv[])
{
    /******************************************
     This is not a correct implementation, you will need to modfy this
     so that it satisfies the project problem.  Currently, this just
     prints every token and then deletes every token.
     *****************************************/
    Token *token = NULL;		// not sure if this may throw errors or not: how to properly allocate in memory? need to keep root of binaryTree in mind
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    FILE *source_file = init_lister(argv[1], source_name, date);
    Print print(source_name, date);
    Scanner scanner(source_file, source_name, date, print);
    int identifierCount = 0;
	BinaryTree tree = BinaryTree();					// not sure how to properly initialize/set the root of the tree
    
    do
	{
        token = scanner.getToken();
        print.printToken(token);
	
	    // BinaryTree stuff goes here
	    // If token is IDENTIFIER type, sends token pointer to tree to check if it exists
		if (token->getCode() == IDENTIFIER) {
			++identifierCount;
			tree.addToken(token);
		}
		/*if (token->getCode() != PERIOD && token->getCode() != END_OF_FILE && token->getCode() != IDENTIFIER)
		{
			delete token;
		}*/
	}while (token->getCode() != PERIOD && token->getCode() != END_OF_FILE);
    
    delete token;
    fclose(source_file);
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    
    strcpy(source_file_name, name);
    file = fopen(source_file_name, "r");
    time(&timer);
    strcpy(dte, asctime(localtime(&timer)));
    return file;
}

