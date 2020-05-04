#include <stdio.h>
#include <stdint.h>

uint32_t sumPower(uint16_t a)
{
	if (a <= 2)
		return a * a + 1;
	return a * a + sumPower(--a);
}	

int main(int argc, char *argv[])
{
	uint16_t number = 0;

	puts("Enter a number, please:");

	while (scanf("%hu", &number) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}

	printf("You have earned %u$ during %u days\n", sumPower(number), number);

	return 0;
}
