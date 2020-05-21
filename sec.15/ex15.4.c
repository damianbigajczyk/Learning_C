#include <stdio.h>
#include "function.h"

int main(int argc, char **argv)
{

	printf("%d\n", getBit(5, 0));
	printf("%d\n", getBit(5, 1));
	printf("%d\n", getBit(5, 2));
	printf("%d\n", getBit(5, 3));
	printf("%d\n", getBit(5, 4));
	putchar('\n');
	printf("%d\n", getBit(-47, 0));
	printf("%d\n", getBit(-47, 1));
	printf("%d\n", getBit(-47, 2));
	printf("%d\n", getBit(-47, 3));
	printf("%d\n", getBit(-47, 4));

	return 0;
}
