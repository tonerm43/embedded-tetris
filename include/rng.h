#ifndef INCLUDE_RNG_H_
#define INCLUDE_RNG_H_

#include "MK64F12.h"

void init_random();

/**
 * Get random.
 * */
int random (void);

#endif /* INCLUDE_RNG_H_ */
