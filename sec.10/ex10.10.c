#include <stdio.h>
#include "function.h"

void show(int *tab, int n);

int main(int argc, char *argv[])
{
	int array_1[] = {2, 4, 5, 8};
	int array_2[] = {1, 0, 4, 6};
	int array_3[4];

	addArray(array_1, array_2, array_3, 4, 4, 4);
	show(array_3, 4);


	return 0;
}

void show(int *tab, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d\t", *(tab + i));
	putchar('\n');
}

