#include <stdio.h>

double findValue(double *tab, int size)
{
	double largest = *tab;
	int i = 0;
	for(i = 1; i < size - 1; i++) {
		if (*(tab + i) > largest)
			largest = *(tab + i);
	}
	return largest;
}

int main(int argc, char *argv[])
{
	double array[5] = {5, 2.1, 9.8, 8, 7};

	printf("The largest value is: %.1f\n", findValue(array, 5));


	return 0;
}


