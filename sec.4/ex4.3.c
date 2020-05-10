#include <stdio.h>

int main(int argc, char *argv[])
{
	float number = 0;

	printf("Enter a number, please\n");
	while (scanf("%f", &number) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	printf("a) Entered number: %0.1f = %0.1e\n", number, number);
	printf("b) Entered number: %+0.3f = %#1.3E\n", number, number);

	return 0;
}
