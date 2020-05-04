#include <stdio.h>

void rzad_zn(char ch, int row, int column)
{
	for(int i = 0; i < row; i++) {
	       for(int j = 0; j < column; j++) {
		       putchar(ch);
		       putchar('\t');
	       }
	       putchar('\n');
	}
}

int main(int argc, char * argv[])
{
	rzad_zn('A', 5, 6);

	return 0;
}

