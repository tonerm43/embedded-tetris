/**
* FILENAME : input-capture.c
*
* DESCRIPTION :
*       Function implementations for input-capture module
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#include "input-capture.h"

void init_input_capture()
{
	// Set up ADCs for joystick
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK;

	// Set ADCs interrupt disabled, single ended, DP1 selected as input
	ADC0_SC1A |= 0b0000001;
	ADC1_SC1A |= 0b0000001;

	// Set up GPIO for pushbuttons
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC_PCR10 |= PORT_PCR_MUX(1); // Rotate
	PORTC_PCR11 |= PORT_PCR_MUX(1); // Drop
}

int user_input()
{
	// Start conversions for ADC
	ADC0_SC1A |= 0b0000001;
	ADC1_SC1A |= 0b0000001;

	if ((GPIOC_PDIR >> 10) & 1) {
		return INPUT_ROTATE;
	} else if ((GPIOC_PDIR >> 11) & 1) {
		return INPUT_DROP;
	} else {
		// Determine joystick left/right with 'dead zone'
		// in middle 1/4 of total joystick range
		while (!(ADC0_SC1A >> 7 & 1));
		if (ADC0_RA >= 0x00 && ADC0_RA < 0x60) {
			// Joystick Left
			return INPUT_LEFT;
		} else if (ADC0_RA <= 0xFF && ADC0_RA > 0xA0) {
			// Joystick Right
			return INPUT_RIGHT;
		}

		// Determine joystick up/down with 'dead zone'
		// in middle 1/4 of total joystick range
		while (!(ADC1_SC1A >> 7 & 1));
		if (ADC0_RA >= 0x00 && ADC0_RA < 0x60) {
			// Joystick down
			return INPUT_DOWN;
		}
		// Don't care about joystick up
	}
	// No input detected
	return 0;
}
