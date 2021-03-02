#ifndef _INPUTS_
#define _INPUTS_

#include "Statechanger.h"
#include "TinyTimber.h"
#include "Pulsegenerator.h"

typedef struct {
	Object super;
	struct Statechanger *coup;
	struct Pulsegenerator *left;
	struct Pulsegenerator *right;
	struct Pulsegenerator *current;
	} Inputs;

#define initInputs(coup, left, right)\
	{initObject(), coup, left, right, left}
		

void checkInputs(Inputs *self);
void checkSideways(Inputs *self);
void initialize(Inputs *self);

#endif