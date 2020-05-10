#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	double array[] = {0.25, 0.50, 8.6, 3, 12, 7.6, 9.1};
	int i = 0;

	for(i = 0; i < sizeof(array)/sizeof(double); i++)
		printf("%.2f\t", array[i]);
	putchar('\n');

	reverse(array, sizeof(array)/sizeof(double));

	for(i = 0; i < sizeof(array)/sizeof(double); i++)
		printf("%.2f\t", array[i]);
	putchar('\n');

	return 0;
}
