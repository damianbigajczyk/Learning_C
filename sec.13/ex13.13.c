#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define ROW 20
#define COLUMN 30

int round_1(float a)
{
	int b = a;
	return (a - b >= 0.5) ? b+1 : b;
}

bool check(int a, int b)
{
	int c = a - b;
	return (c * c > 1) ? true : false;
}

int upgrade(int tab[ROW][COLUMN])
{
	FILE *pf_upgrade = NULL;
	FILE *pf_upgradeSign = NULL;
	char sign[ROW][COLUMN+1];
	int i = 0;
	int j = 0;

	if (!(pf_upgrade = fopen("uppgrade.txt", "w+"))) {
		fprintf(stderr, "Failed to open file: \"upgrade.txt\"\n");
		return -1;
	}
	if (!(pf_upgradeSign = fopen("uppgradeSign.txt", "w+"))) {
		fprintf(stderr, "Failed to open file: \"upgradeSign.txt\"\n");
		return -1;
	}

	int (* copy)[COLUMN];
	copy = (int (*)[COLUMN]) malloc(ROW * COLUMN * sizeof(int));

	if (check(tab[0][0], tab[0][1]) || check(tab[0][0], tab[1][0]))
		copy[0][0] = round_1((float)(tab[0][1] + tab[1][0]) / 2);
	else
		copy[0][0] = tab[0][0];

	if (check(tab[0][COLUMN-1], tab[0][COLUMN-2]) || check(tab[0][COLUMN-1], tab[1][COLUMN-1]))
		copy[0][COLUMN-1] = round_1((float)(tab[0][COLUMN-2] + tab[1][COLUMN-1]) / 2);
	else
		copy[0][COLUMN-1] = tab[0][COLUMN-1];
	
	if (check(tab[ROW-1][0], tab[ROW-1][1]) || check(tab[ROW-1][0], tab[ROW-2][0]))
		copy[ROW-1][0] = round_1((float)(tab[ROW-1][1] + tab[ROW-2][0]) / 2);
	else
		copy[ROW-1][0] = tab[ROW-1][0];

	if(check(tab[ROW-1][COLUMN-1], tab[ROW-1][COLUMN-2]) || check(tab[ROW-1][COLUMN-1], tab[ROW-2][COLUMN-1]))
		copy[ROW-1][COLUMN-1] = round_1((float)(tab[ROW-1][COLUMN-2] + tab[ROW-2][COLUMN-1]) / 2);
	else
		copy[ROW-1][COLUMN-1] = tab[ROW-1][COLUMN-1];

	//check the upside
	for(j = 1; j < COLUMN-1; j++) {
		if (check(tab[0][j], tab[0][j-1]) || check(tab[0][j], tab[0][j+1]) || check(tab[0][j], tab[1][j]))
			copy[0][j] = round_1((float)(tab[0][j-1] + tab[0][j+1] + tab[1][j]) / 3);
		else
			copy[0][j] = tab[0][j];
	}
	//check the bottom side
	for(j = 1; j < COLUMN-1; j++) {
		if (check(tab[ROW-1][j], tab[ROW-1][j-1]) || check(tab[ROW-1][j], tab[ROW-1][j+1]) || 
				check(tab[ROW-1][j], tab[ROW-2][j]))
			copy[ROW-1][j] = round_1((float)(tab[ROW-1][j-1] + tab[ROW-1][j+1] + tab[ROW-2][j]) / 3);
		else
			copy[ROW-1][j] = tab[ROW-1][j];
	}
	//check the left side
	for(i = 1; i < ROW-1; i++) {
		if (check(tab[i][0], tab[i-1][0]) || check(tab[i][0], tab[i+1][0]) || 
				check(tab[i][0], tab[i][1]))
			copy[i][0] = round_1((float)(tab[i-1][0] + tab[i+1][0] + tab[i][1]) / 3);
		else
			copy[i][0] = tab[i][0];
	}
	//check the right side
	for(i = 1; i < ROW-1; i++) {
		if (check(tab[i][COLUMN-1], tab[i-1][COLUMN-1]) || check(tab[i][COLUMN-1], tab[i+1][COLUMN-1]) || 
				check(tab[i][COLUMN-1], tab[i][COLUMN-2]))
			copy[i][COLUMN-1] = round_1((float)(tab[i-1][COLUMN-1] + tab[i+1][COLUMN-1] + 
						tab[i][COLUMN-2]) / 3);
		else
			copy[i][COLUMN-1] = tab[i][COLUMN-1];
	}
	//check the inside
	for(i = 1; i < ROW-1; i++)
		for(j = 1; j < COLUMN-1; j++) {
			if (check(tab[i][j], tab[i][j-1]) || check(tab[i][j], tab[i-1][j]) || 
					check(tab[i][j], tab[i][j+1]) || check(tab[i][j], tab[i+1][j]))
				copy[i][j] = round_1((float)(tab[i][j-1] + tab[i-1][j] + tab[i][j+1] + 
							tab[i+1][j]) / 4);
			else
				copy[i][j] = tab[i][j];
		}
	for(i = 0; i < ROW; i++) {
		for(j = 0; j < COLUMN; j++)
			fprintf(pf_upgrade, "%d ", copy[i][j]);
		fputc('\n', pf_upgrade);
	}
	for(i = 0; i < ROW; i++) {
		for(j = 0; j < COLUMN; j++) {
			switch(copy[i][j] - 48) {
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
	for(i = 0; i < ROW; i++)
		fprintf(pf_upgradeSign, "%s\n", sign[i]);
	free(copy);
	fclose(pf_upgrade);
	fclose(pf_upgradeSign);
	return 0;
}

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
	upgrade(number);
	
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
