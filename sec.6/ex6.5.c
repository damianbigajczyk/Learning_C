#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int rows = 0;
	int diff = 0;
	char ch = '\0';

	fputs("Enter a letter, please: ", stdout);
	ch = getchar();
	ch = toupper(ch);
	diff = ch - 'A';

	for(rows = diff, i = 0; i <= rows; i++) {
		for(j = 0; j < diff; j++)
			putchar(' ');
		for(int k = 'A'; k <= ch - diff; k++)
			putchar(k);

		for(int k = ch - diff - 1; k >= 'A'; k--)
			putchar(k);
		diff--;
		putchar('\n');
	}


	return 0;
}
