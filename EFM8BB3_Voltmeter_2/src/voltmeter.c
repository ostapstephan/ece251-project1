
#include "bsp.h"
#include "tick.h"
#include "disp.h"
#include "render.h"
#include "voltmeter.h"
#include "joystick.h"
#include "adc.h"
#include "thinfont.h"
#include "dpad_n.h"
#include "stdio.h"
#include "../lib/bsp/efm8_retargetserial/retargetserial.h"
//#include "retargetserial.h"
// Generic line buffer
SI_SEGMENT_VARIABLE(Line[DISP_BUF_SIZE], uint8_t, RENDER_LINE_SEG);

//unsigned char* inputcharacter;
unsigned char c;
const int w = 20;
//const int h = 10;
int x = 0;
int y = 0;
char xdata chars[20] = {0};
int i,j;

// ADC input: joystick or external
bool adcInput;
#define ADCINPUT_JOYSTICK 0
#define ADCINPUT_EXTERNAL 1

// Flag to update the ADC input text on the screen.
uint8_t updateAdcInput;
#define UPDATEADCINPUT_NO  0
#define UPDATEADCINPUT_YES 1

void drawScreenText(SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG), uint8_t rowNum, uint8_t fontScale)
{
  uint8_t i, j;

  for (i = 0; i < FONT_HEIGHT; i++)
  {
    RENDER_ClrLine(Line);
    RENDER_Large_StrLine(Line, 4, i, (SI_VARIABLE_SEGMENT_POINTER(, char, RENDER_STR_SEG))str, fontScale);

    for (j = 1; j < fontScale + 1; j++)
    {
      DISP_WriteLine(rowNum + (i * fontScale) + j, Line);
    }
  }
}

void Voltmeter_main(void)
{
  //uint32_t adcVoltage = 0;

	  SCON0_TI = 1;


  // Begin demo
  while(1)
  {

	drawScreenText("Enter character: ", 12, FONT_SCALE_DEFAULT);
	c = getchar();

	chars[x] = c;
	x++;
	if (x >= w) {
		x = 1;
		i++;
		for (j = 1; j < w; j++) {
			chars[j] = 0;
		}
		chars[0] = c;
	}
	drawScreenText(chars, 12*(i+2), FONT_SCALE_DEFAULT);
  }
}
