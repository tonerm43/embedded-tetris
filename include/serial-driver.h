/**
* FILENAME : serial-driver.h
*
* DESCRIPTION :
*       Header for serial-driver.c
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#ifndef INCLUDE_SERIAL_DRIVER_H_
#define INCLUDE_SERIAL_DRIVER_H_

#include "fsl_device_registers.h"
#include "tetris-well.h"

/**
 * Initialize UART for use
 */
void init_serial();


/**
 * Send state of well to UART to print
 */
void serial_print_well(struct tetris_well *well);

/**
 * Get input from keyboard
 */
char serial_get_input();

/**
 * Output a string to uart
 */
void serial_print_string(char *s);

#endif /* INCLUDE_SERIAL_DRIVER_H_ */
