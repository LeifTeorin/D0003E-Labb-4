#include "TinyTimber.h"
#include "GUI.h"

#include <avr/io.h>
#include <avr/portpins.h>
#include <stdint.h>

int characters[10] = {0x1551,		// 0
	0x0118,		// 1
	0x1e11,		// 2
	0x1b11,		// 3
	0x0b50,		// 4
	0x1b41,		// 5
	0x1f41,		// 6
	0x4009,		// 7
	0x1f51,		// 8
	0x1b51		// 9
	};

void writeChar(GUI *self, char ch, int pos){
	if((pos>5) | (pos<0)){
		return;
	}
	int shift;
	char mask_reg;
	char currbyte = 0x00;
	int character = 0;
	char *ptr;
	ptr  = &LCDDR0; // pekaren b�rjar p� lcddr0
	
	if((int)ch > -1 && (int)ch < 10){
		character = characters[(int)ch];
	}
	
	
	if(pos & 0x01){ // om pos �r udda finns det en etta p� slutet, d� ska den skrivas p� de fyra bitarna till v�nster p� registren
		mask_reg = 0x0f;
		shift = 4; // bitarna som ska skrivas beh�ver �ven flyttas f�r att skrivas p� v�nster sida
		}else{
		mask_reg = 0xf0;
		shift = 0;
	}
	ptr = ptr + (pos>>1); // pekaren hamnar p� lcddr0, 1 eller 2 beroende p� pos
	
	for(int i = 0; i < 4; i++){
		currbyte = (character & 0x0f); // vi tar de 4 bittarna l�ngst till h�ger
		currbyte = currbyte << shift; // bittarna shiftas antingen 0 eller 4 steg �t v�nster
		*ptr = ((*ptr & mask_reg)|currbyte); // registret maskas och fylls sedan in med de bittarna vi h�mtat
		character = (character>>4); // vi tar bort de 4 bittarna till h�ger
		ptr += 5; // pekaren g�r fem register fram f�r n�sta 4 bittar
	}
}

void printAt(GUI *self, long num, int pos) {
	int pp = pos;
	//SYNC(self, writeChar, (((num % 100) / 10), pp));
	writeChar(self, ((num % 100) / 10), pp); // �ndra detta till sync sen, s� den blir l�st
	pp++;
	//SYNC(self, writeChar, ((num % 10), pp));
	writeChar(self, (num % 10), pp); // �ndra detta till sync sen, s� den blir l�st
}

void printLeft(GUI *self, long num) {
	writeChar(self, ((num % 100) / 10), 0); // �ndra detta till sync sen, s� den blir l�st
	writeChar(self, (num % 10), 1); // �ndra detta till sync sen, s� den blir l�st
}

void printRight(GUI *self, long num) {
	writeChar(self, ((num % 100) / 10), 4); // �ndra detta till sync sen, s� den blir l�st
	writeChar(self, (num % 10), 5); // �ndra detta till sync sen, s� den blir l�st
}

void init_program(GUI *self){
	LCDCRA |= 0x80; // LCD enable
	LCDCRB = 0xb7; // 1/3 bias och 1/4 duty, asynk-klockan anv�nds och 25 segment anv�nds
	LCDCCR |= 15; // s�tter kontrastkontrollen till 3,35 V
	LCDFRR = 7;	// s�tter prescalern och ger framerate 32 Hz
	
	EIMSK = 0x80;
	PCMSK1 = 0x80;
	TCCR1A = 0xC0;
	TCCR1B = 0x18;
	
	CLKPR = 0x80;
	CLKPR = 0x00;
	
	SYNC(self, printRight, 0);
	SYNC(self, printLeft, 0);
//	printLeft(self, 0);
//	printRight(self, 0);
}