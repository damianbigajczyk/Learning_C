#include <stdio.h>

int main(int argc, char *argv[])
{
	float number = 1;

	while (number) {
		printf("Enter a number, please (0 - the end):\n");
		while (scanf("%f", &number) != 1) {
			printf("Wrong input, try again!\n");
			while (getchar() != '\n') {}
		}
		printf("Your number is %f\t%e\t%a\n", number, number, number);
	}
	
	return 0;
}
