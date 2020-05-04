#include <stdio.h>

int function(void)
{
	static int n;
	int x;

	printf("check %d\t%d\n", n, x);
	return ++n;
}

int main(int argc, char *argv[])
{
	int i = 5;
	int n = 0;

	while (i-- > 0)
		n = function();	
	printf("%d\n", n);
	return 0;
}
