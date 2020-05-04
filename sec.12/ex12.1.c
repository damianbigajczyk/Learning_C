#include <stdio.h>

void criticism(int *p_pounds)
{
	puts("Miss, try again!");
	scanf("%d", p_pounds);
}

int main(int argc, char *argv[])
{
	int pounds = 0;

	puts("How many pounds of butter can be are stored in a barrel?");
	while (scanf("%d", &pounds) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}
	while (pounds != 56)
		criticism(&pounds);
	puts("You probably peeped!");

	return 0;
}
