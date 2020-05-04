#include <stdio.h>
#include <stdlib.h>
#include "pex12_7.h"

static int times;
static int wall;
static int dice;

void clearBuff(void)
{
	while(getchar() != '\n') {}
}

int getData(void)
{
	fputs("Enter an amount of timess: ", stdout);
	while(scanf("%d", &times) != 1) {
		puts("Wrong input, try again!");
		clearBuff();
	}
	if(times == -1)
		return -1;

	fputs("How many walls and dices: ", stdout);
	while(scanf("%d %d", &wall, &dice) != 2) {
		puts("Wrong input, try again!");
		clearBuff();
	}
	
	return 0;
}

void count(void)
{
	int sum = 0;
	while(times) {
		for(int i = 0; i < dice; i++)
			sum += ((rand() % wall) + 1);
		printf("%d\t", sum);
		sum = 0;
		times--;
	}
	putchar('\n');

}
