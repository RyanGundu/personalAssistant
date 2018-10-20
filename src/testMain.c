#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userDefined.h"
#include "BinarySearchTreeAPI.h"
#include "commandLoop.h"

int main (int arg, char*argv[]) {

	const double DEFAULT_RATING = 0.5;
	Tree *testTree = createBinTree(&compare, &deleteFunc);
	Tree *emptyTree = createBinTree(&compare, &deleteFunc);


	/* creating dummy values to create new rules */
	char *keyWord1 = malloc(sizeof(char)*10);
	strcpy(keyWord1,"hello");
	char *response1 = malloc(sizeof(char)*30);
	strcpy(response1,"hi there!");
	Rule *newRule1 = createRule(keyWord1, response1, DEFAULT_RATING, DEFAULT_RATING);

	char *keyWord2 = malloc(sizeof(char)*10);
	strcpy(keyWord2,"exams");
	char *response2 = malloc(sizeof(char)*30);
	strcpy(response2,"you can do it!");
	Rule *newRule2 = createRule(keyWord2, response2, DEFAULT_RATING, DEFAULT_RATING);

	char *keyWord3 = malloc(sizeof(char)*10);
	strcpy(keyWord3,"tired");
	char *response3 = malloc(sizeof(char)*30);
	strcpy(response3,"go to sleep soon.");
	Rule *newRule3 = createRule(keyWord3, response3, DEFAULT_RATING, DEFAULT_RATING);

	char *keyWord4 = malloc(sizeof(char)*10);
	strcpy(keyWord4,"mad");
	char *response4 = malloc(sizeof(char)*30);
	strcpy(response4,"don't be mad.");
	Rule *newRule4 = createRule(keyWord4, response4, DEFAULT_RATING, DEFAULT_RATING);

	/* Add them to the tree */
	addToTree(testTree, newRule1);
	addToTree(testTree, newRule2);
	addToTree(testTree, newRule3);
	addToTree(testTree, newRule4);
	/****************************/

	/* testing the order of printing (in order,pre order, post order) */
	printf("Print tree using inOrder traversal\n");
	printInOrder(testTree, &printNodeData);
	printf("\n");
	printf("Print tree using preOrder traversal\n");
	printPreOrder(testTree, &printNodeData);
	printf("\n");
	printf("Print tree using postOrder traversal\n");
	printPostOrder(testTree, &printNodeData); 
	printf("\n");

	/* Test the removal of a rule */
	removeFromTree(testTree, newRule2);
	printf("keyword \"exam\" is now gone\n");
	printInOrder(testTree, &printNodeData);
	printf("\n");

	removeFromTree(testTree, newRule4);
	printf("keyword \"mad\" is now gone\n");
	printInOrder(testTree, &printNodeData);
	printf("\n");

	/* test the search */
	char *toFind = malloc(sizeof(char)*10);
	strcpy(toFind,"tired");
	char *test = malloc(sizeof(char)*20);
	strcpy(test,"go to sleep soon.");
	Rule *ruleToFind = createRule(toFind, test, DEFAULT_RATING, DEFAULT_RATING);
	Rule *found = findInTree(testTree, ruleToFind);
	if (found) {
		printf("Searched and found data:\n");
		printNodeData(found);
	} else {
		printf("The keyword tired was not found\n");
	}
	printf("\n");

	/* test isEmpty */
	printf("Testing isEmpty on non-empty tree\n");
	if (isTreeEmpty(testTree) == 0) {
		printf("It's not empty\n");
	} else printf("The tree is empty\n");
	printf("\n");

	printf("Testing isEmpty on empty tree\n");
	if (isTreeEmpty(emptyTree) == 0) {
		printf("It's not empty\n");
	} else printf("The tree is empty\n");
	printf("\n");

	/* getting the root Data */
	printf("Testing getRootData and printing it:\n");
	printNodeData(getRootData(testTree));
	printf("\n");

	/* destroy the tree */
	destroyBinTree(testTree);



	return 0;

}
