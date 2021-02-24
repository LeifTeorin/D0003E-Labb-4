#ifndef _PULSEGENERATOR_H_
#define _PULSEGENERATOR_H_
#include "TinyTimber.h"

typedef struct{
	Object super;
	int frequence;
	int saved;
	int bitnr;
	int boo;
	} Pulsegenerator;

#define initPulsegenerator(int bitnr)\
		{initObject(), 0, 0, bitnr, 0}

void increase(Pulsegenerator *self, int num);
void decrease(Pulsegenerator *self, int num);
void Pulse(Pulsegenerator *self, int num);