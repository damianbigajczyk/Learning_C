#include <stdio.h>

int loadString(char (*argv)[50])
{
	char ch = '\0';
	int i = 0;
	int j = 0;
	
	FILE *fp = fopen("tekst.txt", "r");
	if (fp == NULL) {
		puts("Failed to open file");
		return -1;
	}
	puts("OK");
	argv[0][0] = "D";
	puts(&argv[0][0]);
	while (fputc(ch, fp) != EOF && i < 10) {
		if (ch == '\n' || j == 48) {
			argv[i][j++] = ch;
			argv[i][j] = '\0';
			i++;
			j = 0;
		} else {	
			argv[i][j] = ch;
			j++;
		}
	}	
	fclose(fp);
	return i;
}
void menu(void)
{
	printf("MENU\n");
	printf("1)wyswietl\n2)wyswietl ASCII\n3)wyswietl rosnaco\n4)wyswietl slowo\n5)koniec\n");
}

int main(int argc, char *argv[])
{
	char array[10][50];
	int choice = 0;
	int count = loadString(array);

	if (count == -1)
		return 0;

	printf("%d\n", count);

	for(int i = 0; i < count; i++) {
		puts(&array[i][0]);
	}
	//menu();
	//scnaf("%d" &choice);

	return 0;
}
