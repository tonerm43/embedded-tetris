#include "rng.h"
#include "game-engine.h"

int main(void)
{
	int level = 0, lines_cleared = 0;

	init_random();
	int score = start_game(&level, &lines_cleared);

	return score - score;
}
