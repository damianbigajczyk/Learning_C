#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int value)
{
	int *wsk = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		wsk[i] = value;
	return wsk;
}

void show_array(const int tab[], int n)
{
	for(int i = 0; i < n; ) {
		printf("%d\t", tab[i]);
		if (!(++i % 8))
			putchar('\n');
	}
}

int main(int argc, char *argv[])
{
	int *wt = NULL;
	int size, value;

	fputs("Enter an amount of elements: ", stdout);
	while (scanf("%d", &size) == 1 && size > 0) {
		fputs("Enter initial value: ", stdout);
		scanf("%d", &value);
		wt = create_array(size, value);
		if (wt) {
			show_array(wt, size);
			free(wt);
		}
		fputs("\nEnter an amount of elements\n(-1 - the end): ", stdout);
	}
	puts("The end");
	
	return 0;
}
