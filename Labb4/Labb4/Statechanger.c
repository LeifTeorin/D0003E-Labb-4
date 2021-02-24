#include <avr/io.h>
#include "Pulsegenerator.h"
#include "Statechanger.h"
#include "TinyTimber.h"

#include <avr/interrupt.h>

void changeCurrent(Statechanger *self, int num){
	
}

void increaseCurrent(Statechanger *self, int num){
	while((PINB >> 6)==0){
		increase(self->current, num);
	}
}

void decreaseCurrent(Statechanger *self, int num){
	while((PINB >> 7) == 0){
		decrease(self->current, num);
	}
}