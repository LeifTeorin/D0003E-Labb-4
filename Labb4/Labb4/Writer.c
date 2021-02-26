#include "Writer.h"
#include "TinyTimber.h"
#include <avr/io.h>

void writeHighToPort(Writer *self, int bitnr){
	if(bitnr == 4){
		PORTE |= 0x10;
	}
	if(bitnr == 6){
		PORTE |= 0x40;
	}
	//PORTE |= (1<<bitnr);
}

void writeLowToPort(Writer *self, int bitnr){
	if(bitnr == 4){
		PORTE &= 0xE0;
	}
	if(bitnr == 6){
		PORTE &= 0xB0;
	}
	//PORTE &= (~(1<<bitnr));
}