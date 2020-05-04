#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

int getChoice(void);
float getNumber(void);

int main(int argc, char* argv[])
{

	uint8_t choice = 0;
	float a = 0;
	float b = 1;

	while ((choice = getChoice()) != '5') {
		if (!(isdigit(choice)) || choice > '5') {
			printf("Enter the number and it's must be less than 6.\n");
			continue;
		}

		switch (choice) {
			case '1':
				a = getNumber();
				b = getNumber();
				printf("Result: %f\n", a + b);
				break;
			case '2':
				a = getNumber();
				b = getNumber();
				printf("Result: %f\n", a - b);
				break;
			case '3':
				a = getNumber();
				b = getNumber();
				printf("Result: %f\n", a * b);
				break;
			case '4':
				a = getNumber();
				b = getNumber();
				while(b == 0){
					printf("It can't be 0\nTry again!\n");
					b = getNumber();
				}
				printf("Result: %f\n", a / b);
				break;
			default:
				printf("I shouldn't be here\n");
				break;
		}
	}
	puts("The end");

	return 0;
}

int getChoice(void)
{
	int ch = '\0';
	
	printf("Choose one of the following tasks:\n1) add\t\t2) subtract\n3) multiply\t4) divide\n5) End\n");

	ch = getchar();

	while (getchar() != '\n')
		continue;

	return ch;
}

float getNumber(void)
{
	float number = 0;
	char ch = 'a';
	
	fputs("Enter the number, please: ", stdout);

	while (scanf("%f", &number) != 1) 
		while ((ch = getchar()) != '\n') 
			printf("'%c' - it is not a number\nTry again!\n", ch);
	
	while (getchar() != '\n')
		continue;
	return number;
}
