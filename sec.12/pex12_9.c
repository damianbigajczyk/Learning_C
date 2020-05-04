#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pex12_9.h"

static int n;

void clearBuff(void)
{
	while(getchar() != '\n') {}
}

char **create_array(void)
{
	char **w_w_array = NULL;

	fputs("How many words do you want to save: ", stdout);
	while(scanf("%d", &n) != 1) {
		puts("Wrong input, try again!");
		clearBuff();
	}
	w_w_array = (char **) malloc( n * sizeof(char*));
	return w_w_array;
}

void getWord(char **w_w_array)
{
	char temp[20] = {'\0'};
	int i = 0;
	int j = 0;

	puts("Enter your words");

	while(n-i > 0) {
		while(scanf("%s", temp) != 1) {
				printf("I need %d words more:\n", n);
				clearBuff();
		}
		w_w_array[i] = (char *) malloc( (strlen(temp)+1) * sizeof(char));
		for(j = 0; temp[j] != '\0'; j++)
			w_w_array[i][j] = temp[j];
		w_w_array[i][j] = '\0';
		i++;
	}
}

void showWord(char **w_w_array)
{
	for(int i = 0; i < n; i++)
		printf("%d) %s\n", i+1, w_w_array[i]);
}

void clearMem(char **w_w_array)
{
	for(int i = 0; i < n; i++)
		free(w_w_array[i]);
	free(w_w_array);
}
