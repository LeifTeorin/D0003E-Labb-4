#include <avr/io.h>
#include "Pulsegenerator.h"
#include "TinyTimber.h"
#include "GUI.h"
#include "Writer.h"

#include <avr/interrupt.h>

void Pulse(Pulsegenerator *self, int num){
	if(self->frequence == 0){
		AFTER(SEC(1), self, Pulse, NULL);
	}else{
		
		if(self->boo)
		{
			SYNC(self->shakespear, writeHighToPort, self->bitnr);
		}else{
			SYNC(self->shakespear, writeLowToPort, self->bitnr);
		}
		AFTER(USEC(1000000/self->frequence), self, Pulse, NULL);
		self->boo = !(self->boo);
		//AFTER(SEC(1), self, Pulse, num);
	}
	
}

void increase(Pulsegenerator *self, int num){
	
	if(self->frequence < 99){
		self->frequence +=1;
	}else{
		self->frequence = 99;
	}
	if(self->pos == 0){
		SYNC(self->ui, printLeft, self->frequence);
	}else{
		SYNC(self->ui, printRight, self->frequence);
	}
	//increase(self->current, num);
	//ASYNC(&(self->ui), printAt, (&(self->ui), self->current->frequence, self->current->pos));
	//printAt(&(self->ui), self->current->frequence, current->pos);
	if((PINB&0x40)==0){
		AFTER(MSEC(100), self, increase, 0);
	}
}

void decrease(Pulsegenerator *self, int num){
	if(self->frequence > 0){
		self->frequence -= 1;
	}else{
		self->frequence = 0;
	}
	if(self->pos == 0){
		SYNC(self->ui, printLeft, self->frequence);
	}else{
		SYNC(self->ui, printRight, self->frequence);
	}
	//increase(self->current, num);
	//ASYNC(&(self->ui), printAt, (&(self->ui), self->current->frequence, self->current->pos));
	//printAt(&(self->ui), self->current->frequence, current->pos);
	if((PINB&0x80)==0){
		AFTER(MSEC(100), self,decrease, 0);
	}
}

void save(Pulsegenerator *self, int num){
	if(self->frequence>0){
		self->saved = self->frequence;
		self->frequence = 0;
	}else{
		self->frequence = self->saved;
	}
	if(self->pos == 0){
		SYNC(self->ui, printLeft, self->frequence);
	}else{
		SYNC(self->ui, printRight, self->frequence);
	}
}