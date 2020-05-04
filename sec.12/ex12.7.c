#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pex12_7.h"

int main(int argc, char* argv[])
{
	int rc = 0;

	srand(time(NULL));

	while (!(rc = getData()))
		count();


	return 0;
}
