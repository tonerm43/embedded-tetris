/**
* FILENAME : main.c
*
* DESCRIPTION :
*       Main function responsible for initializing
*       modules and starting the tetris game
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#include "game-engine.h"
#include "graphics-driver.h"
#include "input-capture.h"
#include "rng.h"
#include "serial-driver.h"

int main(void)
{
	int level = 0, lines_cleared = 0;

	init_random();
	init_graphics_driver();
	init_serial();
	init_input_capture();

	int score = start_game(&level, &lines_cleared);

	char score_text[80];
	sprintf(score_text, "\n\rYour final score is: %d\n\r", score);
	serial_print_string(score_text);

	return score - score;
}
