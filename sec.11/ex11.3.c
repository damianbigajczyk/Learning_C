#include <stdio.h>

void readWord(char *argv)
{
	char ch = '\0';

	ch = getchar();
	while (ch == '\n' || ch == '\t' || ch == ' ' ) {
		ch = getchar();
	}
	while (ch != '\n' && ch != '\t' && ch != ' ') {
		*argv = ch;
		(*++argv) = '\0';
		ch = getchar();
	}
	while (getchar() != '\n')
		continue;

}

int main()
{
	char array[7];

	readWord(array);
	puts(array);

	return 0;
}
