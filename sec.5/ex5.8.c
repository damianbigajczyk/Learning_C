#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	uint16_t devisor = 1;
	uint32_t divident = 0;

	puts("Enter a divisor, please:");	
	while ((scanf("%hu", &devisor) != 1) || (!devisor)) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}

	puts("Enter a divident, please:");
	while (scanf("%u", &divident) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}

	while (divident) {
		printf("%u %% %hu is equal to %u.\n", divident, devisor, divident % devisor);
		puts("Enter a divident, please: (0 - the end)");
		while (scanf("%u", &divident) != 1) {
			puts("Wrong input, try again!");
			while (getchar() != '\n')
				continue;
		}
	}
	puts("The end");

	return 0;
}
