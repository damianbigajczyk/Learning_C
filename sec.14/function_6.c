#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "function_6.h"

int getData(struct basketball *player)
{
	FILE *pf = NULL;
	uint8_t number;
	int rc = 0;

	if (!(pf = fopen("Players", "r"))) {
		fputs("Failed to open file: \"Players\"\n", stderr);
		return -1;
	}

	while ((rc = fscanf(pf, "%hhu", &number)) != EOF) {
		fscanf(pf, "%s", (player + number)->name);
		fscanf(pf, "%s", (player + number)->surname);
		fscanf(pf, "%hhu", &(player + number)->throw_2);
		fscanf(pf, "%hhu", &(player + number)->hit);
		fscanf(pf, "%hhu", &(player + number)->assist);
		fscanf(pf, "%hhu", &(player + number)->faul);
	}
	if (fclose(pf))
		fputs("Failed to close file\n", stderr);

	return 0;
}
void countEfficacity(struct basketball *player)
{
	for (int i = 0; i < 12; i++, player++)
		player->rate = ((float) player->hit / player->throw_2) * 100;
}
void showPlayer(const struct basketball *player)
{
	uint16_t sumThrow = 0;
	uint16_t sumHit = 0;

	printf("%-7s %-15s%-15s %-7s\t%-5s %-7s %-5s %-15s\n", "Number", "Name", "Surname", "Throw",
			"Hit", "Assist", "Faul", "success rate[%]");
	for (int i = 0; i < 12; i++, player++) {
		sumThrow += player->throw_2;
		sumHit += player->hit;
		printf("%4hhu\t%-15s%-15s%4hhu\t%3hhu\t%4hhu\t%2hhu    %7.2f\n", i, player->name, player->surname,
				player->throw_2, player->hit, player->assist, player->faul, player->rate);
	}
	printf("All throws: %hu\nAll hits: %hu\nTeam success rate[%%]: %.2f\n", sumThrow, sumHit,
			((float) sumHit / sumThrow) * 100);
}
