#ifndef function_H_
#define function_H_

#define months 12
#define years 5

extern const double rain[years][months];

void printArray(const double array[], int n);
void cpyArray_1(const double source[], double destiny[], int n);
void cpyArray_2(const double *source, double *destiny, int size);
void cpyArray_3(const double *source, double *destiny, const double *end);

double findValue(double *tab, int size);

__uint32_t findIndex(double *tab, int size);

int diff(int *array, int size);

void reverse(double *tab, int n);

void showArray_1(double *tab, int n);

void cpyArray_4(const double (*source)[5], int rows, double(*destiny)[5]);
void showArray_2(const double (*tab)[5], int rows);

void addArray(int *tab_1, int *tab_2, int *tab_3, int n_1, int n_2, int n_3);

double average(const double (*rain)[12], int n);
void smallAvg(const double (*rain)[12], int n);

void getNumbers(double (*tab)[5], int rows);
void rowAvg(const double (*tab)[5], int rows);
double avg(const double (*tab)[5], int rows);
double findLargest(const double (*tab)[5], int rows);

#endif
