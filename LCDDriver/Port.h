/*
 * Port.h
 *
 * Created: 12/22/2018 8:48:07 AM
 *  Author: user
 */ 


#ifndef PORT_H_
#define PORT_H_

#define RS 1
#define RW 2
#define EN 3
		/*LCD */
#define LCD_PORT 'B'
#define LCD_DATA_PORT 'A'   
		/*Key Pad */
#define KEY_PAD_PORT 'C'
#define KEY_PAD_DDR 'C'
#define KEY_PAD_PIN PINC

#endif /* PORT_H_ */