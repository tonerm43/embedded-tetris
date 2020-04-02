/**
* FILENAME : game-timer.h
*
* DESCRIPTION :
*       Header for game-timer.c
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#ifndef INCLUDE_GAME_TIMER_H_
#define INCLUDE_GAME_TIMER_H_

/**
 * Initialize `sleep`-like timer functionality.
 * */
void timer_init(void);

/**
 * Once initialized, sleeps for the given number of nanoseconds.
 * */
void sleep(long nano_delay);

/**
 * Initialize interrupt-based timer functionality.
 *
 * Must define `FTM2_IRQHandler(void)` handler.
 * */
void itimer_init(long nano);

#endif /* INCLUDE_GAME_TIMER_H_ */
