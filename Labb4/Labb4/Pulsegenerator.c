#include <avr/io.h>

void Pulse(int x, int f)
{
	x = !x;
	if(x)
	{
		//send io 3.3V
	}
	else
	{
		//send io 0V
	}
	//Pulse with a timer
}