#include <avr/io.h>
#include "Pulsegenerator.h"
#include "Statechanger.h"
#include "TinyTimber.h"
#include "GUI.h"
#include <avr/interrupt.h>


void changeCurrenttoright(Statechanger *self, int num){
	*(self->current) = self->right;
}

void changeCurrenttoleft(Statechanger *self, int num){
	*(self->current) = self->left;
}

void increaseCurrent(Statechanger *self, int num){
	while((PINB >> 6)==0){
		ASYNC(self->current, increase, (self->current, num));
		if(self->current->pos == 0){
			SYNC(&(self->current), printLeft, self->current->frequence);
		}else{
			SYNC(&(self->current), printRight, self->current->frequence);
		}
		//increase(self->current, num);
		//ASYNC(&(self->ui), printAt, (&(self->ui), self->current->frequence, self->current->pos));
		//printAt(&(self->ui), self->current->frequence, current->pos);
	}
}

void decreaseCurrent(Statechanger *self, int num){
	while((PINB >> 7) == 0){
		ASYNC(self->current, decrease, num); // vi tar och spawnar en decrease
		//decrease(self->current, num);
		if(self->current->pos == 0){
			SYNC(&(self->current), printLeft, self->current->frequence); // synka s� att inget g�r fel
		}else{
			SYNC(&(self->current), printRight, self->current->frequence);
		}
	}
}