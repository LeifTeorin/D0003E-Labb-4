#ifndef _STATECHANGER_
#define _STATECHANGER_

#include "Pulsegenerator.h"
#include "TinyTimber.h"

typedef struct{
	Object super;
	Pulsegenerator left;
	Pulsegenerator right;
	*Pulsegenerator current;
}Statechanger;

#define initStatechanger(Pulsegenerator left, Pulsegenerator right)\
			{initObject(), left, right, &left}
void increaseCurrent(Statechanger *self, int num);
void decreaseCurrent(Statechanger *self, int num);
void changeCurrent(Statechanger *self, int num);