#include <stdio.h>

void getNumbers(double (*tab)[5], int rows)
{
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < 5; j++)
			scanf("%lf", &tab[i][j]); 
}
void rowAvg(double (*tab)[5], int rows)
{
	double sum = 0;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
			sum += tab[i][j];
		printf("%d) %.2f\t", i+1, sum/5);
		sum = 0;
	}
	putchar('\n');
}
double avg(double (*tab)[5], int rows)
{
	double sum = 0;
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < 5; j++)
			sum += tab[i][j];
	return sum/15;
}
double find(double (*tab)[5], int rows)
{
	double largest = 0;
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < 5; j++)
			largest = (largest < tab[i][j]) ? tab[i][j] : largest;
	return largest;
}
void show(double (*tab)[5], int rows)
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
			printf("%.2f\t", tab[i][j]);
		putchar('\n');
	}
}
int main(int argc, char *argv[])
{
	double numbers[3][5];
	getNumbers(numbers, 3);
	show(numbers,3);
	rowAvg(numbers, 3);
	printf("%.2f\n", avg(numbers, 3));
	printf("%.2f\n", find(numbers, 3));

	return 0;
}
