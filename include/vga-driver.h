/**
* FILENAME : vga-driver.h
*
* DESCRIPTION :
*       Header for vga-driver.c
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#ifndef INCLUDE_VGA_DRIVER_H_
#define INCLUDE_VGA_DRIVER_H_

#include "tetris-well.h"
#include "MK64F12.h"

/* Colours for each tetromino, compliant with 8-bit colour format */
#define CELL_COLOUR_NONE 0x00
#define CELL_COLOUR_WALL 0xff
#define CELL_COLOUR_I 0x1F /* Aqua */
#define CELL_COLOUR_O 0xFC /* Yellow */
#define CELL_COLOUR_T 0xE3 /* Purple */
#define CELL_COLOUR_S 0x1C /* Green */
#define CELL_COLOUR_Z 0xE0 /* Red */
#define CELL_COLOUR_J 0x03 /* Blue */
#define CELL_COLOUR_L 0xF0 /* Orange */

/* Block size in pixels */
#define BLOCK_SIZE_VERTICAL 24
#define BLOCK_SIZE_HORIZONTAL 6

/**
 * Initialize GPIO pins for use by the vga driver
 */
void init_vga_driver();

/**
 * Use the current state of the well to write pixel data
 * to VGA circuit memory
 */
void gpio_write_graphics_data(struct tetris_well *well);

#endif /* INCLUDE_VGA_DRIVER_H_ */
