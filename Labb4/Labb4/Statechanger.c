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
	//Spara frekvensen och resetta då knappen är nedtryckt i centern.
	Pulsegenerator *curr = self->current;
	SYNC(self->current, save, num);
	if(curr->pos == 0){
		ASYNC(self->ui, printLeft, curr->frequence);
	}else{
		ASYNC(self->ui, printRight, curr->frequence);
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
	SYNC(self->current, increase, num);
	if(curr->pos == 0){
		ASYNC(self->ui, printLeft, curr->frequence);
	}else{
		ASYNC(self->ui, printRight, curr->frequence);
	}
		//increase(self->current, num);
		//ASYNC(&(self->ui), printAt, (&(self->ui), self->current->frequence, self->current->pos));
		//printAt(&(self->ui), self->current->frequence, current->pos);
		if((1<<PINB7)==1 && (1<<PINB6)==0 && (1<<PINB4)==1){
			AFTER(MSEC(200), self, increaseCurrent, 0);
		}
}

void decreaseCurrent(Statechanger *self, int num){
	Pulsegenerator *curr = self->current;
	SYNC(self->current, decrease, num); // vi tar och spawnar en decrease
	//decrease(self->current, num);
	if(curr->pos == 0){
		ASYNC(self->ui, printLeft, curr->frequence); // synka s� att inget g�r fel
	}else{
		ASYNC(self->ui, printRight, curr->frequence);
	}
	if((1<<PINB7)==0 && (1<<PINB6)==1 && (1<<PINB4)==1){
		AFTER(MSEC(200), self, decreaseCurrent, 0);
	}
}

void startup(Statechanger *self, int num){

	SYNC(self->ui, init_program, NULL);
	ASYNC(self->left, Pulse, NULL);
	ASYNC(self->right, Pulse, NULL);
}
