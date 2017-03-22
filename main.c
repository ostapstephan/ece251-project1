
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                // SFR declarations

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------

int main (void)
{
	static DELAY = 10000;
	int x,y;

	XBR2 |= 0x40; //Enable Crossbar so we can easily turn pins on and off.

	while (1) {
		if (P0_B2 == 0) {
			//increase delay amount
			DELAY += 200;
		}
		else if (P0_B3 == 0) {
			//decrease delay amount
			DELAY -= 200;
		}
		//go high
		P1_B4 = 0;
		//delay
		for (x = 0; x < DELAY; x++) {}
		//go low
		P1_B4 = 1;
		//delay
		for (y = 0; y < DELAY; y++) {}
	}
}
