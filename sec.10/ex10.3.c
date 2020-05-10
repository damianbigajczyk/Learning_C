#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	double array[5] = {5, 2.1, 9.8, 8, 7};

	printf("The largest value is: %.1f\n", findValue(array, 5));

	return 0;
}


