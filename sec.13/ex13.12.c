#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROW 20
#define COLUMN 30

int main(int argc, char **argv)
{
	FILE *pf_in = NULL;
	FILE *pf_out = NULL;
	int i = 0;
	int j = 0;
	char ch = 0;
	int number[ROW][COLUMN];
	char sign[ROW][COLUMN + 1];

	srand(time(NULL));

	if (!(pf_in = fopen("numbers.txt", "w+"))) {
		fputs("Failed to open file: \"numbers.txt\"\n", stderr);
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COLUMN;) {
			fputc(rand() % 10 + 48, pf_in);
			j++;
			if (j % COLUMN)
				fputc(' ', pf_in);
			else
				fputc('\n', pf_in);
		}

	rewind(pf_in);

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COLUMN; j++) {
			ch = fgetc(pf_in);
			if(isspace(ch))
				*(*(number + i) + j) = fgetc(pf_in);
			else
				*(*(number + i) + j) = ch;
		}

	for(i = 0; i < ROW; i++) {
		for(j = 0; j < COLUMN; j++) {
			switch(number[i][j] - 48) {
				case 0:
					sign[i][j] = 32;
					break;
				case 1:
					sign[i][j] = 46;
					break;
				case 2:
					sign[i][j] = 45;
					break;
				case 3:
					sign[i][j] = 44;
					break;
				case 4:
					sign[i][j] = 34;
					break;
				case 5:
					sign[i][j] = 43;
					break;
				case 6:
					sign[i][j] = 33;
					break;
				case 7:
					sign[i][j] = 36;
					break;
				case 8:
					sign[i][j] = 37;
					break;
				case 9:
					sign[i][j] = 35;
					break;
				default:
					sign[i][j] = 101;
			}
		}
		sign[i][j] = '\0';
	}

	if ((pf_out = fopen("signs.txt", "w+"))) {
		for(i = 0; i < ROW; i++)
			fprintf(pf_out, "%s\n", sign[i]);
		if (fclose(pf_out))
			fputs("Failed to close file: \"sign.txt\"\n", stderr);
	} else 
		fputs("Failed to open file: \"signs.txt\"\n", stderr);

	if (fclose(pf_in))
		fputs("Failed to close file: \"numbers.txt\"\n", stderr);

	return 0;
}
