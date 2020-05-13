#include <stdio.h>
#include "function_6.h"

int main(int argc, char **argv)
{
	struct basketball player[12];
	getData(player);
	countEfficacity(player);
	showPlayer(player);

	return 0;
}
