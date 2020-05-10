#include <stdio.h>
#include "function.h"

int main(int argc, char **argv)
{
	double array_1[] = {1, 2, 3, 4, 5, 6, 7};
	double array_2[3];
	
	showArray_1(array_1, sizeof(array_1)/sizeof(double));
	showArray_1(array_2, sizeof(array_2)/sizeof(double));

	cpyArray_3(array_1 + 2, array_2, array_1 + 5);

	showArray_1(array_1, sizeof(array_1)/sizeof(double));
	showArray_1(array_2, sizeof(array_2)/sizeof(double));

	return 0;
}
