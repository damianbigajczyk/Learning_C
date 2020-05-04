#include <stdio.h>

void printArray(double array[], int n)
{
	for(int i = 0; i < n; i++){
		printf("The value of array[%d] = %.1f\n", i, *(array + i));
	}
	printf("\n");
}

void copy_array(double source[], double destiny[], int n)
{
	for(int i = 0; i < n; i++) {
		destiny[i] = source[i];
	}
}

void copy_p(double *source, double *destiny, int size)
{
	for(int i = 0; i < size; i++) {
		*(destiny + i) = *(source + i);
	}
}

void copy_p2(double *source, double *destiny, double *end)
{
	while (source < end) {
		*destiny = *source;
		destiny++;
		source++;
	}
}

int main(int argc, char* argv[])
{
	double source[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double dest_1[5];
	double dest_2[5];
	double dest_3[5];
	
	printArray(source, 5);
	printArray(dest_1, 5);

	copy_array(source, dest_1, 5);

	printArray(dest_1, 5);
	copy_p(source, dest_2, 5);
	printArray(dest_2, 5);
	copy_p2(source, dest_3, source + 5);
	printArray(dest_3, 5);
	return 0;
}
