#include "KeyPadDriver.h"


void keyPad_vIntial(void){
	DIO_vSetHighNibbleDirection(KEY_PAD_DDR,INPUT);
	DIO_vSetLowNibbleDirection(KEY_PAD_DDR,OUTPUT);
	DIO_vSetPort(KEY_PAD_PORT);
}
uint8 keyPad_vScan(void){
	int row,col;
	const char arr[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	for(row = WRITE_START_PIN;row <= WRITE_END_PIN ;row ++)
	{
		// put it as macros for putting port pins  to 1 ? as it deals directly with micro controller
		DIO_vSetPort(KEY_PAD_PORT);
		CLR_BIT(PORTC,row);
		for(col = READ_START_PIN;col <= READ_END_PIN;col++)
		{
			
			if(BUTTON_IN_COL_PRESSED == READ_BIT(KEY_PAD_PIN,col)){
					                                              
					return arr[row][col - READ_START_PIN];            
				
			}
		}
		
	}
	
	return NO_PRESS;
}