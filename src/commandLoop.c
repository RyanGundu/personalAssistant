#include "commandLoop.h"

void commandLoop (Tree *theTree) {

	char *text = malloc(sizeof(char) * 30);	
	while (1) {
		printf("\n");
		printf("Enter an option (1,2,3,4,5,9)\n");
		printf("----------------------------\n");
		printf("1) Add a new rule\n");
		printf("2) Remove a rule\n");
		printf("3) Display rules\n");
		printf("4) Modify rule ratings\n");
		printf("5) Discuss\n\n");
		printf("9) Quit\n");
		printf("\nEnter an option: ");	
		fgets (text, 10, stdin);
		removeTrailingHardReturn(text);
		if (strlen(text) > 1) {
			printf("Invalid Option\n");
		} else if (text[0] == '1') {
			addRule(theTree);
		} else if (text[0] == '2') {
			removeRule(theTree);
		} else if (text[0] == '3') {
			printf("\n");
			printInOrder(theTree, &printNodeData);
		} else if (text[0] == '4') {
			updateRule(theTree);
		} else if (text[0] == '5') {
			discuss(theTree);
		} else if (text[0] == '9') {
			break;
		} else {
			printf("Invalid Option\n");
		}
	} 
	free(text);
	
}

double checkRating(char *toCheck) {

	if (strlen(toCheck) == 0)
		return -1;

	int count = 0;
	for(int i = 0; i<strlen(toCheck); ++i) {
		if (toCheck[i] == '.')
			++count;
		if ((isdigit(toCheck[i]) == 0 && toCheck[i] != '.') || count > 1)
			return -1;
	}
	return 0;
}

void addRule (Tree *theTree) {

	char *keyword = malloc(sizeof(char) * 46);	
	printf("Enter a keyword to add: ");
	fgets (keyword, 46, stdin);
	removeTrailingHardReturn(keyword);
	makeLowerCase(keyword);
	Rule *tempRule = createRule(keyword, NULL, 0.5, 0.5);
	if (findInTree(theTree, tempRule) != NULL) {
		printf("The keyword \"%s\" already exists\n", keyword);
		return;
	}
	char *word = malloc(sizeof(char) *(strlen(keyword) +1));
	strcpy(word,keyword);
	
	char *sentence = malloc(sizeof(char) * 100);
	printf("Enter a response: ");
	fgets (sentence, 46, stdin);
	removeTrailingHardReturn(sentence);
	char *response = malloc(sizeof(char) * (strlen(sentence) +1));
	strcpy(response, sentence);
	
	char *ratingCheck = malloc(sizeof(char) * 10);
	double rating;

	/* Checks validity of rating value */
	do {
		rating = -1;
		while (rating != 0) {
			printf("Enter a rating (0-1): ");
			fgets (ratingCheck, 10, stdin);
			removeTrailingHardReturn(ratingCheck);
			rating = checkRating(ratingCheck);
		}
		rating = atof(ratingCheck);
	} while (rating > 1 || rating < 0);

	Rule *newRule = createRule(keyword, response, rating, 0.5);
	addToTree(theTree, newRule);
	free(ratingCheck);
	printf("The new rule has been added.\n");

}

void removeRule (Tree *theTree) {

	char *keyword = malloc(sizeof(char) * 30);
	printf("Enter a keyword to remove: ");
	fgets ( keyword, 30, stdin);
	removeTrailingHardReturn(keyword);
	makeLowerCase(keyword);
	Rule *tempRule = createRule(keyword, NULL, 0.5, 0.5);
	if (findInTree(theTree, tempRule) == NULL) {
		printf("\"%s\" was not found.\n", keyword);
	} else {
		removeFromTree (theTree, tempRule);
		printf("\"%s\" has been removed.\n", keyword);
		free(keyword);
		free(tempRule);
	}

}

void updateRule (Tree* theTree) {

	char *keyword = malloc(sizeof(char) * 30);
	printf("Enter the keyword: ");
	fgets ( keyword, 30, stdin);
	removeTrailingHardReturn(keyword);
	makeLowerCase(keyword);

	Rule *tempRule = createRule(keyword, NULL, 0.5, 0.5);
	Rule *toChange = findInTree(theTree, tempRule);
	if (toChange == NULL) {
		printf("The keyword \"%s\" was not found.\n", keyword);
		free(tempRule);
		return;
	}

	char *ratingCheck = malloc(sizeof(char) * 10);
	double rating;

	/* Checks validity of rating value */
	do {
		rating = -1;
		while (rating != 0) {
			printf("\nCurrent Rating: %.2lf\n", toChange->userRating);
			printf("Enter a new rating (0-1): ");
			fgets (ratingCheck, 10, stdin);
			removeTrailingHardReturn(ratingCheck);
			rating = checkRating(ratingCheck);
		}
		rating = atof(ratingCheck);
	} while (rating > 1 || rating < 0);

	toChange->userRating = rating;
	free(keyword);
	free(tempRule);
	printf("The rating has been updated.\n");

}

