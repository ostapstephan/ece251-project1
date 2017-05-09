#include "bsp.h"
#include "InitDevice.h"
#include "disp.h"
#include "voltmeter.h"
#include <SI_EFM8BB3_Register_Enums.h>
//0.4 = TX
//0.5 = RX

//---------------------------------------------------------------------------
// main() Routine
// --------------------------------------------------------------------------
int main(void)
{
  // Enter default mode
  enter_DefaultMode_from_RESET();

  // Enable all interrupts
  IE_EA = 1;
  SCON0_TI = 1;
  P2_B2 = 0; //EFM8 does not control the UART
  DISP_Init();
  Voltmeter_main();

  while (1);
}
