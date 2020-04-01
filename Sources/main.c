#include "game-engine.h"
#include "input-capture.h"
#include "rng.h"
#include "vga-driver.h"

int main(void)
{
	int level = 0, lines_cleared = 0;

	init_random();
	init_vga_driver();
	init_input_capture();
	int score = start_game(&level, &lines_cleared);

	return score - score;
}
