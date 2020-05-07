#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	char month[10];

	getMonth(month);
	printf("%d\n", getDays(month));

	return 0;
}
