#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	int array[] = {3, 5, 2, 8, 4};

	printf("The different is equal to: %d\n", diff(array, sizeof(array)/sizeof(int)));

	return 0;
}
