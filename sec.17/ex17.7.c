#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordsTree.h"

int menu(void);
void displayTree(Tree *ptree);
void displayWord(Word word);
void findWord(Tree *ptree);
char *readIn(char *to, int n);

int main(int argc, char **argv)
{
	FILE *pf = fopen("words.txt", "r");
	Tree words;
	Word temp;
	int choice;
	if (pf == NULL) {
		fprintf(stderr, "Failed to open file \"words.txt\"\n");
		exit(EXIT_FAILURE);
	}
	InitTree(&words);
	while (fscanf(pf, "%s", temp.s) == 1)
		AddWord(&temp, &words);
	
	choice = menu();
	while (choice > 0 && choice <= 2) {
		switch (choice) {
			case 1:
				displayTree(&words);
				break;
			case 2:
				findWord(&words);
				break;
			default:
				fprintf(stderr,"I shouldn't be here\n");
				exit(EXIT_FAILURE);
		}
		choice = menu();
	}
	DeleteTree(&words);
	fclose(pf);

	return 0;
}

int menu(void)
{
	int choice;
	puts("1) Display all words\n2) Check word\n3) Exit");
	fprintf(stdout, "Your choice: ");
	while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3 ) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}
	return choice;
}
void displayTree(Tree *ptree)
{
	if (EmptyTree(ptree))
		puts("Nothing to display");
	else
		Execute(ptree, displayWord);
}
void displayWord(Word word)
{
	printf("Word: %-12s amount: %d\n", word.s, word.amount);
}
void findWord(Tree *ptree)
{
	Word find;
	Node *temp;
	if (EmptyTree(ptree)) {
		puts("Empty tree");
		return;
	}
	fputs("Enter the word you are looking for: ", stdout);
	readIn(find.s, LEN);
	if ((temp = FindWord(&find, ptree)) == NULL)
		printf("%-12s not found\n", find.s);
	else
		printf("%-12s - %d\n", temp->word.s, temp->word.amount);
}
char *readIn(char *to, int n)
{
	char *result;
	char *here;
	while (getchar() != '\n'){}
	result = fgets(to, n, stdin);
	if (result) {
		here = strchr(to, '\n');
		if (here)
			*here = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return result;
}
