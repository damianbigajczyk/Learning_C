#include <stdio.h>
#include "pe12_3.h"

int main(int argc, char *argv[])
{
	int mode = setMode();

	while (mode >= 0) {
		float distance = 0;
		float usage = 0;

		getData(mode, &distance, &usage);
		showData(mode, &distance, &usage);
		mode = setMode();
	}
	puts("The end");

	return 0;
}

