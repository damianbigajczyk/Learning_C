#include <stdio.h>

void show(char ch, int column, int row)
{
	for(int i = 0; i < row; i++) {
	       for(int j = 0; j < column; j++)
		       putchar(ch);
	       putchar('\n');
	}
}

int main(int argc, char **argv)
{
	show('#', 10, 5);	

	return 0;
}
