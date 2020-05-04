#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *f_s = NULL;
	int ch = 0;
	int i = 1;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file>...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while (argc - i) {
		if ((f_s = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "Failed to open file \"%s\"\n", argv[i]);
			i++;
			continue;
		}
		fprintf(stdout, "The file \"%s\" contains:\n", argv[i]);
		while ((ch = fgetc(f_s)) != EOF)
			fputc(ch, stdout);
		if (fclose(f_s)) {
			fprintf(stderr, "Failed to close file \"%s\"\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}


	return 0;
}
