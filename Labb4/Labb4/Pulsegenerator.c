#include <avr/io.h>
#include "Pulsegenerator.h"
#include "TinyTimber.h"
#include "GUI.h"
#include "Writer.h"

#include <avr/interrupt.h>

void Pulse(Pulsegenerator *self, int num){
	self->boo = !(self->boo);
	if(self->frequence == 0){
		AFTER(SEC(1), self, Pulse, num);
		return;
	}else{
		AFTER(USEC(1000000/self->frequence), self, Pulse, num);
		//AFTER(SEC(1), self, Pulse, num);
	}
	if(self->boo)
	{
		SYNC(self->shakespear, writeHighToPort, self->bitnr);
	}else{
		SYNC(self->shakespear, writeLowToPort, self->bitnr);
	}
}

void increase(Pulsegenerator *self, int num){
	if(self->frequence < 99){
		self->frequence +=1;
	}
}

void decrease(Pulsegenerator *self, int num){
	if(self->frequence > 0){
		(self->frequence)--;
	}
}

void save(Pulsegenerator *self, int num){
	if(self->frequence>0){
		self->saved = self->frequence;
		self->frequence = 0;
	}else{
		self->frequence = self->saved;
	}
}