#include <avr/io.h>
#include "Pulsegenerator.h"

#include <avr/interrupt.h>

void Pulse(Pulsegenerator *self)
{
	self->boo = !(self->boo);
	if(self->boo)
	{
		//send io 3.3V
	}
	else
	{
		//send io 0V
	}
	//Pulse with a timer
}

