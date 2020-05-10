#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char name[10];
	char surname[20];

	printf("Hi!, what is your name?\n");
	while (scanf("%s", name) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	printf("Nice to meet you %s!\nWhat is your surname?\n", name);
	while (scanf("%s", surname) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}
	putchar('\n');

	printf("%10s %20s\n%10ld %20ld\n\n", name, surname, strlen(name), strlen(surname));
	printf("%-10s %-20s\n%-10ld %-20ld\n", name, surname, strlen(name), strlen(surname));

	return 0;
}
