#include "Inputs.h"
#include "Statechanger.h"
#include "TinyTimber.h"
#include <avr/io.h>

void checkInputs(Inputs *self, int num){
	if((PINB&0x80)==0){ // nedtryckt
		SYNC(self->coup, decreaseCurrent, 0);
	}
	if((PINB&0x40)==0){
		SYNC(self->coup, increaseCurrent, 0);
	}
	if((PINB&0x10)==0){
		SYNC(self->coup, saveCurrent, 0);
	}
	// lägg till kod för nedtryckning sen
}

void checkSideways(Inputs *self, int num){
	// anropa changecurrent
	if((PINE&0x04)==0){
		SYNC(self->coup, changeCurrenttoleft, 0);
	}
	if((PINE&0x08)==0){
		SYNC(self->coup, changeCurrenttoright, 0);
	}
}