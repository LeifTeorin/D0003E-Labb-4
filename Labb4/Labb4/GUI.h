#ifndef _GUI_
#define _GUI_

#include "Pulsegenerator.h"
#include "TinyTimber.h"

typedef struct{
	Object super;
	int[] characters;
}GUI;

#define initGUI()\
		{initObject(), {
			0x1551,		// 0
			0x0118,		// 1
			0x1e11,		// 2
			0x1b11,		// 3
			0x0b50,		// 4
			0x1b41,		// 5
			0x1f41,		// 6
			0x4009,		// 7
			0x1f51,		// 8
			0x1b51,		// 9
		}
	}