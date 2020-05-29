#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int checkIs(int *tab, int n, int index);
void showElements(int *tab, size_t size, int n);

int main(int argc, char **argv)
{
	srand(time(NULL));
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	showElements(array, sizeof(array), 5);	

	return 0;
}
int checkIs(int *tab, int n, int index)
{
	for(int i = 0; i < n; i++) {
		if (*(tab + i) == index)
		      return 1;
	}
	return 0;	
}

void showElements(int *tab, size_t size, int n)
{
	int elements = size/sizeof(int);
	int index;
	int *arrayIndex = malloc(size);
	int count = 0;
	
	for(int i = 0; i < n && count < elements;) {
		index = rand() % elements;
		if (!checkIs(arrayIndex, count, index)) {
			*(arrayIndex + count) = index;
			printf("Array[%d] = %d\n", index, *(tab + index));
			i++;
			count++;
		}
	}
}
