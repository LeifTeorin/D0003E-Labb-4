#include <avr/io.h>
#include "Pulsegenerator.h"
#include "TinyTimber.h"
#include "GUI.h"
#include "Writer.h"

#include <avr/interrupt.h>

void Pulse(Pulsegenerator *self, int num){
	if(self->frequence <= 0){
		AFTER(SEC(1), self, Pulse, NULL);
		SYNC(self->shakespear, writeLowToPort, self->bitnr);
		self->boo = 0;
	}else{
		if(self->boo)
		{
			SYNC(self->shakespear, writeHighToPort, self->bitnr);
		}else{
			SYNC(self->shakespear, writeLowToPort, self->bitnr);
		}
		AFTER(USEC(500000/self->frequence), self, Pulse, NULL);
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
	int args[2] = {self->pos, self->frequence};
	SYNC(self->ui, printAt, args); // vi printar den nya frekvensen
	if((PINB&0x40)==0){
		AFTER(MSEC(100), self, increase, 0); // om knappen hålls ned så kommer vi att skapa en ny increase
	}
}

void decrease(Pulsegenerator *self, int num){
	if(self->frequence > 0){
		self->frequence -= 1;
	}else{
		self->frequence = 0;
	}
	int args[2] = {self->pos, self->frequence};
	SYNC(self->ui, printAt, args);
	if((PINB&0x80)==0){
		AFTER(MSEC(100), self,decrease, 0); // om knappen hålls ned så skapas en ny decrease
	}
}

void save(Pulsegenerator *self, int num){
	if(self->frequence>0){
		self->saved = self->frequence;
		self->frequence = 0;
		SYNC(self->shakespear, writeLowToPort, self->bitnr);
		self->boo = 0; // efter att frekvensen blivit noll så blir porten låg
	}else{
		self->frequence = self->saved;
	}
	int args[2] = {self->pos, self->frequence};
	SYNC(self->ui, printAt, args);
}