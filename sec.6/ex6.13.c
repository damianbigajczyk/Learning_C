#include <stdio.h>

#define size 8

int twoPower(int i)
{
	if (i == 0)
		return 1;
	if (i == 1)
		return 2;
	return 2 * twoPower(--i);
}
int main(int argc, char *argv[])
{
	int array[size];

	for(int i = 0; i < size; i++) {
		*(array + i) = twoPower(i);
		printf("%d\t", *(array + i));
	}
	putchar('\n');

	return 0;
}
