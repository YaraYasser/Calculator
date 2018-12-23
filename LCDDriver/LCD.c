#include "LCD.h"


static void setFallingEdge(void){
	DIO_vWrite(LCD_PORT,HIGH_VOLT,EN);
	
	_delay_ms(4);
	DIO_vWrite(LCD_PORT,LOW_VOLT,EN);
	
	_delay_ms(4);
	
}


#if defined LCD_4
void LCD_vSendCmd(char cmd){
	/* choose RS */
	CLR_BIT(PORTB,RS);
	/*most seg*/
	PORTA &= 0x0f;
	PORTA |= cmd & 0xf0;
	setFallingEdge();
	PORTA &= 0x0f;
	PORTA |= (cmd<<4);
	setFallingEdge();
	
}
void LCD_vInit(void){
	DDRA |= 0xf0;
	DDRB |= 0x0e;
	CLR_BIT(PORTB,RW);

	/* to let LCD work mode */
	LCD_vSendCmd(0x33);
	LCD_vSendCmd(0x32);
	LCD_vSendCmd(0x28);
	/* blink cursor*/
	LCD_vSendCmd(0x0F);
	
	/*Clear screen*/
	LCD_vSendCmd(0x01);
	_delay_ms(20);
}
void LCD_vPrintChar(char parData){
	SET_BIT(PORTB,RS);
	PORTA &= 0x0f;
	PORTA |= parData & 0xf0;
	setFallingEdge();
	PORTA &= 0x0f;
	PORTA |= (parData<<4);
	setFallingEdge();
}

void LCD_vPrintString(char* parStr){
	
	while(*parStr)
	{
		LCD_vPrintChar(*parStr);
		parStr++;
	}
}


#endif

void LCD_vMoveCursir(unsigned char row,unsigned char col){
	char temp;
	if((row < 2) && (col < 16))
	{
		if(row == 0)
		{
			temp = 0x80 + col;
			LCD_vSendCmd(temp);
		}
		else
		{
			temp = 0xc0 + col;
			LCD_vSendCmd(temp);
		}
	}
	
}

void LCD_vClearScreen(){
	LCD_vSendCmd(0x01);
	
}