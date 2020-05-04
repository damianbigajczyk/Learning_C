#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int showRow(FILE *pf)
{
	int ch = 0;
	while((ch = fgetc(pf)) != '\n' && (ch != EOF))
		fputc(ch, stdout);
	fputc('\n', stdout);
	return (ch == EOF)? 1 : 0;
}

int main(int argc, char **argv)
{
	FILE *pf_1 = NULL;
	FILE *pf_2 = NULL;
	bool flag1_EOF = false;
	bool flag2_EOF = false;
	int i = 1;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <file> <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (!(pf_1 = fopen(argv[1], "r"))) {
		fprintf(stderr, "Failed to open file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (!(pf_2 = fopen(argv[2], "r"))) {
		fprintf(stderr, "Failed to open file \"%s\"\n", argv[2]);
		fclose(pf_1);
		exit(EXIT_FAILURE);
	}
	while (!flag1_EOF || !flag2_EOF) {
		if (!flag1_EOF) {
			fprintf(stdout, "\"%s\": %d)", argv[1], i);
			flag1_EOF = (showRow(pf_1) == 1)? true : false;
		}
		if (!flag2_EOF) {
			fprintf(stdout, "\"%s\": %d)", argv[2], i);
			flag2_EOF = (showRow(pf_2) == 1)? true : false;
		}
		i++;
	}
	if (fclose(pf_1) || fclose(pf_2))
		puts("Failed to close files");

	return 0;
}
