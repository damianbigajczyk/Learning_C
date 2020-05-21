#include <stdio.h>
#include "function.h"

int main(int argc, char **argv)
{
	printf("%d\n", countBiteOn(4));	
	printf("%d\n", countBiteOn(12));	
	printf("%d\n", countBiteOn(0));	
	printf("%d\n", countBiteOn(1023));	

	return 0;
}
