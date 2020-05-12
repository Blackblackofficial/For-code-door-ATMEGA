#ifndef LCD_BACKLIGH_H
#define LCD_BACKLIGH_H

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>

//Slowly turns on the lcd backlight
//nice smooth turn on like mobile phones
void BackLightOn();

//Slowly turns off the lcd backlight
void BackLightOff();

#endif
