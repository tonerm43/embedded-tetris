/**
* FILENAME : rng.h
*
* DESCRIPTION :
*       Header for rng.c
*
* AUTHORS :    Brandon Richardson, Mackenzie Toner
*
*/

#ifndef INCLUDE_RNG_H_
#define INCLUDE_RNG_H_

#include "MK64F12.h"

/**
 * Initialize FRDM-K64 RNG module for use
 * */
void init_random();

/**
 * Get random.
 * */
int random (void);

#endif /* INCLUDE_RNG_H_ */
