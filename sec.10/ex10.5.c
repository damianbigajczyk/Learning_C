#include <stdio.h>

int diff(int *array, int size)
{
	int smallest = *array;
	int largest = *array;
	int i = 1;
	for(i = 1; i < size -1; i++) {
		if (*(array + i) < smallest)
			smallest = *(array + i);
	}
	for(i = 1; i < size -1; i++) {
		if (*(array + i) > largest)
			largest = *(array + i);
	}

	return largest - smallest;
}

int main(int argc, char *argv[])
{
	int array[] = {3, 5, 2, 8, 4};

	printf("The different is equal to: %d\n", diff(array, sizeof(array)/sizeof(int)));

	return 0;
}
