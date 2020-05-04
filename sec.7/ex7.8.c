#include <stdio.h>
#include <stdint.h>

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
	printf("1) %d $/hour\t\t2) %d $/hour\n", wage_1, wage_2);
	printf("3) %d $/hour\t\t4) %d $/hours\n5) Exit\n", wage_3, wage_4);
	puts("************************************************************");
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
	uint8_t choice = 0;
	uint8_t wage = 0;

	menu();
	while (1) {
		scanf("%hhu", &choice);	
		switch (choice) {
			case 1:
				wage = wage_1;
				break;
			case 2:
				wage = wage_2;
				break;
			case 3:
				wage = wage_3;
				break;
			case 4:
				wage = wage_4;
				break;
			case 5:
				return 0;
			default:
				puts("Enter the number from 1 to 5,please");
				while(getchar() != '\n'){}

				continue;
		}
		calculate(wage);
		menu();
	}
	
	return 0;
}

