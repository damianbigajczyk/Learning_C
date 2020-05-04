#include <stdio.h>

#define LEN 10

int main(int argc, char *argv[])
{
	char name[LEN];
	char surname[LEN];

	printf("What is your name?\n");
	scanf("%s", name);

	printf("What is your surname?\n");
	scanf("%s", surname);

	printf("Your personal data is: %s, %s.\n", surname, name);

	return 0;
}
