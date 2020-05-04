#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

int main(int argc, char **argv)
{
	FILE *pf = NULL;
	char tempString[MAX];
	int i = 1;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <string> <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (!(pf = fopen(argv[2], "r"))) {
		fprintf(stderr, "Failed to open file: \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(tempString, MAX, pf)) {
		if (strstr(tempString, argv[1]))
			fprintf(stdout, "line %d: %s\n", i, tempString);
		memset(tempString, '\0', MAX);
		i++;
	}
	if (fclose(pf))
		fprintf(stderr, "Failed to close file: \"%s\"\n", argv[2]);

	return 0;
}
