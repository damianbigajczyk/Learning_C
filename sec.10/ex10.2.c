#include <stdio.h>
#include "function.h"

int main(int argc, char* argv[])
{
	double source[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double dest_1[5];
	double dest_2[5];
	double dest_3[5];
	
	printArray(source, 5);
	printArray(dest_1, 5);

	cpyArray_1(source, dest_1, 5);
	printArray(dest_1, 5);

	cpyArray_2(source, dest_2, 5);
	printArray(dest_2, 5);

	cpyArray_3(source, dest_3, source + 5);
	printArray(dest_3, 5);

	return 0;
}
