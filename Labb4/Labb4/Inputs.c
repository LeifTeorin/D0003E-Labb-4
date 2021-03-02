#include "Inputs.h"
#include "Statechanger.h"
#include "TinyTimber.h"
#include "Pulsegenerator.h"
#include <avr/io.h>

void initialize(Inputs *self){
	ASYNC(self->left, Pulse, 0);
	ASYNC(self->right, Pulse, 0);
}

void checkInputs(Inputs *self){
	if((PINB&0x80)==0){ // nedtryckt
		ASYNC(self->current, decrease, 0);
//		AFTER(MSEC(450), self->coup, decreaseCurrent, 0);
//		ASYNC(self->coup, decreaseCurrent, 0);
	}
	if((PINB&0x40)==0){
		ASYNC(self->current, increase, 0);
//		AFTER(MSEC(450), self->coup, increaseCurrent, 0);
//		ASYNC(self->coup, increaseCurrent, 0);
	}
	if((PINB&0x10)==0){
		ASYNC(self->current, save, 0);
	}
	// lägg till kod för nedtryckning sen
}

void checkSideways(Inputs *self){
	// anropa changecurrent
	if((PINE&0x04)==0){
		self->current = self->left;
		LCDDR1 &= 0x9F;
		LCDDR0 |= 0x40;
	
	}
	if((PINE&0x08)==0){
		self->current = self->right;
		LCDDR0 &= 0x9F;
		LCDDR1 |= 0x20;
	}
}