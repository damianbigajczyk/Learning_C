#include <stdio.h>
#include <stdint.h>

#define rate 0.08

int main(int argc, char *argv[])
{
	float  money = 1000000;
	uint16_t year = 1;

	while (money > 100000) {
		money -= 100000;
		money += (money * rate);
		printf("After %d years he has %.3f$ left\n", year++, money);
	}	

	printf("After %d years he will withdraw his last money: %.3f$\n", year, money);

	return 0;
}
