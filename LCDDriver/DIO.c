#include "DIO.h"

void DIO_vSetPinDirection(uint8 parPortName,uint8 parDirection,uint8 parPinNo)
{
  switch(parPortName)
  {
	  case 'A':
		 if (OUTPUT == parDirection)
		{
			SET_BIT(DDRA,parPinNo);	
		}
		else
		{
			CLR_BIT(DDRA,parPinNo);
		}
	     
	  break;
	  
	  case 'B':
		 if (OUTPUT == parDirection)
	    {
		   SET_BIT(DDRB,parPinNo);
	    }
	     else
	    {
		   CLR_BIT(DDRB,parPinNo);
	    }
	  break;
	  
	  case 'C':
		 if (OUTPUT == parDirection)
	    {
		   SET_BIT(DDRC,parPinNo);
	    }
	     else
	    {
		   CLR_BIT(DDRC,parPinNo);
	    }
	  break;
	  
	  case 'D':
	   if (OUTPUT == parDirection)
	   {
		   SET_BIT(DDRD,parPinNo);
	   }
	   else
	   {
		   CLR_BIT(DDRD,parPinNo);
	   }
	  break;
  }	
}


void DIO_vSetHighNibbleDirection(uint8 parPortName,uint8 parNibbleVoltType)
{
	switch (parPortName)
	{
		case 'A':
		if(HIGH_VOLT == parNibbleVoltType){
			DDRA |= 0b11110000;
		}
		else{
			DDRA &= 0b00001111;
		}
		break;
		case 'B':
		if(HIGH_VOLT == parNibbleVoltType){
			DDRB |= 0b11110000;
		}
		else{
			DDRB &= 0b00001111;
		}
		break;
		case 'C':
		if(HIGH_VOLT == parNibbleVoltType){
			DDRC |= 0b11110000;
		}
		else{
			DDRC &= 0b00001111;
		}
		break;
		case 'D':
		if(HIGH_VOLT == parNibbleVoltType){
			DDRD|= 0b11110000;
		}
		else{
			DDRD &= 0b00001111;
		}
		break;
	}
	
}

void DIO_vSetLowNibbleDirection(uint8 parPortName,uint8 parNibbleVoltType){
switch (parPortName)
{
	case 'A':
	if (HIGH_VOLT == parNibbleVoltType)
	{
		DDRA |= 0b00001111;
	}
	else
	{
		DDRA &= 0b11110000;
	}
	break;
	case 'B':
	if (HIGH_VOLT == parNibbleVoltType)
	{
		DDRB |= 0b00001111;
	}
	else
	{
		DDRB &= 0b11110000;
	}
	break;
	case 'C':
	if (HIGH_VOLT == parNibbleVoltType)
	{
		DDRC |= 0b00001111;
	}
	else
	{
		DDRC &= 0b11110000;
	}
	break;
	case 'D':
	if (HIGH_VOLT == parNibbleVoltType)
	{
		DDRD |= 0b00001111;
	}
	else
	{
		DDRD &= 0b11110000;
	}
	break;
}
}

void DIO_vSetHighNibbleDirectionWithSpecificValue(uint8 parPortName,uint8 parValueToBeAdded){
	switch (parPortName)
	{
		case 'A':
		DDRA |= (parValueToBeAdded & 0b11110000);
		
		break;
		case 'B':
		DDRB |= (parValueToBeAdded & 0b11110000);
		break;
		case 'C':
		DDRC |= (parValueToBeAdded & 0b11110000);
		break;
		case 'D':
		DDRD |= (parValueToBeAdded & 0b11110000);
		break;
	}
}

void DIO_vSetLowNibbleDirectionWithSpecificValue(uint8 parPortName,uint8 parValueToBeAdded){
	switch (parPortName)
	{
		case 'A':
		DDRA |= (parValueToBeAdded & 0b00001111);
		
		break;
		case 'B':
		DDRB |= (parValueToBeAdded & 0b00001111);
		break;
		case 'C':
		DDRC |= (parValueToBeAdded & 0b00001111);
		
		break;
		case 'D':
		DDRD |= (parValueToBeAdded & 0b00001111);
		
		break;
	}
	
}

void DIO_vWrite(uint8 parPortName,uint8 parVoltType,uint8 parPinNum){
	
	switch (parPortName)
	{
		case 'A':
		if(HIGH_VOLT == parVoltType){
			SET_BIT(PORTA,parPinNum);
			
		}
		
		else{
			CLR_BIT(PORTA,parPinNum);
			
		}
		break;
		case 'B':
		if(HIGH_VOLT == parVoltType){
			SET_BIT(PORTB,parPinNum);
			
		}
		else{
			CLR_BIT(PORTB,parPinNum);
		}
		break;
		case 'C':
		if(HIGH_VOLT == parVoltType){
			SET_BIT(PORTC,parPinNum);
			
		}
		else{
			CLR_BIT(PORTC,parPinNum);
			
		}
		break;
		case 'D':
		if(HIGH_VOLT == parVoltType){
			SET_BIT(PORTD,parPinNum);
			
		}
		else{
			CLR_BIT(PORTD,parPinNum);
			
		}
		break;
	}
}

uint8 DIO_uint8Read(uint8 parPortName,uint8 parPinNum){
	switch (parPortName)
	{
		case 'A':
		return READ_BIT(PINA,parPinNum);
		break;
		case 'B':
		return READ_BIT(PINB,parPinNum);
		break;
		case 'C':
		return READ_BIT(PINC,parPinNum);
		break;
		case 'D':
		return READ_BIT(PIND,parPinNum);
		break;
		
	}
	return 0;
}


void DIO_vWriteDataInLCD(uint8 parPortName,uint8 parData){
	switch (parPortName)
	{
		case 'A':
			PORTA = parData;
		break;
		
		case 'B':
			PORTB = parData;
		break;
		
		case 'C':
			PORTC = parData;
		break;
		
		case 'D':
			PORTD = parData;
		break;
	}
}

void DIO_vSetHighNibblePortWithHighNibbleData(uint8 parPortName,uint8 parData)
{
 switch(parPortName)
 {
	 case 'A':
		 PORTA &= 0x0f;
		 PORTA |= parData & 0xf0;	 
	 break;
	 
	 case 'B':
		 PORTB &= 0x0f;
		 PORTB |= parData & 0xf0;
	 
	 break;
	 
	 case 'C':
		PORTC &= 0x0f;
		PORTC |= parData & 0xf0;
	 break;
	 
	 case 'D':
		PORTD &= 0x0f;
		PORTD |= parData & 0xf0;
	 break;
 }	
}

void DIO_vSetHighNibblePortWithLowNibbleData(uint8 parPortName,uint8 parData)
{
	switch(parPortName)
	{
		case 'A':
			PORTA &= 0x0f;
			PORTA |= (parData<<HALF_REGESTER_SIZE);
		break;
		
	    case 'B':
			PORTB &= 0x0f;
			PORTB |= (parData<<HALF_REGESTER_SIZE);
		break;
		
		case 'C':
			PORTC &= 0x0f;
			PORTC |= (parData<<HALF_REGESTER_SIZE);
		break;
		
		case 'D':
			PORTD &= 0x0f;
			PORTD |= (parData<<HALF_REGESTER_SIZE);
		break;
	}
	
}

void DIO_vSetPort(uint8 parPortName){
	switch (parPortName)
	{
		case 'A':
		PORTA = 0xff;
		break;
		case 'B':
		PORTB = 0xff;
		break;
		case 'C':
		PORTC = 0xff;
		break;
		case 'D':
		PORTD = 0xff;
		break;
		
	}
}
