#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pex13_5.h"

int main(int argc, char *argv[])
{
	FILE *f_d = NULL;	//file destiny
	FILE *f_s = NULL; 	//file source
	
	int files = 0;
	int ch = 0;
	int i = 1;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <destiny> <source>...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((f_d = fopen(argv[1], "a+b")) == NULL) {
		fprintf(stderr, "%s - open error\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(f_d, NULL, _IOFBF, size_BUF)) {
		fputs("Couldn't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}

	while (argc - ++i) {
		if(strcmp(argv[1], argv[i]) == 0) 
			fprintf(stderr, "The fiel \"%s\" couldn't be added to itself\n", argv[i]);
		else if ((f_s = fopen(argv[i], "rb")) == NULL)
			fprintf(stderr, "Faile to open file \"%s\"\n", argv[i]);
		else {
			if (setvbuf(f_s, NULL, _IOFBF, size_BUF)) {
				fputs("Couldn't open input buffer\n", stderr);
				continue;
			}
			add(f_s, f_d);
			if(ferror(f_s))
				fprintf(stderr, "Error to read file %s\n", argv[i]);
			if(ferror(f_d))
				fprintf(stderr, "Error to write file %s\n", argv[1]);
			fclose(f_s);
			files++;
			printf("File %s appended.\n", argv[i]);
		}
	}
	printf("Added %d files.\n", files);
	rewind(f_d);
	printf("%s contain:\n", argv[1]);
	while((ch = getc(f_d)) != EOF)
		putchar(ch);
	puts("The end");
	fclose(f_d);
	return 0;
}
