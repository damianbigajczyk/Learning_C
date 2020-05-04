#include <stdio.h>
#include <ctype.h>

#define sizeArray 7

void readWord(char *argv, int size, int n)
{
	while (isspace(*argv = getchar()))
		continue;
	while (!(isspace(*argv)) && (--size > 0) && (--n >= 0))
		*(++argv) = getchar();
	while (*argv != '\n') {
		*argv = getchar();
		continue;
	}
	*(argv) = '\0';
}

int main()
{
	char array[sizeArray];

	readWord(array,7,6);
	puts(array);

	return 0;
}
