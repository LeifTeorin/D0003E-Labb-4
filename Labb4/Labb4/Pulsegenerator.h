#ifndef _PULSEGENERATOR_H_
#define _PULSEGENERATOR_H_
#include "TinyTimber.h"
#include "Writer.h"
#include "GUI.h"

typedef struct{
	Object super;
	int pos;
	int frequence;
	int saved;
	int bitnr;
	int boo;
	struct Writer *shakespear;
	struct GUI *ui
	} Pulsegenerator;

#define initPulsegenerator(pos, bitnr, shakespear, ui)\
		{initObject(), pos, 0, 0, bitnr, 0, shakespear, ui}

void increase(Pulsegenerator *self, int num);
void decrease(Pulsegenerator *self, int num);
void Pulse(Pulsegenerator *self, int num);
void save(Pulsegenerator *self, int num);

#endif