#include <stdio.h>
#include <stdlib.h>


struct letter {
	char ch;
	struct letter *previous;
};

int main(int argc, char **argv)
{
	char chTemp;
	struct letter *temp = NULL;
	struct letter *previousTemp = NULL;
	fputs("Enter your name: ", stdout);
	while ((chTemp = getchar()) != '\n') {
		if (temp == NULL) {
			temp = (struct letter*) malloc(sizeof(struct letter));
			temp->ch = chTemp;
			previousTemp = temp;
			continue;
		}
		struct letter *ptr = (struct letter*) malloc(sizeof(struct letter));
		ptr->ch = chTemp;
		ptr->previous = previousTemp;
		previousTemp = ptr;
	}

	while(previousTemp->previous != NULL) {
		putchar(previousTemp->ch);
		temp = previousTemp;
		previousTemp = previousTemp->previous;
		free(temp);
	}
	putchar(previousTemp->ch);
	free(previousTemp);
	puts("\n\nSee you!!!");

	return 0;
}
