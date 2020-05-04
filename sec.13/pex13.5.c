#include <stdio.h>
#include <stdlib.h>
#include "pex13_5.h"

void add(FILE *source, FILE *destiny)
{
	size_t bytes;
	static char temp[size_BUF];
	while ((bytes = fread(temp, sizeof(char), size_BUF, source)) > 0)
		fwrite(temp, sizeof(char), size_BUF, destiny);
}

