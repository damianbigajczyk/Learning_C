#include <stdio.h>
#include <stdint.h>

#define week 7 

int main(int argc, char *argv[])
{
	int i = 0;
	uint32_t days = 0;
	uint16_t weeks = 0;

	puts("Hi, enter an amount of days, please:");
	while (scanf("%u", &days) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}
	
	i = days;

	while (i > 6) {
		i -= week;
		weeks++;
	}

	printf("%u days is %u %s and %u %s\n", days, weeks, (weeks == 1)? "week" : "weeks", i,
			(i == 1)? "day" : "days");

	return 0;
}
