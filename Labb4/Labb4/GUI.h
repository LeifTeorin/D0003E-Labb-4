#ifndef _GUI_
#define _GUI_

#include "Pulsegenerator.h"
#include "TinyTimber.h"

typedef struct{
	Object super;
//	int[] characters;
}GUI;

#define initGUI()\
		{initObject()}
	
void printAt(GUI *self, long num, int pos);
void writeChar(GUI *self, char ch, int pos);
void init_program(GUI *self);
void printLeft(GUI *self, int num);
void printRight(GUI *self, int num);

#endif