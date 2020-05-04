#include <stdio.h>

void addArray(int *tab_1, int *tab_2, int *tab_3, int n_1, int n_2, int n_3)
{
	int min = n_1 > n_2 ? n_2 : n_1;
	min = min > n_3 ? n_3 : min;

	for(int i = 0; i < min; i++)
		*(tab_3 + i) = *(tab_1 + i) + *(tab_2 + i);
}

void show(int *tab, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d\t", *(tab + i));
	putchar('\n');
}

int main(int argc, char *argv[])
{
	int array_1[] = {2, 4, 5, 8};
	int array_2[] = {1, 0, 4, 6};
	int array_3[4];

	addArray(array_1, array_2, array_3, 4, 4, 4);
	show(array_3, 4);


	return 0;
}

