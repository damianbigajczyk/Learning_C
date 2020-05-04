#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char name[10];
	char surname[20];

	printf("Hi!, what is your name?\n");
	scanf("%s", name);

	printf("Nice to meet you %s!\nWhat is your surname?\n", name);
	scanf("%s", surname);
	putchar('\n');

	printf("%10s %20s\n%10ld %20ld\n\n", name, surname, strlen(name), strlen(surname));
	printf("%-10s %-20s\n%-10ld %-20ld\n", name, surname, strlen(name), strlen(surname));

	return 0;
}
