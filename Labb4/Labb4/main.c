/*
 * Labb4.c
 *
 * Created: 2021-02-22 10:36:20
 * Author : hjall and crill
 */ 

#include <avr/io.h>
#include "GUI.h"
#include "Pulsegenerator.h"
#include "Writer.h"
#include "Statechanger.h"
#include "TinyTimber.h"
#include "Inputs.h"


GUI ui = initGUI();
Writer writer = initWriter();
Pulsegenerator left = initPulsegenerator(0, 4, &writer, &ui);
Pulsegenerator right = initPulsegenerator(4, 6, &writer, &ui);
Inputs handler = initInputs(&left, &right);


int main(void)
{
	init_program(&ui);
//	increase(&right, 0);
//	increase(&left, 0);
//	increase(&left, 0);
//	increase(&left, 0);
	INSTALL(&handler, checkInputs, IRQ_PCINT1);
	INSTALL(&handler, checkSideways, IRQ_PCINT0);
//	startup(&coupdetat, 0);
//	tinytimber(&left, Pulse, 0);
//	tinytimber(&right, Pulse, 0);
//	tinytimber(&coupdetat, startup, 0);
//	tinytimber(&ui, init_program, 0);
	tinytimber(&handler, initialize, NULL);
//	increase(&right, 0);
//	increase(&left, 0);
//	increase(&left, 0);
	
	
    while (1) 
    {
		
    }
}

