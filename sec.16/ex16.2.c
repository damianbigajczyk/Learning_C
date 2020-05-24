#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>

#define H2MEAN(x,y) (2/((1/(x)) + (1/(y))))

int main(int argc, char **argv)
{
	check(argc > 2, "Usage: %s <number_1> <number_2>", argv[0]);
	printf("Harmonic mean: %.2f\n", H2MEAN( atof(argv[1]), atof(argv[2]) ));
	
	return 0;
error:
	return -1;
}
