#include <stdio.h>
#include <time.h>
#include "pex12_5.h"

int main(int argc, char *argv[])
{
	int number[100];
	int i = 0;
	
	srand_1((unsigned int) time(0));

	for(i = 0; i < 100; i++) 
		number[i] = rand_1();

	bubble_sort(number, 100);

	for(i = 0; i < 100; ) {
		printf("%d\t", number[i]);
		if (!(++i % 10))
			putchar('\n');
	}

	return 0;
}
