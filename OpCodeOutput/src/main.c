
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                // SFR declarations
#include "InitDevice.h"
//initialize pins

///////////////////////////////////////////////////////////////////////////////
// Supporting Functions
///////////////////////////////////////////////////////////////////////////////
static const int DELAY = 25000;

static void setOpPins(char * operation) {
	if (operation == "ADD") {
		P0_B0 = 0;
		P0_B1 = 0;
	}
	else if (operation == "OR") {
		P0_B0 = 0;
		P0_B1 = 1;
	}
	else if (operation == "AND") {
		P0_B0 = 1;
		P0_B1 = 0;
	}
}

static void setDataPins(int i) {
	//assume i is a decimal integer less than 32
	int remainder;
	int data[4];
	int index = 0;
	//converts decimal to binary
	while(i != 0) {
		remainder = i%2;
		i = i/2;
		data(index) = remainder;
		index++;
	}
	//sets data pins
	P0_B2 = data[0]; //least significant bit
	P0_B3 = data[1];
	P0_B4 = data[2];
	P0_B5 = data[3];
}

static void clock() {
	P0_B6 = 1;
	delay();
	P0_B6 = 0;
	delay();
}

static void delay() {
	for (int x = 0; x < DELAY; x++) {}
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------

int main (void)
{
	XBR2 |= 0x40; //Enable Crossbar so we can easily turn pins on and off.

	setDataPins(2);
	while (1) {
		//if button pressed

			//execute list of operations


	}
}
