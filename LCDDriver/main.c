/*
 * LCDDriver.c
 *
 * Created: 12/22/2018 8:00:47 AM
 * Author : user
 */ 
#include "Main.h"
#include <avr/io.h>
#include <util/delay.h>

#include "KeyPadDriver.h"
#include "LCD.h"
#include "Calculator.h"



int main(void)
{
	keyPad_vIntial();
	
	LCD_vInit();
	LCD_vMoveCursir(0,1);
    uPtrInt8 displayedString;
	/* Replace with your application code */
    while (1) 
    {
			uint8 x = keyPad_vScan();
			if (NO_PRESS != x)
			{	
				if('=' == x)
				{
					LCD_vMoveCursir(1,1);
				displayedString = Calc_vCalculate(x);	
					//LCD_vPrintChar(*displayedString);
					LCD_vPrintString(displayedString);
					//LCD_vMoveCursir(0,1);
				}
				else if('A' == x)
				{
					LCD_vClearScreen();
					Calc_vClear();
				}
				else
				{
					Calc_vCalculate(x);
					LCD_vPrintChar(x);
				
				}
				_delay_ms(40);
			}
			
    }
}

