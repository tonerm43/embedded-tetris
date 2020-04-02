/**
* FILENAME : vga-driver.c
*
* DESCRIPTION :
*       Function implementations for vga-driver module
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#include "vga-driver.h"

void set_data_lines(uint8_t data);
uint8_t colour_for(uint8_t cell);

void init_vga_driver()
{
	// Enable ports for GPIO
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK |
			SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK;

	// Set PCR and PDDR for data bits
	PORTC_PCR16 |= PORT_PCR_MUX(1); // Data bit 0
	PORTC_PCR17 |= PORT_PCR_MUX(1); // Data bit 1
	PORTB_PCR9  |= PORT_PCR_MUX(1); // Data bit 2
	PORTA_PCR1  |= PORT_PCR_MUX(1); // Data bit 3
	PORTB_PCR23 |= PORT_PCR_MUX(1); // Data bit 4
	PORTA_PCR2  |= PORT_PCR_MUX(1); // Data bit 5
	PORTC_PCR2  |= PORT_PCR_MUX(1); // Data bit 6
	PORTC_PCR3  |= PORT_PCR_MUX(1); // Data bit 7

	GPIOA_PDDR |= ((1 << 1) | (1 << 2)); // Enable pins 1 and 2 for output
	GPIOB_PDDR |= ((1 << 9) | (1 << 23)); // Enable pins 9 and 23 for output
	GPIOC_PDDR |= ((1<<2)|(1<<3)|(1<<16)|(1<<17)); // Enable pins 2, 3, 16, 17 for output

	// Set PCR and PDDR for control bits
	PORTA_PCR0 |= PORT_PCR_MUX(1); // GPIO ADDR RESET
	PORTC_PCR4 |= PORT_PCR_MUX(1); // GPIO RAM LOAD
	PORTD_PCR0 |= PORT_PCR_MUX(1); // GPIO ADDR INC
	PORTD_PCR2 |= PORT_PCR_MUX(1); // GPIO RAM COMMIT

	GPIOA_PDDR |= 1; // Enable pin 0 for output
	GPIOC_PDDR |= (1 << 4); // Enable pin 4 for output
	GPIOD_PDDR |= (1 | (1 << 2)); // Enable pins 0 and 2 for output

	// GPIO RAM COMMIT is active low, so initialize to high
	GPIOD_PSOR |= (1 << 2);
}

void gpio_write_graphics_data(struct tetris_well *well)
{
	// Set GPIO RAM LOAD
	GPIOC_PSOR |= (1 << 4);

	// Cycle GPIO ADDR RESET bit
	GPIOA_PSOR |= 1;
	GPIOA_PCOR |= 1;

	// Loop to set each memory location
	for(int i = 0; i < 600; i++) {
		for(int j = 0; j < 200; j++) {
			if (j < 64 || j >= 136) {
				// Set black pixels outside of well
				set_data_lines(CELL_COLOUR_NONE);
			} else if ((j >= 64 && j < 70) || (j >= 130 && j < 136)) {
				// Set pixels for vertical walls
				set_data_lines(CELL_COLOUR_WALL);
			} else {
				if (i >= 576) {
					// Set white pixels for bottom of well
					set_data_lines(CELL_COLOUR_WALL);
				} else {
					// Find colour for current pixel from well
					int horizontal_ix = (j - 70) / BLOCK_SIZE_HORIZONTAL;
					int vertical_ix = i / BLOCK_SIZE_VERTICAL;

					uint8_t cell_type = well->matrix[vertical_ix][horizontal_ix];
					set_data_lines(colour_for(cell_type));
				}
			}

			// Cycle GPIO RAM COMMIT
			GPIOD_PCOR |= (1 << 2);
			GPIOD_PSOR |= (1 << 2);

			// Cycle GPIO ADDR INC
			GPIOD_PSOR |= 1;
			GPIOD_PCOR |= 1;
		}
	}

	// Clear GPIO RAM LOAD
	GPIOC_PCOR |= (1 << 4);
}

void set_data_lines(uint8_t data)
{
	GPIOC_PSOR |= (data & 1) << 16;
	GPIOC_PSOR |= ((data & (1 << 1)) >> 1) << 17;
	GPIOB_PSOR |= ((data & (1 << 2)) >> 2) << 9;
	GPIOA_PSOR |= ((data & (1 << 3)) >> 3) << 1;
	GPIOB_PSOR |= ((data & (1 << 4)) >> 4) << 23;
	GPIOA_PSOR |= ((data & (1 << 5)) >> 5) << 2;
	GPIOC_PSOR |= ((data & (1 << 6)) >> 6) << 2;
	GPIOC_PSOR |= ((data & (1 << 7)) >> 7) << 3;
}

uint8_t colour_for(uint8_t cell)
{
	switch (cell) {
		case CELL_TYPE_NONE:
			return CELL_COLOUR_NONE;
		case CELL_TYPE_I:
			return CELL_COLOUR_I;
		case CELL_TYPE_O:
			return CELL_COLOUR_O;
		case CELL_TYPE_T:
			return CELL_COLOUR_T;
		case CELL_TYPE_S:
			return CELL_COLOUR_S;
		case CELL_TYPE_Z:
			return CELL_COLOUR_Z;
		case CELL_TYPE_J:
			return CELL_COLOUR_J;
		case CELL_TYPE_L:
			return CELL_COLOUR_L;
	}
}
