/**
* FILENAME : serial-driver.c
*
* DESCRIPTION :
*       Function implementations for serial-driver module
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#include "serial-driver.h"

void serial_putchar(char c);
char char_for(uint8_t cell);

void init_serial()
{
	// Enable the clock module
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;

	// Enable port E and B
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTB_MASK;

	// Connect the UART0 to the PORTE bits PC4 -TX, PC5 –RX
	PORTB_PCR17 |= PORT_PCR_MUX(3); // PB17 TX
	PORTB_PCR16 |= PORT_PCR_MUX(3); // PB16 RX

	// Disable transmit enable and receive enable
	UART0_C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

	// Configure UART0 for 8 bits, even parity enabled
	UART0_C1 = 0b00;

	// Set the baud rate to 9600
	// Must be 1/16 the clock rate
	UART0_BDH = 0;
	UART0_BDL = 0x88;

	// Enable transmit and receive
	UART0_C2 |= UART_C2_TE_MASK;
	UART0_C2 |= UART_C2_RE_MASK;
}

void serial_print_well(struct tetris_well *well)
{
	for(int i = 0; i < BOARD_HEIGHT; i++) {
		serial_putchar('\n');
		serial_putchar('\r');
		serial_putchar('|');
		for (int j = 0; j < BOARD_WIDTH; j++) {
			char c = char_for(well->matrix[i][j]);
			if (((well->tetrimino_coords[0][0] == j && well->tetrimino_coords[0][1] == i) ||
				 (well->tetrimino_coords[1][0] == j && well->tetrimino_coords[1][1] == i) ||
				 (well->tetrimino_coords[2][0] == j && well->tetrimino_coords[2][1] == i) ||
				 (well->tetrimino_coords[3][0] == j && well->tetrimino_coords[3][1] == i)))
				c = char_for(well->tetrimino_type);
			serial_putchar(c);
		}
		serial_putchar('|');
	}
	serial_putchar('\n');
	serial_putchar('\r');
	for(int i = 0; i < BOARD_WIDTH + 2; i++) {
		serial_putchar('-');
	}
}

char serial_get_input()
{
	// Check the RDRF (transmit data register empty)
	if((UART0_S1 >> 5) & 1) {
		// Read from output
		return UART0_D;
	}
	return 0;
}

void serial_putchar(char c) {
	// Poll the TDRE (transmit data register empty)
	while(!((UART0_S1 >> 7) & 1));
	// Write to output
	UART0_D = c;
}

void serial_print_string(char *s)
{
	while(*s) {
		serial_putchar(*s);
		s++;
	}

}

char char_for(uint8_t cell)
{
	switch (cell) {
		case CELL_TYPE_NONE:
			return ' ';
		case CELL_TYPE_I:
			return 'I';
		case CELL_TYPE_O:
			return 'O';
		case CELL_TYPE_T:
			return 'T';
		case CELL_TYPE_S:
			return 'S';
		case CELL_TYPE_Z:
			return 'Z';
		case CELL_TYPE_J:
			return 'J';
		case CELL_TYPE_L:
			return 'L';
	}
}

