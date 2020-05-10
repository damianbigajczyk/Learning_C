#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	double numbers[3][5];

	getNumbers(numbers, 3);
	showArray_2(numbers,3);
	rowAvg(numbers, 3);
	printf("%.2f\n", avg(numbers, 3));
	printf("%.2f\n", findLargest(numbers, 3));

	return 0;
}
