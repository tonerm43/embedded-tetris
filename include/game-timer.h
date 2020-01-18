#ifndef INCLUDE_GAME_TIMER_H_
#define INCLUDE_GAME_TIMER_H_

/**
 * game-timer.h
 *
 * Utilizes the FlexTimer Module (FTM) to
 * */

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