void discuss(Tree *theTree) {
	
	char *question = malloc(sizeof(char) * 30);
	printf("Ask a question: ");
	fgets ( question, 100, stdin);
	removeTrailingHardReturn(question);
	removePunc(question);
	makeLowerCase(question);
	
	int wordLocation[30];
	int j = 0;
	int words = 0;
	int count = 0;
	int flag = 0;

	/* Counts the number of words and stores the index of each */
	for (int i = 0; i < strlen(question); ++i) {
		if (isspace(question[i]) == 0 || i == strlen(question)-1) 
			count = 1;
		if ((isspace(question[i]) != 0 && count == 1) || (i == strlen(question)-1)) {
			++words;
			count = 0;
		}
		if (isspace(question[i]) == 0 && flag == 0) {
			wordLocation[j] = i;
			flag = 1;
			++j;
		}
		if (isspace(question[i]) != 0) {
			flag = 0;
		}	
	}

	/* Parse the words in the question */
	char **parsedWords = malloc(sizeof(char*)*words);
	char *tempWord = malloc(sizeof(char) * 46);
	for (int i = 0; i < words; ++i) {
		int k = subString(question, wordLocation[i]);
		tempWord = createWord(question, wordLocation[i], k);
		parsedWords[i]= tempWord;
	}

	/* locate the max importance */
	int priorityWord = -1;
	double importance = 0;
	double currentImport = 0;
	Rule *tempRule;
	for (int i = 0; i < words; ++i)
	{
		tempRule = createRule(parsedWords[i], NULL, 0.5, 0.5);
		Rule *toFind = findInTree(theTree, tempRule);
		if(toFind != NULL ) {
			currentImport = getImportance(toFind);
			if (importance < currentImport) {
				importance = currentImport;
				priorityWord = i;
			}
		}
	}

	/* if keyword is found or not */
	if (priorityWord != -1) {
		tempRule = createRule(parsedWords[priorityWord], NULL, 0.5, 0.5);
		Rule *toPrint = findInTree(theTree, tempRule);
		printResponse(toPrint);
		feedBack(theTree, toPrint);
		free(tempRule);

	} else {
		printf("\nSorry, I'm currently unable to help with that but I'm learning.\n");
	}

	/* free the temporary memory */
	for (int i = 0; i < words; ++i)
	{
		free(parsedWords[i]);
	}
	free(parsedWords);
	parsedWords = NULL;	

}

int subString (char* string, int start) {
	for (int i = start; i < strlen(string); ++i) {
		if (isspace(string[i]) != 0) {
			return i;
		}	
	}
	return strlen(string);
}

char *createWord(char* string, int start, int end) {

	char* word = malloc(sizeof(char) * (end-start+1));
	int j = 0;
	for (int i = start; i<end; ++i) {
		word[j] = string[i]; 
		++j;
	}
	word[strlen(word)] = '\0';
	removePunc(word);
	return word;
}

void feedBack (Tree *theTree, void* data) {

	int x = 0;
	while (x == 0) {
		char *feedBack = malloc(sizeof(char) * 10);
		printf("Was this feedBack helpful? 'y' or 'n': ");
		fgets ( feedBack, 10, stdin);
		removeTrailingHardReturn(feedBack);
		makeLowerCase(feedBack);
		if (strcmp("y",feedBack) == 0 || strcmp("yes",feedBack) == 0) {
			updateData(data, YES);
			x = 1;
		} else if (strcmp("n",feedBack) == 0 || strcmp("no",feedBack) == 0) {
			updateData(data, NO);
			x = 1;
		} else {
			printf("Invalid response\n");
		}
	}
	

}

void removePunc (char line[]) {
	if (isalpha(line[strlen(line)-1]) == 0)
   	{
      line[strlen(line)-1] = '\0';
   	}
   	return;
}

void removeTrailingHardReturn(char line[]) {

   	if (line[strlen(line)-1] == '\n')
   	{
     	 line[strlen(line)-1] = '\0';
   	}
   	return;
}

void makeLowerCase (char *text) {

	for (int i = 0; i<strlen(text); i++) 
		text[i] = tolower(text[i]);

}
