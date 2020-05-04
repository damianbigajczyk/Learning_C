#include <stdio.h>

void copy(double (*source)[5], int rows, double(*destiny)[5])
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
			*(*(destiny + i) + j) = source[i][j];
	}
}
void show(double (*tab)[5], int rows)
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
			printf("%.2f\t", tab[i][j]);
		putchar('\n');
	}
}

int main(int argc, char *argv[])
{
	double rain[][5] = {
		{2.8, 4.5, 2.3, 6.9, 8.0},
		{2.3, 9.4, 5.0, 8.2, 1.6},
		{2.4, 9.6, 4.6, 7.3, 2.5}
	};
	double array[3][5];

	show(rain, 3);
	putchar('\n');
	show(array, 3);
	putchar('\n');

	copy(rain, 3, array);
	show(array, 3);

	return 0;
}
