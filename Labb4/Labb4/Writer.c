#include "Writer.h"
#include "TinyTimber.h"
#include "Pulsegenerator.h"
#include <avr/io.h>

void writeHighToPort(Writer *self, int bitnr){
	if(bitnr == 4){
		PORTE |= 0x10;
		LCDDR2 |= 0x60;
	}
	if(bitnr == 6){
		PORTE |= 0x40;
		LCDDR2 |= 0x06;
	}
	//PORTE |= (1<<bitnr);
}

void writeLowToPort(Writer *self, int bitnr){
	if(bitnr == 4){
		PORTE &= 0xEF;
		LCDDR2 &= 0x9F;
	}
	if(bitnr == 6){
		PORTE &= 0xBF;
		LCDDR2 &= 0xF9;
	}
	//PORTE &= (~(1<<bitnr));
}
