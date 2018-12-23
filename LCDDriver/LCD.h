/*
 * LCD.h
 *
 * Created: 12/22/2018 8:03:13 AM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#include <util/delay.h>

#include "Main.h"
#include "Port.h"
#include "macros.h"
#include "DIO.h"
#define INSTRUCTION_MODE 0 
#define DATA_MODE 1
#define WRITE 0
#define NULLTER '\0'
#define SET_ALL_PORT_HIGH 0xff
#if defined LCD_8
void LCD_vSendCmd(char cmd);
void LCD_vInit(void);
void LCD_vPrintChar(char parData);
void LCD_vPrintString(char* parStr);
void LCD_vClearScreen();
void LCD_vMoveCursir(unsigned char row,unsigned char col);
#endif

#if defined LCD_4
void LCD_vSendCmd(char cmd);

void LCD_vInit(void);
void LCD_vPrintChar(char parData);
void LCD_vPrintString(char* parStr);
void LCD_vClearScreen();
void LCD_vMoveCursir(unsigned char row,unsigned char col);
#endif



#endif /* LCD_H_ */