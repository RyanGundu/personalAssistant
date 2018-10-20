#ifndef USER
#define USER

#include "BinarySearchTreeAPI.h"
#include "commandLoop.h"
#include "Rule.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Constants for feedback
#define YES 0
#define NO 1

/** Function frees the data within a Node
*@param data is a generic pointer to any data type.
*/
void deleteFunc (void *data);

/** Function prints the data within a Node
*@param toBePrinted is a generic pointer to any data type (to be casted and printed)
*@param index is the index of the data being printed
*/
void printNodeData (void *toBePrinted);

/** Function used to compare data
*@param first is a generic pointer to any data type.
*@param second is a generic pointer to any data type.
*@return returns 0 if the data matches, otherwise returns a value less or grater than 0
*/
int compare (const void *first,const void *second);

/**
* Function returns the importance value
* @param data
* @return double - the sum of user and system rating
*/
double getImportance (const void *data);

/**
* Function prints the response
* @param data
*/
void printResponse(const void* data);

/**
*  adds to occurence counter and updates ratings based on response
* @param data
*/
void updateData (const void *data, int response);

#endif
