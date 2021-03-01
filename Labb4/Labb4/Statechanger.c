#include <avr/io.h>
#include "Pulsegenerator.h"
#include "Statechanger.h"
#include "TinyTimber.h"
#include "GUI.h"
#include <avr/interrupt.h>


void changeCurrent(Statechanger *self, int num)
{
	if((PINE & 0x04) == 0)
	{ 
		self->current = self->left; //Switcha vänster sida
	}
	else if((PINE & 0x02) == 0)
	{ 
		self->current = self->right; //Switcha höger sida
	}
}

void saveCurrent(Statechanger *self, int num)
{
	if ((PINB&0x10) == 0)
	{
		//Spara frekvensen och resetta då knappen är nedtryckt i centern.
		SYNC(self->current, save, num);
	}
}

void changeCurrenttoright(Statechanger *self, int num){
	self->current = self->right;
}

void changeCurrenttoleft(Statechanger *self, int num){
	self->current = self->left;
}

void increaseCurrent(Statechanger *self, int num){
	Pulsegenerator *curr = self->current;
	while((PINB & 0x40)==0){
		ASYNC(self->current, increase, num);
		if(curr->pos == 0){
			SYNC(&(self->current), printLeft, curr->frequence);
		}else{
			SYNC(&(self->current), printRight, curr->frequence);
		}
		//increase(self->current, num);
		//ASYNC(&(self->ui), printAt, (&(self->ui), self->current->frequence, self->current->pos));
		//printAt(&(self->ui), self->current->frequence, current->pos);
	}
}

void decreaseCurrent(Statechanger *self, int num){
	Pulsegenerator *curr = self->current;
	while((PINB >> 7) == 0){
		ASYNC(self->current, decrease, num); // vi tar och spawnar en decrease
		//decrease(self->current, num);
		if(curr->pos == 0){
			SYNC(&(self->current), printLeft, curr->frequence); // synka s� att inget g�r fel
		}else{
			SYNC(&(self->current), printRight, curr->frequence);
		}
	}
}