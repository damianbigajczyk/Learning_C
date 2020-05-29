#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(double period)
{
	double end = 0;
	clock_t start = clock();

	while (end < period)
	{
		end = ((double)(clock() - start)) / CLOCKS_PER_SEC;
	}
	printf("End: %.2f sek\n", end);
}

int main(int argc, char **argv)
{
	check(argc > 1, "Usage: %s <period>", argv[0]);

	float time = atof(argv[1]);
	
	printf("Wait for %.2f sek\n", time);
	wait(time);
	puts("The end");

	return 0;
error:
	return -1;
}
