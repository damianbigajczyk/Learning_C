#include <stdio.h>
#include "function.h"

int main(int argc, char **argv)
{
	printf("%c\n", turn('O', 3));
	printf("%c\n", turn('T', 4));
	printf("%c\n", turn('T', 8));

	return 0;
}
