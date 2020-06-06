#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 45

struct movie {
	char title[SIZE];
	int rating;
	struct movie *next;
};

char *readIn(char *to, int n);
void showListReverse(struct movie *head);
void showList(struct movie *head);

int main(int argc, char **argv)
{
	struct movie *head = NULL;
	struct movie *previous, *temp;
	char input[SIZE];
	puts("Enter the first title of movie:");
	while (readIn(input, SIZE) != NULL && input[0] != '\0') {
		temp = (struct movie *) malloc(sizeof(struct movie));
		if (head == NULL)
			head = temp;
		else
			previous->next = temp;
		temp->next = NULL;
		strcpy(temp->title, input);
		fputs("Enter your assessment: ", stdout);
		scanf("%d", &temp->rating);	
		while (getchar() != '\n') {}
		puts("Enter next title of movie or press [enter] to end");
		previous = temp;

	}
	showList(head);
	puts("Free memory...");
	temp = head;
	while (temp != NULL) {
		previous = temp;
		temp = previous->next;
		free(previous);
	}
	puts("See you!");

	return 0;
}
char *readIn(char *to, int n)
{
	char *result = NULL;
	char *here = NULL;

	result = fgets(to, n, stdin);
	if (result) {
		here = strchr(to, '\n');
		if (here)
			*here = '\0';
		else
			while (getchar() != '\n') {}
	}
	return result;
}
void showListReverse(struct movie *head)
{
	static int i = 1;
	if (head->next != NULL)
		showListReverse(head->next);

	printf("%d) Movie: %s Rating: %d\n", i++, head->title, head->rating);
}
void showList(struct movie *head)
{
	static int i = 1;
	struct movie *temp;
	if (head == NULL) {
		puts("No data entered");
		return;
	}

	puts("This is a list of your movies:");
	temp = head;
	while (temp != NULL) {
		printf("%d) Movie: %s Rating: %d\n", i++, temp->title, temp->rating);
		temp = temp->next;
	}
	puts("\n\nThis is a list in reverse mode:");
	temp = head;
	showListReverse(temp);
}
