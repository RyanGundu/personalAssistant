#ifndef RULE
#define RULE

#include <stdlib.h>
#include <stdio.h>

/**
* Struct defining the components of a rule
*/
typedef struct rule Rule;
struct rule {

	char *keyword;
	char *response;
	double userRating;
	double systemRating;
	int occurrences;

};

/**
* Function to create and allocate memory for a rule
* @param char* - keyword
* @param char* - response
* @param double - userRyan
* @param double - systemRating
*/
Rule *createRule(char* keyword, char* response, double userRating, double systemRating);






#endif
