#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#include "keypad.h"

#define KEYPAD_PORT PORT(KEYPAD)
#define KEYPAD_DDR   DDR(KEYPAD)
#define KEYPAD_PIN   PIN(KEYPAD)

uint8_t GetKeyPressed()
{
      uint8_t r,c;

      KEYPAD_PORT|= 0X0F;
	  

      for(c=0;c<4;c++)
      {
         KEYPAD_DDR&=~(0XFF);

         KEYPAD_DDR|=(0X80>>c);
         for(r=0;r<4;r++)
         {
            if(!(KEYPAD_PIN & (0X08>>r)))
            {
               return (r*4+c);
            }
         }
      }
	  return 0XFF;//Indicate No key pressed
}

