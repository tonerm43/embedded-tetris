/**
* FILENAME : input-capture.h
*
* DESCRIPTION :
*       Header for input-capture.c
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#ifndef INCLUDE_INPUT_CAPTURE_H_
#define INCLUDE_INPUT_CAPTURE_H_

#include "MK64F12.h"
#include "serial-driver.h"

#define INPUT_LEFT 1
#define INPUT_RIGHT 2
#define INPUT_DOWN 3
#define INPUT_ROTATE 4
#define INPUT_PAUSE 5
#define INPUT_STOP 6
#define INPUT_DROP 7

/**
 * Initialize ADCs and GPIO for input captrue
 */
void init_input_capture();

/**
 * Check for input and return what input
 * was triggered if the user triggered input
 */
int user_input();

#endif /* INCLUDE_INPUT_CAPTURE_H_ */
