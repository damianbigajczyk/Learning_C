#include <stdio.h>
#include <stdint.h>

uint32_t findIndex(double *tab, int size)
{
	uint32_t largest = 0;
	for(int i = 1; i < size - 1; i++) {
		if (*(tab + i) > tab[largest])
			largest = i;
	}

	return largest;
}

int main(int argc, char *argv[])
{
	double array[] = {2, 2.9, 3.5, 3.7, 1};

	printf("Index of the largest value is: %d\n", findIndex(array, sizeof(array)/sizeof(double)));


	return 0;
}
