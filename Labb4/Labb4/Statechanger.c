#include <avr/io.h>
#include "Pulsegenerator.h"
#include "Statechanger.h"
#include "TinyTimber.h"

#include <avr/interrupt.h>

void changeCurrent(Statechanger *self, int num)
{
	if((PINB >> 2) == 0)
	{ 
		self->current = self->left; //Switcha vänster sida
	}
	else if((PINB >> 3) == 0)
	{ 
		self->current = self->right; //Switcha höger sida
	}
}

void saveCurrent(Statechanger *self, int num)
{
	if ((PINB >> 4) == 0)
	{
		//Spara frekvensen och resetta då knappen är nedtryckt i centern.
		self->current->saved = self->current->frequence;
		self->current->frequence = 0;
	}
}

void increaseCurrent(Statechanger *self, int num){
	while((PINB >> 6) == 0){
		increase(self->current, num);
	}
}

void decreaseCurrent(Statechanger *self, int num){
	while((PINB >> 7) == 0){
		decrease(self->current, num);
	}
}