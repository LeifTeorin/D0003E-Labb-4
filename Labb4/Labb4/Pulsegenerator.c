#include <avr/io.h>
#include "Pulsegenerator.h"
#include "TinyTimber.h"

#include <avr/interrupt.h>

void Pulse(Pulsegenerator *self, int num){
	self->boo = !(self->boo);
	if(self->boo)
	{
		//send io 3.3V with SYNC to writer
	}else{
		//send io 0V with SYNC to writer
	}
	//Pulse with a timer
}

void increase(Pulsegenerator *self, int num){
	if(self->frequence < 99){
		self->frequence +=1;
		// härifrån anropas GUI
	}
}

void decrease(Pulsegenerator *self, int num){
	if(self->frequence > 0){
		(self->frequence)--;
		// härifrån anropas GUI
	}
}