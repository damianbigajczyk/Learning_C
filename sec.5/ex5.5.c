#include <stdio.h>

int main(int argc, char *argv[])
{
	int days = 0;
	int counter = 0;
	int sum = 0;

	puts("Hi, enter a days, please:");
	while (scanf("%d", &days) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n')
			continue;
	}

	while (counter++ < days)
		sum += counter;

	printf("You will earn %d$ in %d days\n", sum, days);

	return 0;
}
