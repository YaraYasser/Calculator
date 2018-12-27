
#include "Calculator.h"

		/* static variables*/
static uint8 LastPressedIsNumber = 0;
static uint8 LastChar = 0;
static uint8 finalResult = 0;

uint8 Calc_vCalculate(uint8 parNo)
{	
	if(parNo == '=')
	{
		return finalResult;		
	}	
	
	else if((parNo == '+') || (parNo == '-') || (parNo == '/') || (parNo == '*'))
	{
		LastChar = parNo;
		LastPressedIsNumber = 0;
	}
	else
	{
		if(LastPressedIsNumber == 1)
		{
			finalResult *= 10;
			finalResult += (LastChar - '0');
		
		}
		else
		{
		  if(LastChar == 0)
		  {
			finalResult = (parNo - '0');
		  }
		  else
		  {
		    Calc_vOperate(parNo);
		  }
		  
		}
		LastChar = parNo;
		LastPressedIsNumber = 1;
	}
	return RESULT_NOT_REQUIRED;	
}


void Calc_vOperate(uint8 parNo){
	
	if (LastChar == '+')
	{
		finalResult += (parNo - '0');
	}
	if (LastChar == '-')
	{
		finalResult -= (parNo - '0');
	}
	if (LastChar == '*')
	{
		finalResult *= (parNo - '0');
	}
	if (LastChar == '/')
	{
		finalResult /= (parNo - '0');
	}
	
}

