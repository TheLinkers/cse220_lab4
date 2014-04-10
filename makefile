#!/bin/bash
#******************************************************
#Team 15: https://github.com/TheLinkers/cse220_lab4
#Nikolas Conklin: nconklin
#Daniel Martin: plan10-acme
#Matthew Weser: mweser
# 
#Lab 4
#8 Apr 2014
#CSE 220
#10:30am T Th
#******************************************************* 

OBJS = BinaryTree.o IntegerList.o IntegerNode.o main.o Print.o Scanner.o Token.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

CrossReference : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

main.o : main.cpp common.h Print.h Scanner.h Token.h
	$(CC) $(CFLAGS) main.cpp

BinaryTree.o : BinaryTree.h BinaryTree.cpp Token.h IntegerList.h
	$(CC) $(CFLAGS) BinaryTree.cpp

IntegerList.o : IntegerList.h IntegerList.cpp
	$(CC) $(CFLAGS) IntegerList.cpp
    
IntegerNode.o : IntegerNode.h IntegerNode.cpp
	$(CC) $(CFLAGS) IntegerNode.cpp

Print.o : Print.h Print.cpp Token.h BinaryTree.h IntegerList.h
	$(CC) $(CFLAGS) Print.cpp

Scanner.o : Scanner.h Scanner.cpp Print.h 
	$(CC) $(CFLAGS) Scanner.cpp

Token.o : Token.h Token.cpp BinaryTree.h IntegerList.h
	$(CC) $(CFLAGS) Token.cpp

clean:
	\rm *.o *~ CrossReference


