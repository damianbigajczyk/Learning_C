#include <stdio.h>

void reverse(double *tab, int n)
{
	double temp = 0;

	for(int i = 0; i < n/2; i++) {
		temp = *(tab + (n - (i+1)));
		*(tab + (n - (i+1))) = *(tab + i);
		*(tab + i) = temp;
	}
}

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
