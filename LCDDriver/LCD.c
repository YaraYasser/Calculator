#include "LCD.h"


static void setFallingEdge(void){
	DIO_vWrite(LCD_PORT,HIGH_VOLT,EN);
	
	_delay_ms(4);
	DIO_vWrite(LCD_PORT,LOW_VOLT,EN);
	
	_delay_ms(4);
	
}

#if defined LCD_8
void LCD_vSendCmd(char cmd){
	/* put data in port*/
	DIO_vWriteDataInLCD(LCD_DATA_PORT,cmd);
	/* choose RS */
	DIO_vWrite(LCD_PORT,LOW_VOLT,RS);
	/*send falling edge*/
	setFallingEdge();
}
void LCD_vInit(void){
	DIO_vSetLowNibbleDirection(LCD_DATA_PORT,SET_ALL_PORT_HIGH);
	DIO_vSetHighNibbleDirection(LCD_DATA_PORT,SET_ALL_PORT_HIGH);
	DIO_vSetLowNibbleDirection(LCD_PORT,0x0e);
	
	DIO_vWrite(LCD_PORT,LOW_VOLT,RW);
	
	/* to let LCD work mode */
	LCD_vSendCmd(0x38);
	
	/* blink cursor*/
	LCD_vSendCmd(0x0F);
	
	/*Clear screen*/
	LCD_vSendCmd(0x01);
	_delay_ms(20);
}
void LCD_vPrintChar(char parData){
	DIO_vWrite(LCD_PORT,HIGH_VOLT,RS);
	
	DIO_vWriteDataInLCD(LCD_DATA_PORT,parData);
	
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

#if defined LCD_4
void LCD_vSendCmd(char cmd){
	/* choose RS */
	DIO_vWrite(LCD_PORT,LOW_VOLT,RS);
	
	DIO_vSetHighNibblePortWithHighNibbleData(LCD_DATA_PORT,cmd);
	setFallingEdge();
	DIO_vSetHighNibblePortWithLowNibbleData(LCD_DATA_PORT,cmd);
	setFallingEdge();
	
}
void LCD_vInit(void){
	DIO_vSetHighNibbleDirection(LCD_DATA_PORT,0xf0);
	DIO_vSetLowNibbleDirection(LCD_PORT,0x0e);
	DIO_vWrite(LCD_PORT,LOW_VOLT,RW);

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
	DIO_vWrite(LCD_PORT,HIGH_VOLT,RS);
	
	DIO_vSetHighNibblePortWithHighNibbleData(LCD_DATA_PORT,parData);
	setFallingEdge();
	DIO_vSetHighNibblePortWithLowNibbleData(LCD_DATA_PORT,parData);
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