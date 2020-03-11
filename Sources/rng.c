/*
 * rng.c
 *
 *  Created on: Feb 26, 2020
 *      Author: bricha11
 */
#include "MK64F12.h"
#include "rng.h"

void init_random()
{
	SIM_SCGC6 |= SIM_SCGC6_RNGA_MASK;
	/* Enable the RNG module: */
	// //Interrupt Mask (bit 2)
	// //High Assurance (bit 1)
	// Go (bit 0)
	RNG_CR |= RNG_CR_GO_MASK;

	int seed = random();
	RNG_ER = seed;
}

int random (void)
{
	while(!(RNG_SR & RNG_SR_OREG_LVL_MASK));
	return RNG_OR;
}



