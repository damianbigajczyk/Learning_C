#include <stdio.h>
#include "function.h"


int main(int argc, char **argv)
{
	char *x1 = "01001001";
	char *x2 = "1110001110001000";
	char *x3 = "10000000000000000000000000000000";
	char *x4 = "100000000000000000000000000000000000";

	printf("%d\n\n", convertBin(x1));
	printf("%d\n\n", convertBin(x2));
	printf("%d\n\n", convertBin(x3));
	printf("%d\n\n", convertBin(x4));


	return 0;
}

