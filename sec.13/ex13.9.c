#include <stdio.h>
#include <stdlib.h>

#define MAX 41

int countWords(FILE *pf)
{
	int counter = 0;
	int ch = 0;
	
	while ((ch = fgetc(pf)) != EOF)
		if (ch == '\n')
			counter++;
	return counter;
}

int main(int argc, char *argv[])
{
	FILE *wp = NULL;
	char words[MAX];
	int i = 1;

	if ((wp = fopen("words", "a+")) == NULL) {
		fprintf(stderr, "I couldn't open a file \"words\".\n");
		exit(EXIT_FAILURE);
	}
	
	i = countWords(wp) + 1;

	puts("Enter a words which will be saved in file");
	puts("To end program enter #.");

	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(wp, "%d-%s\n", i++, words);
	puts("The file contain:");
	rewind(wp);
	while (fscanf(wp, "%s", words) == 1) {
		fputs(words, stdout);
		fputc('\n', stdout);
	}
	if (fclose(wp))
		fprintf(stderr, "Error during closing the file");

	return 0;
}
