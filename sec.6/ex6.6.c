#include <stdio.h>

int main(int argc, char *argv[])
{
	int min = 0;
	int max = 0;

	puts("Enter the smallest number:");
	while (scanf("%d", &min) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	puts("Enter the largest number:");
	while (scanf("%d", &max) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	for(int i = min; i <= max; i++)
		printf("%d\t%d\t%d\n", i, i*i, i*i*i);


	return 0;
}
