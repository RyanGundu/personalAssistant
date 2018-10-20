#include "userDefined.h"

int compare (const void *first, const void *second) {

	Rule *a = (Rule*)first;
	Rule *b = (Rule*)second;
	
	/* returns 0 on match */
	return (strcmp(a->keyword, b->keyword));
}

double getImportance (const void *data) {
	Rule *a = (Rule*)data;
	return (a->userRating + a->systemRating);
}

void printResponse (const void *data) {	
	Rule *a = (Rule*)data;
	printf("%s\n", a->response);
}

void updateData (const void *data, int response) {

	double learningRate = 0.5;
	Rule *a = (Rule*)data;
	a->occurrences += 1;

	double rating = a->systemRating;
	switch (response) {
		case YES:
			a->systemRating = rating + (rating*learningRate/a->occurrences);
			break;
		case NO:
			a->systemRating = rating - (rating*learningRate/a->occurrences);
			break;
		default:
			break;	
	}
	if (a->systemRating > 1) {
		a->systemRating = 1;
	} 
	else if (a->systemRating < 0) {
		a->systemRating = 0;
	}

}

void deleteFunc (void *data) {

	Rule* rule = (Rule*)data;

	free(rule->keyword);
	rule->keyword = NULL;
	free(rule->response);
	rule->response = NULL;
	free(rule);
	rule = NULL;

}

void printNodeData (void *toBePrinted) {

	Rule* rule = (Rule*)toBePrinted;
	printf("%s\tRating: %.2lf\tSystem: %.2lf\tOccurrences: %d\n",rule->keyword, rule->userRating, rule->systemRating, rule->occurrences);

}

