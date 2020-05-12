#include <avr/io.h>
#include <inttypes.h>

#include "lcd.h"
#include "keypad.h"
#include "user_interface.h"

uint16_t InputNumber(char *msg)
{
	uint8_t keyCode,x,pos;
	uint8_t prev_key=0xFF;

		
	while(1)
	{
		x=0;
		pos=6;

		LCDClear();
		LCDWriteStringXY(0,0,msg);
		LCDGotoXY(6,1);
	
		uint8_t key[]="####";
 
		
		uint8_t system_reset=0;
		uint16_t backlight_timeout=8000;

    	while(!system_reset)
    	{
			
			if(backlight_timeout>0)
			{
				backlight_timeout--;

				if(backlight_timeout==0)
				{
					LCDBacklightOff();
				}

			}

			
			
		
			keyCode=GetKeyPressed(); 							//Get the keycode of pressed key

			if(keyCode==prev_key)
				continue;
			else if(keyCode==0xFF)
			{
				prev_key=0xFF;
				continue;
			}
			else
			{
				prev_key=keyCode;
			}
				

			if(keyCode!=0xFF)
			{
				LCDBacklightOn();
				backlight_timeout=8000;
			}

			//_delay_ms(200); 									//key debouncing delay

			if(pos==10)
			{
				//Wait for enter key or reset key
				while(1)
				{
					keyCode=GetKeyPressed();
					if(keyCode==4)
					{
						//Enter key
						break;
					}
				
				}
				
				//Convert pass to a single integer
				return(((1000*key[0])+(100*key[1])+(10*key[2])+key[3]));		//save the password in 16 bit integer
			
				LCDClear();

				


			}

			switch (keyCode) 									//generating key characeter to display on LCD
		 	{
				case (11): 
					LCDWriteStringXY(pos,1,"*");
					key[x]=1;
					++x;
		 			pos++;
					break;
			
			
				case (10): 
					LCDWriteStringXY(pos,1,"*");
					key[x]=2;
		     		++x;
					pos++;
				break;
			
				case (9): 
					LCDWriteStringXY(pos,1,"*");
					key[x]=3;
		           	++x;
				 	pos++;
				break;
			
				case (7): 
				LCDWriteStringXY(pos,1,"*");
		           	key[x]=4;
		           	++x;
				 	pos++;
				break;
			
				case (6): 
					LCDWriteStringXY(pos,1,"*");
		           	key[x]=5;
		           	++x;
				 	pos++;
				break;
			
				case (5): 
					LCDWriteStringXY(pos,1,"*");
		           	key[x]=6;
		           	++x;
					pos++;
				break;
			
				case (3): 
					LCDWriteStringXY(pos,1,"*");
		          	key[x]=7;
		           	++x;
					pos++;
				break;

				case (2): 
					LCDWriteStringXY(pos,1,"*");
		           	key[x]=8;
		           	++x;
				 	pos++;
				break;
			
				case (1): 
					LCDWriteStringXY(pos,1,"*");
		           	key[x]=9;
		           	++x;
				 	pos++;
				break;

				case (14): 
					LCDWriteStringXY(pos,1,"*");
		           	key[x]=0;
		           	++x;
				 	pos++;
				break;

				case (8): 
					system_reset=1;
					
					break;
					
				default: ;

			}

			_delay_loop_2(1600);

		}	
	}		
}
