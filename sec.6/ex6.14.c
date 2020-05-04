#include <stdio.h>

int main(int argc, char* argv[])
{
	double array_1[8];
	double array_2[8];
	double sum = 0;
	int i = 0;

	for(i = 0; i < 8; i++) {
		printf("Write a number in array[%d]: ", i);
		scanf("%lf", &array_1[i]);
		putchar('\n');
	}
	
	for(i = 0; i < 8; i++) {
		for(int j = 0; j<= i; j++) {
			sum += array_1[j];
		}
		array_2[i] = sum;
		sum = 0;
	}
	for(i = 0; i < 8; i++) {
		printf("%.2lf\t", array_1[i]);
	}

	printf("\n");

	for(i = 0; i < 8; i++) {
		printf("%.2lf\t", array_2[i]);
	}

	printf("\n");

	return 0;
}
