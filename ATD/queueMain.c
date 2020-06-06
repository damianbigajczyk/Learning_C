#include <stdio.h>
#include "queue.h"

int main(int argc, char **argv)
{
	Queue que;
	Position temp;
	char ch;
	InitQueue(&que);
	puts("This is test of queue interface. Enter 'd' to add value,");
	puts("'u' to delete value or 'q' to quit");
	while ((ch = getchar()) != 'q') {
		switch (ch) {
			case 'd':
				fputs("The value to add: ", stdout);
				scanf("%d", &temp);
				if (!FullQueue(&que)) {
					printf("%d has been added to queue\n", temp);
					Set(temp, &que);
				} else 
					puts("The queue is full");
				break;
			case 'u':
				if (EmptyQueue(&que))
					puts("Nothing to detach");
				else {
					Detach(&temp, &que);
					printf("%d has been detached from queue\n", temp);
				}
				break;
			default:
				continue;
		}
		while (getchar() != '\n') {}
		printf("Amount of positions: %d\n", CountAmount(&que));
		puts("Enter 'd' to add value, 'u' to delete or 'q' to quit");
	}
	ClearQueue(&que);
	puts("See you!");

	return 0;
}
