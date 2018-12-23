#include "KeyPadDriver.h"


void keyPad_vIntial(void){
	DIO_vSetHighNibbleDirection(KEY_PAD_DDR,0);
	DIO_vSetLowNibbleDirection(KEY_PAD_DDR,1);
	DIO_vSetPort(KEY_PAD_PORT);
}
uint8 keyPad_vScan(void){
	int rows,col;
	const char arr[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	for(rows = 0;rows<=3 ;rows ++)
	{
		// put it as macros for putting port pins  to 1 ? as it deals directly with micro controller
		DIO_vSetPort(KEY_PAD_PORT);
		CLR_BIT(PORTC,rows);
		for(col = 4;col<=7;col++)
		{
			
			if(0 == READ_BIT(KEY_PAD_PIN,col)){
					
					return arr[rows][col-4];
				
			}
		}
		
	}
	
	return NO_PRESS;
}