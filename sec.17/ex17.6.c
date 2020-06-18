#include <stdio.h>
#include <stdbool.h>

bool isContained(const int *array, int n, int x); 

int main(int argc, char *argv[])
{
	int array[] = {0,1,2,3,4,8,11,12};
	int check[] = {5,20,0,13,15,14,6,8,3,1};

	for (int i = 0; i < sizeof(check)/sizeof(int); i++) {
	       if (isContained(array, sizeof(array)/sizeof(int), check[i]))	       
		       printf("The array contains the number: %d\n", check[i]);
	       else
		       printf("The array doesn't contain the number: %d\n", check[i]);
	}
	return 0;
}
bool isContained(const int *array, int n, int x)
{
	int start = 0;
	int end = n-1;
	int index = (start + end) / 2;

	while (1) {
		if (x == array[index])
			return true;
		else if (x < array[index]) {
			if (start == (end = index))
				return (x == array[index]) ? true : false;
			else
				index = (start + end) / 2;
		} else {
			if (end - (start = index) == 1)
				return (x == array[index + 1]) ? true : false;
			else
				index = (start + end) / 2;
		}
	}
}
