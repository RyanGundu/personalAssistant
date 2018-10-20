#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userDefined.h"
#include "BinarySearchTreeAPI.h"
#include "commandLoop.h"
#include "Rule.h"

/**
*function prompts user for a valid fileName if an invalid one is given 
*/
FILE* myOpenforReading (char fileName[]) {
	FILE* fileptr; 
	char newFile[50];
	fileptr = fopen(fileName, "r");
	if (fileptr == NULL) {
		char option[20];
      	printf("Could not open file %s.\n",fileName);
      	printf("Press 1 to exit or 2 to Enter a new file name:\n");
      	scanf("%s", option);
      	getchar();
      	if (option[0] == '1') {
      		return NULL;
      	} else if (option[0] == '2') {
	      	printf("Please enter a new file name:\n");
	      	scanf("%s",newFile);
	      	getchar();
	      	fileptr = myOpenforReading(newFile);
	      	return fileptr;
      }       
   }
   
   return fileptr;
}

int main (int arg, char*argv[]) {

	FILE *fptr = NULL;
	fptr = myOpenforReading( argv[1] );
	if (fptr == NULL) {
		return 0;
	}
	int i = 0;
	const double DEFAULT_RATING = 0.5;
	char *text = malloc(sizeof(char) * 46);

	char *keyWord;
	char *response;
	Rule *newRule;

	Tree *tree = createBinTree(&compare, &deleteFunc);

	while ( fgets ( text, 46, fptr ) ) {

		removeTrailingHardReturn(text);
		makeLowerCase(text);
		if (i%2 == 0) {
			keyWord = malloc(sizeof(char) *(strlen(text) +1));
			strcpy(keyWord,text);
		} else {
			response = malloc(sizeof(char) *(strlen(text) +1));
			strcpy(response,text);
			newRule = createRule(keyWord, response, DEFAULT_RATING, DEFAULT_RATING);
			addToTree(tree, newRule);
		}
		++i;

	}
	commandLoop(tree);

	free(text);
	destroyBinTree(tree);

	fclose(fptr);

	return 0;

}
