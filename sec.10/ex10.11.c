#include <stdio.h>

void showArray(int (*tab)[5], int rows);
void raise(int (*tab)[5], int rows);

int main(int argc, char *argv[])
{
	int number[3][5] =
	{
		{3, 6, 7, 4, 3},
		{6, 4, 9 ,2, 1},
		{9, 3, 5, 1, 7}
	};

	showArray(number, 3);
	raise(number, 3);
	putchar('\n');
	showArray(number, 3);

	return 0;

}

void showArray(int (*tab)[5], int rows)
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
		       printf("%d\t", *(*(tab + i) + j));
		putchar('\n');
	}	
}

void raise(int (*tab)[5], int rows)
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
			*(*(tab + i) + j) *= 2;
	}
}
