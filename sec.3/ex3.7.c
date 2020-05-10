#include <stdio.h>
#include <stdint.h>

#define inch 2.54

int main(int argc, char *argv[])
{
	uint16_t height = 0;

	printf("Enter your height in centimeters, please (0 - the end)\n");
	while (scanf("%hd", &height) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}

	while (height) {
		printf("Your height is %hd which is equal to %.2f inches\n", height, height / inch);
		printf("Enter your height in centimeters, please (0 - the end)\n");
		while (scanf("%hd", &height) != 1) {
			puts("Wrong input, try again!");
			while (getchar() != '\n') {}
		}
	}

	return 0;
}
