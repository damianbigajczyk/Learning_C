#include <stdio.h>
#include <stdint.h>
#include "function.h"

const double rain[][months] =
{
	{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
	{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
	{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
	{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
	{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
};

/**************** Exercise 10.2 ********************/
void printArray(const double array[], int n)
{
	for (int i = 0; i < n; i++){
		printf("The value of array[%d] = %.1f\n", i, *(array + i));
	}
	printf("\n");
}

void cpyArray_1(const double source[], double destiny[], int n)
{
	for (int i = 0; i < n; i++) {
		destiny[i] = source[i];
	}
}

void cpyArray_2(const double *source, double *destiny, int size)
{
	for (int i = 0; i < size; i++) {
		*(destiny + i) = *(source + i);
	}
}

void cpyArray_3(const double *source, double *destiny, const double *end)
{
	while (source < end) {
		*destiny = *source;
		destiny++;
		source++;
	}
}
/**************** Exercise 10.3 *********************/
double findValue(double *tab, int size)
{
	double largest = *tab;
	int i = 0;

	for (i = 1; i < size - 1; i++) {
		if (*(tab + i) > largest)
			largest = *(tab + i);
	}
	return largest;
}
/*************** Exercise 10.4 **********************/
uint32_t findIndex(double *tab, int size)
{
	uint32_t largest = 0;

	for (int i = 1; i < size - 1; i++) {
		if (*(tab + i) > tab[largest])
			largest = i;
	}

	return largest;
}
/*************** Exercise 10.5 ********************/
int diff(int *array, int size)
{
	int smallest = *array;
	int largest = *array;
	int i = 1;

	for(i = 1; i < size -1; i++) {
		if (*(array + i) < smallest)
			smallest = *(array + i);
	}
	for(i = 1; i < size -1; i++) {
		if (*(array + i) > largest)
			largest = *(array + i);
	}

	return largest - smallest;
}
/************** Exercise 10.6 *******************/
void reverse(double *tab, int n)
{
	double temp = 0;

	for(int i = 0; i < n/2; i++) {
		temp = *(tab + (n - (i+1)));
		*(tab + (n - (i+1))) = *(tab + i);
		*(tab + i) = temp;
	}
}
/************* Exercise 10.8 *******************/
void showArray_1(double *tab, int n)
{
	for(int i = 0; i < n; i++)
		printf("%lf\t", *(tab + i));
	putchar('\n');
}
/************ Exercise 10.9 *********************/
void cpyArray_4(const double (*source)[5], int rows, double(*destiny)[5])
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
			*(*(destiny + i) + j) = source[i][j];
	}
}
void showArray_2(const double (*tab)[5], int rows)
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < 5; j++)
			printf("%.2f\t", tab[i][j]);
		putchar('\n');
	}
}
/************ Exercise 10.10 *******************/
void addArray(int *tab_1, int *tab_2, int *tab_3, int n_1, int n_2, int n_3)
{
	int min = n_1 > n_2 ? n_2 : n_1;
	min = min > n_3 ? n_3 : min;

	for(int i = 0; i < min; i++)
		*(tab_3 + i) = *(tab_1 + i) + *(tab_2 + i);
}
/*********** Exercise 10.12 ******************/
double average(const double (*rain)[12], int n)
{
	double sum = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 12; j++)
			sum += *(*(rain + i) + j);
	}

	return sum;
}
void smallAvg(const double (*rain)[12], int n)
{
	double sum = 0;

	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < n; j++) {
			sum += *(*(rain + j) + i);
		}
		printf("%4.1lf ", sum/n);
		sum = 0;
	}
}
/************ Exercise 10.13 ******************/
void getNumbers(double (*tab)[5], int rows)
{
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < 5; j++)
			scanf("%lf", &tab[i][j]); 
}
void rowAvg(const double (*tab)[5], int rows)
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
double avg(const double (*tab)[5], int rows)
{
	double sum = 0;

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < 5; j++)
			sum += tab[i][j];
	return sum/15;
}
double findLargest(const double (*tab)[5], int rows)
{
	double largest = 0;

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < 5; j++)
			largest = (largest < tab[i][j]) ? tab[i][j] : largest;
	return largest;
}
