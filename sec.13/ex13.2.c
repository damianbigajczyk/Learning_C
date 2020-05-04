#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *f_s = NULL;
	FILE *f_d = NULL;
	int ch = 0;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <source> <destiny>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((f_s = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Failed to open file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((f_d = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "Failed to open file \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(f_s)) != EOF)
		fputc(ch, f_d);

	if (fclose(f_s))
		fprintf(stderr, "Failed to close file \"%s\"\n", argv[1]);

	if (fclose(f_d))
		fprintf(stderr, "Failed to close file \"%s\"\n", argv[2]);

	return 0;
}
