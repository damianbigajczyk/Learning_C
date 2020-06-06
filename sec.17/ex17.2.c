#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_1.h"

void showMovie(Movie object);
char *readIn(char *to, int n);

int main(int argc, char **argv)
{
	List movies;
	Movie temp;

	InitList(&movies);
	if (FullList(&movies)) {
		fprintf(stderr, "Out of memory !\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter first title of movie:");
	while (readIn(temp.title, TITLE) != NULL && temp.title[0] != '\0') {
		puts("Enter your assessment:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddMovie(temp, &movies) == false) {
			fprintf(stderr, "Error memory allocation\n");
			break;
		}
		if (FullList(&movies)) {
			puts("The list if full");
			break;
		}
		puts("Enter the next title of movie or press [Enter] to finished");
	}	

	if (EmptyList(&movies))
		puts("Nothing has been entered");
	else {
		puts("This is the list of movies:");
		Pass(&movies, showMovie);
	}

	printf("You have entered %d movies\n", CountItems(&movies));

	ClearList(&movies);
	puts("See you!");

	return 0;
error:
	return -1;
}
void showMovie(Movie item)
{
	printf("Movie: %s Rating: %d\n", item.title, item.rating);
}
char *readIn(char *to, int n)
{
	char *result;
	char *here;
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
