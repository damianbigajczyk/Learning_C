#include <stdio.h>
#include <stdint.h>

#define watermelon 1.25
#define beetroot 0.65
#define onion 0.89

void clear()
{
	while (getchar() != '\n') {}
}

void menu(void)
{
	puts("************************");
	puts("     Choose to order:");
	puts("A) Watermelon\t\tB) Beetroot\nC) Onion\t\tK) Order");
	puts("************************");
}

float add(float price, uint8_t kg)
{
	return price * kg;
}

void calculate(float price, float weight)
{
	const float discount = 0.05;

	price = (price > 100) ? price - discount * price : price;

	if (weight <= 5) {
		price += 3.5;
	}else if (weight > 5 && weight <= 20) {
		price += 10;
	} else {
		price += 8 + (weight - 20) * 0.1;
	}

	printf("You have to pay: %.2f$\n", price);
}

int main(int argc, char *argv[])
{
	float price = 0;
	float weight = 0;
	char ch = '\0';

	menu();
	while (1) {
		ch = getchar();
		clear();

		switch (ch) {
			case 'A':
				puts("How many kilos do you need?");
				while(scanf("%f", &weight) != 1) {
					clear();
					puts("Wrong input, try again!");
				}
				price = add(watermelon, weight);
				break;
			case 'B':
				puts("How many kilos do you need?");
				while(scanf("%f", &weight) != 1) {
					clear();
					puts("Wrong input, try again!");
				}
				price = add(beetroot, weight);
				break;
			case 'C':
				puts("How many kilos do you need?");
				while(scanf("%f", &weight) != 1) {
					clear();
					puts("Wrong input, try again!");
				}
				price = add(onion, weight);
				break;
			case 'K':
				calculate(price, weight);
				puts("Bye!!!");
				return 0;
			default:
				puts("Enter A, B, C or K.");
				continue;
		}
		menu();
	}

	return 0;
}
