/*
 * DIO.h
 *
 * Created: 12/22/2018 3:44:47 PM
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>
#include "Main.h"
#include "macros.h"
 /*public variables*/
#define OUTPUT 1
#define HIGH_VOLT 1	
#define LOW_VOLT 0
 /*Functions ProtoType*/
void DIO_vSetPinDirection(uint8 parPortName,uint8 parDirection,uint8 parPinNo);
void DIO_vSetHighNibbleDirection(uint8 PortName,uint8 parValueToBeAdded);
void DIO_vSetLowNibbleDirection(uint8 PortName,uint8 parValueToBeAdded);
void DIO_vWrite(uint8 parPortName,uint8 parVoltType,uint8 parPinNum);
uint8 DIO_uint8Read(uint8 PortName,uint8 PinNum);
void DIO_vWriteDataInLCD(uint8 parPortName,uint8 parData);	
void DIO_vSetHighNibblePortWithHighNibbleData(uint8 parPortName,uint8 parData);
void DIO_vSetHighNibblePortWithLowNibbleData(uint8 parPortName,uint8 parData);
void DIO_vSetPort(uint8 PortName);
#endif /* DIO_H_ */