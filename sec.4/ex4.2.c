#include <stdio.h>

int main(int argc, char *argv[])
{
	char name[10];

	printf("What is your name?\n");
	while (scanf("%s", name) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	printf("a) \"%s\"\n", name);
	printf("b) \"%18s\"\n", name);
	printf("c) \"%-18s\"\n", name);
	printf("d) \"%c%c%c%s\"\n", ' ', ' ', ' ', name);

	return 0;
}
