
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                // SFR declarations
#include "InitDevice.h"
#include <string.h>

<<<<<<< HEAD
extern void WDT_0_enter_DefaultMode_from_RESET(void) {
	// $[WDTCN - Watchdog Timer Control]
	SFRPAGE = 0x00;
	//Disable Watchdog with key sequence
	WDTCN = 0xDE; //First key
	WDTCN = 0xAD; //Second key
	// [WDTCN - Watchdog Timer Control]$

}

=======
>>>>>>> 761f6cccda0196bb932eb2af51c0029e5c02297c
///////////////////////////////////////////////////////////////////////////////
// Supporting Functions
///////////////////////////////////////////////////////////////////////////////
const int DELAY = 25000;

<<<<<<< HEAD
 void setOpPins(int i) {
	if (i == 1) { //sum
		P0_B0 = 1;
		P0_B1 = 1;
	}
	else if (i == 2) { //or
		P0_B0 = 1;
		P0_B1 = 0;
	}
	else if (i == 3) { //and
		P0_B0 = 0;
		P0_B1 = 1;
	}
	else if (i == 4) { //reset
		P0_B0 = 0;
		P0_B1 = 0;
	}
=======
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
>>>>>>> 761f6cccda0196bb932eb2af51c0029e5c02297c
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

<<<<<<< HEAD
 void delay1() {
=======
 void ourDelay() {
>>>>>>> 761f6cccda0196bb932eb2af51c0029e5c02297c
	 int x;
	for (x = 0; x < DELAY; x++) {}
}

 void clockPulse() {
<<<<<<< HEAD
	P1_B0 = 0;
	delay1();
	P1_B0 = 1;
	delay1();
	P1_B0 = 0;
=======
	ourDelay();
	P1_B0 = 1;
	ourDelay();
	P1_B0 = 0;
	ourDelay();
>>>>>>> 761f6cccda0196bb932eb2af51c0029e5c02297c
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------

int main (void)
{
<<<<<<< HEAD
	WDT_0_enter_DefaultMode_from_RESET();
	enter_DefaultMode_from_RESET();
	XBR2 |= 0x40; //Enable Crossbar so we can easily turn pins on and off.

	setDataPins(1);
	setOpPins(4); //Resets LEDs
	clockPulse();
	setOpPins(1); //sets operation to SUM

	while (1) {
		if (P0_B2 == 0) {
			int i;
			for (i = 0; i < 15; i++) {
				clockPulse();
			}
			delay1();
			delay1();
			delay1();
=======
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
>>>>>>> 761f6cccda0196bb932eb2af51c0029e5c02297c
		}
	}
}
