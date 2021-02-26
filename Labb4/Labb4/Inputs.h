#ifndef _INPUTS_
#define _INPUTS_

#include "Statechanger.h"
#include "TinyTimber.h"

typedef struct {
	Object super;
	struct Statechanger *coup;
	} Inputs;

#define initInputs(coup)\
	{initObject(), coup}
		

void checkInputs(Inputs *self, int num);

#endif