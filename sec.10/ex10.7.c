#include <stdio.h>
#include "function.h"

int main(int argc, char* argv[])
{
	double array[5][12];

	printf("%ld\t%ld\t%ld\n", sizeof(rain), sizeof(float), sizeof(rain)/sizeof(float));

	for(int i = 0; i < 5; i++) {
	       for(int j = 0; j < 12; j++)
			printf("%.2f\t", rain[i][j]);
	       putchar('\n');
	}	       
	putchar('\n');

	for(int i = 0; i < 5; i++)
		cpyArray_2(rain[i], array[i], 12);

	for(int i = 0; i < 5; i++) {
	       for(int j = 0; j < 12; j++)
			printf("%.2f\t", array[i][j]);
	       putchar('\n');
	}	       


	return 0;
}
