#include <stdio.h>

#include "rng.h"
#include "game-engine.h"

int main(void)
{
	int level = 0, lines_cleared = 0;

	init_random();
	int score = start_game(&level, &lines_cleared);

	printf("You reached level %d.\n", level);
	printf("You scored %d points and cleared %d lines.\n", score, lines_cleared);

	return 0;
}
