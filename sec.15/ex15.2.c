#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char **argv)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: %s <bin1> <bin2> <mode>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	bitwiseOp(argv[1], argv[2], argv[3][0]);

	return 0;
}
