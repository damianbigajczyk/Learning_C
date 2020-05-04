#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	uint8_t number = 0;

	puts("Enter a positive number, please:");
	while (scanf("%hhu", &number) != 1) {
		puts("Wrong input, enter the number, please");
		while (getchar() != '\n') {}
	}

	if (number == 1) 
		puts("There are no Prime numbers");

	while (number > 1) {
		bool flag = true;

		if (number == 2) {
			puts("2 -> Prime number");
			break;
		}

		for(uint8_t i = 2; i < number; i++) {
			if (number % i == 0) {
				flag = false;
				break;
			}
		}

		if (flag)
			printf("%hhu -> Prime number\n", number);
		--number;
	}

	puts("The end");

	return 0;
}

