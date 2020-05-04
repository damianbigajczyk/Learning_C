#include <stdio.h>

#define s 3.156e7

int main(int argc, char *argv[])
{
	int age = 0;

	printf("How old are you? (0 - the end)\n");
	while (scanf("%d", &age) != 1) {
		printf("Wrong input, try again!\n");
		while (getchar() != '\n') {}
	}

	while (age) {
		printf("You have been living for %lf seconds\n", age * s);
		printf("How old are you? (0 - the end)\n");
		while (scanf("%d", &age) != 1) {
			printf("Wrong input, try again!\n");
			while (getchar() != '\n') {}
		}
	}

	return 0;
}
