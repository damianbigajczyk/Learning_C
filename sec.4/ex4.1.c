#include <stdio.h>

#define LEN 10

int main(int argc, char *argv[])
{
	char name[LEN];
	char surname[LEN];

	printf("What is your name?\n");
	while (scanf("%s", name) != 1) {
		puts("Wrong input, try again");
		while (getchar() != '\n') {}
	}

	printf("What is your surname?\n");
	while (scanf("%s", surname) != 1) {
		puts("Wrong input, try again");
		while (getchar() != '\n') {}
	}

	printf("Your personal data is: %s, %s.\n", surname, name);

	return 0;
}
