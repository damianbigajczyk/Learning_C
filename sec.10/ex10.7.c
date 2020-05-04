#include <stdio.h>

void copy_p(const float *source, float *destiny, int size)
{
	for(int i = 0; i < size; i++) {
		*(destiny + i) = *(source + i);
	}
}

int main(int argc, char* argv[])
{

	const float rain[][12] =
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	printf("%ld\t%ld\t%ld\n", sizeof(rain), sizeof(float), sizeof(rain)/sizeof(float));
	float array[5][12];

	for(int i = 0; i < 5; i++) {
	       for(int j = 0; j < 12; j++)
			printf("%.2f\t", rain[i][j]);
	       putchar('\n');
	}	       
	putchar('\n');

	for(int i = 0; i < 5; i++)
		copy_p(rain[i], array[i], 12);

	for(int i = 0; i < 5; i++) {
	       for(int j = 0; j < 12; j++)
			printf("%.2f\t", array[i][j]);
	       putchar('\n');
	}	       


	return 0;
}
