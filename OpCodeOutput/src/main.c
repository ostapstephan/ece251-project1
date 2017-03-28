
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                // SFR declarations
#include "InitDevice.h"
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
// Supporting Functions
///////////////////////////////////////////////////////////////////////////////
const int DELAY = 25000;

 void setOpPins(char * operation) {
	if (strcmp(operation,"SUM")) {
		P0_B0 = 0;
		P0_B1 = 0;
	}
	else if (strcmp(operation, "OR")) {
		P0_B0 = 0;
		P0_B1 = 1;
	}
	else if (strcmp(operation, "AND")) {
		P0_B0 = 1;
		P0_B1 = 0;
	}
	else if (strcmp(operation,"RESET")) {
		P0_B0 = 1;
		P0_B1 = 1;
	}
 }

 void setDataPins(int i) {
	//assume i is a decimal integer less than 32
	 int r = 0;
	 int d[4]={0,0,0,0};
	 int index=0;
	//converts decimal to binary
	while(i != 0) {
		r = i%2;
		i = i/2;
		d[index] = r;
		index++;
	}
	//sets data pins
	P0_B4 = d[0]; //least significant bit
	P0_B5 = d[1];
	P0_B6 = d[2];
	P0_B7 = d[3];
}

 void ourDelay() {
	 int x;
	for (x = 0; x < DELAY; x++) {}
}

 void clockPulse() {
	ourDelay();
	P1_B0 = 1;
	ourDelay();
	P1_B0 = 0;
	ourDelay();
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------

int main (void)
{
	enter_DefaultMode_from_RESET();
	XBR2 |= 0x40; //Enable Crossbar so we can easily turn pins on and off.

	setDataPins(2);
	while (1) {
		if (P0_B2 == 0) {
			setOpPins("RESET");
			clockPulse();
			setOpPins("SUM");
			clockPulse();
			setOpPins("AND");
			clockPulse();
			setOpPins("RESET");
			clockPulse();
		}
	}
}
