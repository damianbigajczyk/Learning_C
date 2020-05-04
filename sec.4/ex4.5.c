#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float speed = 0;
	float size = 0;
	float time = 0;

	if (argc < 3) {
		puts("Usage: ./ex4.5 <speed[mb/s]> <size[Mb]>");
		return 0;
	}

	if (!(speed = atof(argv[1])) || !(size = atof(argv[2]))) {
		puts("Error: valid conversion");
		return 0;
	}

	time = size * 8 / speed;

	printf("The file %.2f[Mb] of size will be downloaded in %.2f seconds with %.2f[mb/s] speed\n",
		      size, time, speed);	

	return 0;
}
