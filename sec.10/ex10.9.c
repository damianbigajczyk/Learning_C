#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	double rain[][5] = {
		{2.8, 4.5, 2.3, 6.9, 8.0},
		{2.3, 9.4, 5.0, 8.2, 1.6},
		{2.4, 9.6, 4.6, 7.3, 2.5}
	};
	double array[3][5];

	showArray_2(rain, 3);
	putchar('\n');

	showArray_2(array, 3);
	putchar('\n');

	cpyArray_4(rain, 3, array);
	showArray_2(array, 3);

	return 0;
}
