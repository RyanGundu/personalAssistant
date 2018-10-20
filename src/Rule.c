#include "Rule.h"

Rule *createRule(char* keyword, char* response, double userRating, double systemRating) {

	Rule *newRule = malloc(sizeof(Rule));
	newRule->keyword = keyword;
	newRule->response = response;
	newRule->userRating = userRating;
	newRule->systemRating = systemRating;
	newRule->occurrences = 0;

	return newRule;
	
}

