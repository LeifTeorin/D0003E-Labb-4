#ifndef _WRITER_
#define _WRITER_

#include "Pulsegenerator.h"
#include "TinyTimber.h"

typedef struct{
	Object super;
	
}Writer;

#define initWriter()\
			{initObject()}