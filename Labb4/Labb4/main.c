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
Pulsegenerator left = initPulsegenerator(0, 4, &writer);
Pulsegenerator right = initPulsegenerator(4, 6, &writer);
//Statechanger coupdetat = initStatechanger(ui, left, right);
//Inputs handler = initInputs(coupdetat);


int main(void)
{
	init_program(&ui);
	increase(&right, 0);
	increase(&left, 0);
	increase(&left, 0);
	increase(&left, 0);
	increase(&left, 0);
	increase(&left, 0);
	tinytimber(&left, Pulse, 0);
	//ASYNC(&right, Pulse, 0);
	//ASYNC(&left, Pulse, 0);
//	Pulse(&left, 0);
	
	
	
    while (1) 
    {
		
    }
}

