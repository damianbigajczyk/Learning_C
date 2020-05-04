#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *pf = NULL;
	char ch = '\0';
	int counter = 0;
	int i = 2;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <sign> <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (argc == 2) {
		fputs("Enter the data (# - the end):\n", stdout);
		while ((ch = getchar()) != '#')
			if (ch == argv[1][0])
				counter++;
		fprintf(stdout, "stdin contains '%c' %d times\n", argv[1][0], counter);
		return 0;
	} else {
		while (argc - i) {
			if (!(pf = fopen(argv[i], "r"))) {
				fprintf(stderr, "Failed to opend file \"%s\"\n", argv[i]);
				i++;
				continue;
			}
			while ((ch = fgetc(pf)) != EOF)
				if (ch == argv[1][0])
					counter++;
			fprintf(stdout, "The file: \"%s\" contains '%c' %d times\n",
					argv[i], argv[1][0], counter);
			if (fclose(pf))
				fprintf(stderr, "Failed to close file: \"%s\"\n", argv[i]);

			i++;
			counter = 0;
		}
	}

	return 0;
}
