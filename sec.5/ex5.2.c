#include <stdio.h>

int main(int argc, char *argv[])
{
	int number = 0;
	int i = 11;

	printf("Enter a integer, please:\n");

	while (scanf("%d", &number) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}

	while (i--)
		printf("%d\t", number++);
	putchar('\n');

	return 0;
}
