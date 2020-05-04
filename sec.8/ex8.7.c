#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define wage_1 35
#define wage_2 37
#define wage_3 40
#define wage_4 45
#define extra 1.5
#define first 0.15
#define second 0.2
#define third 0.25

void menu(void)
{
	puts("************************************************************");
	printf("How much do you earn per hour?\n");
	printf("A) %d $/hour\t\tB) %d $/hour\n", wage_1, wage_2);
	printf("C) %d $/hour\t\tD) %d $/hours\nQ) Exit\n", wage_3, wage_4);
	puts("************************************************************");
}

int getFirst(void)
{
	int ch = getchar();

	while (!isalpha(ch)) {
		while (getchar() != '\n') {}
		puts("Enter a letter, please:");
		ch = getchar();
	}

	while (getchar() != '\n') {}
	
	return toupper(ch);
}

void calculate(uint16_t wage)
{
	uint8_t hours = 0;
	uint16_t salary = 0;
	float tax = 0;

	puts("How many hours have you worked?");
	while (scanf("%hhu", &hours) != 1) {
		puts("Wrong input, try again");
		while (getchar() != '\n'){}
	}
	while (getchar() != '\n'){}

	if (hours <= 40) {
		salary = hours * wage;
		if (salary <= 1200) {
			tax = salary * first;
		} else if (salary  > 1200 && salary <= 1800) {
			tax = 1200 * first + (salary - 1200)*second;
		} else {
			tax = (1200 * first) + (600 * second) + ((salary - 1800) * third);
		}
	} else {
		salary = (40 * wage) + ((hours - 40) * wage * extra);
		if (salary <= 1800) {
			tax = 1200 * first + (salary - 1200)*second;
		} else {
			tax = (1200 * first) + (600 * second) + ((salary - 1800) * third);
		}
	}
	
	printf("1) Gross pay: %.2u$\n2) Take-Home pay: %.2f$\n3) Tax: %.2f$\n",
		       salary, salary - tax, tax);	

}

int main(int argc, char *argv[])
{
	char choice = '\0';
	uint8_t wage = 0;

	menu();
	while (1) {
		choice = getFirst(); 
		switch (choice) {
			case 'A':
				wage = wage_1;
				break;
			case 'B':
				wage = wage_2;
				break;
			case 'C':
				wage = wage_3;
				break;
			case 'D':
				wage = wage_4;
				break;
			case 'Q':
				return 0;
			default:
				puts("Enter the letter from 'A' to 'D' or 'Q' to exit");

				continue;
		}
		calculate(wage);
		menu();
	}
	
	return 0;
}
