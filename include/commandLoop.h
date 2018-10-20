#ifndef COMMAND
#define COMMAND

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "BinarySearchTreeAPI.h"
#include "userDefined.h"

/** Function to display the menu untill and exit is requested
*@pre Tree must exist.
*@param binary tree pointer
*/
void commandLoop (Tree *theTree);

/**
* Function to check validity of rating
* @param toCheck
*/
double checkRating(char *toCheck);

/**
* Adds a new rule to the tree
* @param theTree
*/
void addRule (Tree *theTree);

/**
* Function to remove a rule if found
* @param theTree pointer to the binary tree to search
*/
void removeRule(Tree *theTree);

/**
* Function to update the user rating
* @param theTree
*/
void updateRule (Tree* theTree);

/**
* Function allows the dicussion to take place
* @param theTree
*/
void discuss(Tree *theTree);

/**
* Function locates the ending index of a string
* @param string
* @param start - starting index
* @return ending index of word
*/
int subString (char* string, int start);

/**
* Function uses index from substring and creates a word from string 
* @param string
* @param start - start index
* @param end - end index
* @return char* theWord
*/
char *createWord(char* string, int start, int end);

/**
* Function removes punctuation if at the end of a string
* @param line
*/
void removePunc (char line[]);

/**
* Function prompts feedback and updates 
* @param theTree
* @param data
*/
void feedBack(Tree *theTree, void* data);

/** 
* Function removes a hard return if it exists
*@param line is an array of characters
*/
void removeTrailingHardReturn(char line[]);

/** Function makes andy array of characters to lowercase
* @param array of characters to make lowercase
*/
void makeLowerCase (char *text);

#endif
