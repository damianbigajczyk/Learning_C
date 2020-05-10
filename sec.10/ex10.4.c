#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	double array[] = {2, 2.9, 3.5, 3.7, 1};

	printf("Index of the largest value is: %d\n", findIndex(array, sizeof(array)/sizeof(double)));

	return 0;
}
