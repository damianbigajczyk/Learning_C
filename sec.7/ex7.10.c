#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define base 0.15
#define extra 0.28

void menu(void)
{
	puts("********************************");
	puts("Choose category:");
	puts("1) Single state\n2) Head of the family\n3) Marriage - common payoff\n4) Marriage - individual payoff");
	puts("5) Exit");
	puts("********************************");
}

void calculate(uint16_t limit)
{
	uint32_t salary = 0;
	float tax = 0;
	puts("How much have you earned?");
	while (scanf("%u", &salary) != 1) {
		puts("Wrong input, try again");
		while (getchar() != '\n'){}
	}		

	tax = ((int)salary - (int)limit <= 0) ? base * salary : base * limit + extra * (salary - limit);

	printf("You have to pay: %.2f$ for taxes\n", tax);
}

int main(int argc, char *argv[])
{
	uint16_t limit = 0;
	uint8_t choice = 0;

	menu();

	while (1) {
		scanf("%hhu", &choice);
		switch(choice) {
			case 1:
				limit = 17850;
				break;
			case 2:
				limit = 23900;
				break;
			case 3:
				limit = 29750;
				break;
			case 4:
				limit = 14875;
				break;
			case 5:
				return 0;
			default:
				puts("Enter the number from 1 to 5, please.");
				while (getchar() != '\n'){}
				continue;
		}
		calculate(limit);
		menu();
	}
	puts("The end");

	return 0;
}
