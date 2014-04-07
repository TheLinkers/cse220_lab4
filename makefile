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

OBJS = BinaryTree.o IntegerList.o main.o Print.o Scanner.o Token.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

CrossReference : $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o p1

main.o : main.cpp common.h Print.h Scanner.h Token.h
    $(CC) $(CFLAGS) main.cpp

BinaryTree.o : BinaryTree.h BinaryTree.cpp
    $(CC) $(CFLAGS) BinaryTree.cpp

IntegerList.o : IntegerList.h IntegerList.cpp
    $(CC) $(CFLAGS) IntegerList.cpp

Print.o : Print.h Print.cpp Token.h 
    $(CC) $(CFLAGS) Print.cpp

Scanner.o : Scanner.h Scanner.cpp Print.h 
    $(CC) $(CFLAGS) Scanner.cpp

Token.o : Token.h Token.cpp BinaryTree.h IntegerList.h
    $(CC) $(CFLAGS) Token.cpp

clean:
    \rm *.o *~ CrossReference


