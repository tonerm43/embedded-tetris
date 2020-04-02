/**
* FILENAME : game-engine.h
*
* DESCRIPTION :
*       Header for game-engine.c
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#ifndef TETRIS_GAME_ENGINE_H
#define TETRIS_GAME_ENGINE_H

/**
 * Entry point of tetris game
 * Returns final score
 * */
int start_game(int *level, int *lines_cleared);

#endif //TETRIS_GAME_ENGINE_H
