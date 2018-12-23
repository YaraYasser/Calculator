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
 
				    /* Pin Direction Functions*/
				
void DIO_vSetPinDirection(uint8 parPortName,uint8 parDirection,uint8 parPinNo);
void DIO_vSetHighNibbleDirection(uint8 parPortName,uint8 parNibbleVoltType);
void DIO_vSetLowNibbleDirection(uint8 parPortName,uint8 parNibbleVoltType);
void DIO_vSetHighNibbleDirectionWithSpecificValue(uint8 parPortName,uint8 parValueToBeAdded);
void DIO_vSetLowNibbleDirectionWithSpecificValue(uint8 parPortName,uint8 parValueToBeAdded);

        /* Functions use Port & Pin for reading and writing */ 
			 
void DIO_vWrite(uint8 parPortName,uint8 parVoltType,uint8 parPinNum);
uint8 DIO_uint8Read(uint8 parPortName,uint8 parPinNum);
void DIO_vWriteDataInLCD(uint8 parPortName,uint8 parData);	
void DIO_vSetHighNibblePortWithHighNibbleData(uint8 parPortName,uint8 parData);
void DIO_vSetHighNibblePortWithLowNibbleData(uint8 parPortName,uint8 parData);
void DIO_vSetPort(uint8 parPortName);
#endif /* DIO_H_ */