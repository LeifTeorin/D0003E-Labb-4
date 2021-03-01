#ifndef _STATECHANGER_
#define _STATECHANGER_

#include "Pulsegenerator.h"
#include "TinyTimber.h"
#include "GUI.h"

typedef struct{
	Object super;
	struct GUI *ui;
	struct Pulsegenerator *left;
	struct Pulsegenerator *right;
	struct Pulsegenerator *current;
}Statechanger;

#define initStatechanger(ui, left, right)\
			{initObject(), ui, left, right, left}
void increaseCurrent(Statechanger *self, int num);
void decreaseCurrent(Statechanger *self, int num);
void changeCurrenttoright(Statechanger *self, int num);
void changeCurrenttoleft(Statechanger *self, int num);
void changeCurrent(Statechanger *self, int num);
void saveCurrent(Statechanger *self, int num);

#endif