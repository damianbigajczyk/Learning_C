#include <stdio.h>
#include <stdlib.h>
#include "pex12_9.h"

int main(int argc, char *argv[])
{
	char **w_w_array = create_array();

	if (!(w_w_array))
		return 0;

	getWord(w_w_array);
	showWord(w_w_array);	
	clearMem(w_w_array);

	return 0;
}
