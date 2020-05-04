#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
	if (argc < 2) {
		puts("Usage: ./ex6.7 <word>");
		return 0;
	}

	uint8_t wordLen = strlen(argv[1]);
	char temp[wordLen + 1];
	
	for(int i = 0; i < wordLen; i++)
		temp[i] = argv[1][wordLen-i-1];
	
	printf("%s\t%s\n", argv[1], temp);

	return 0;
}
