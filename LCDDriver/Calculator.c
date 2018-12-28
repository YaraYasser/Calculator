
#include "Calculator.h"
#include "LCD.h"
		/* static variables*/
static uint8 LastChar = 0;
static uint8 arrLeftNo[NO_ARRAY_SIZE];
static short arrLeftNoPtrCounter = 0;
static short arrRightNo[NO_ARRAY_SIZE];
static short arrRightNoPtrCounter = 0;

uint8* Calc_vCalculate(uint8 parNo)
{	
	
	if(parNo == '=')
	{
		
		Calc_vOperate();
		return arrLeftNo;		
	}	
	
	else if((parNo == '+') || (parNo == '-') || (parNo == '/') || (parNo == '*'))
	{
		if (LastChar != 0)
		{
			Calc_vOperate();
		}
		LastChar = parNo;
	}
	else
	{
		if(LastChar == 0)
		{
			
			arrLeftNo[arrLeftNoPtrCounter] = parNo;
			arrLeftNoPtrCounter++;
		}
		
		else
		{
		  arrRightNo[arrRightNoPtrCounter] = (parNo - '0');
		  arrRightNoPtrCounter++;
		}
		
	}
	
	return NULLTER;	
}


void Calc_vOperate(){
 
 short arrFinalResult[NO_ARRAY_SIZE];
 short arrFinalResultPtrCounter = 19;
  if(arrRightNoPtrCounter != 0)
  {
	  arrRightNoPtrCounter--;
	  
  }
  
  if(arrLeftNoPtrCounter != 0)
  {
    arrLeftNoPtrCounter--;
    	  
  }


	if (LastChar == '+')
	{
		uint8 boolCarryFlag = 0;
	
				
		while((arrLeftNoPtrCounter >= 0) && (arrRightNoPtrCounter >= 0))
		{
			if(boolCarryFlag == 1){
				arrRightNo[arrRightNoPtrCounter] += 1;
				boolCarryFlag = 0; 
			}
			if((arrRightNo[arrRightNoPtrCounter] + (arrLeftNo[arrLeftNoPtrCounter] - '0')) > 9)
			{
					 arrFinalResult[arrFinalResultPtrCounter] = (arrRightNo[arrRightNoPtrCounter] + (arrLeftNo[arrLeftNoPtrCounter] - '0')) % 10;
					 arrFinalResultPtrCounter--;
					 boolCarryFlag = 1; 
			}
			else
			{
				arrFinalResult[arrFinalResultPtrCounter] = arrRightNo[arrRightNoPtrCounter] + (arrLeftNo[arrLeftNoPtrCounter] - '0');
				arrFinalResultPtrCounter--;
			}
			arrRightNoPtrCounter--;
			arrLeftNoPtrCounter--;
			if((arrRightNoPtrCounter == 0) || (arrLeftNoPtrCounter == 0))
			{
				break;
			}
		
		}
		
		if(boolCarryFlag == 1)
		{
			
			if(arrLeftNoPtrCounter > 0)
			{
				arrFinalResult[arrFinalResultPtrCounter] = (arrLeftNo[arrLeftNoPtrCounter] - '0') + 1;
				arrFinalResultPtrCounter--;
				arrLeftNoPtrCounter--;
			}
			else if (arrRightNoPtrCounter > 0)
			{
				arrFinalResult[arrFinalResultPtrCounter] = arrRightNo[arrRightNoPtrCounter] + 1;
				arrFinalResultPtrCounter--;
				arrRightNoPtrCounter--;
			}
			else
			{
			arrFinalResult[arrFinalResultPtrCounter] = 1;
			arrFinalResultPtrCounter--;	
			}
		}
		while(arrLeftNoPtrCounter >= 0)
		{
			
			arrFinalResult[arrFinalResultPtrCounter] = (arrLeftNo[arrLeftNoPtrCounter] - '0');
			
			arrFinalResultPtrCounter--;
			arrLeftNoPtrCounter--;
			
			
		}
		while(arrRightNoPtrCounter >= 0)
		{
			arrFinalResult[arrFinalResultPtrCounter] = arrRightNo[arrRightNoPtrCounter];
			arrFinalResultPtrCounter--;
			arrRightNoPtrCounter--;
		}
			
	}
	
	
	
	
	if (LastChar == '-')
	{
		if(arrRightNoPtrCounter <= arrLeftNoPtrCounter)
		{
				while((arrLeftNoPtrCounter >= 0) && (arrRightNoPtrCounter >= 0))
				{
					
					if((arrLeftNo[arrLeftNoPtrCounter] - '0') < arrRightNo[arrRightNoPtrCounter])
					{
						arrLeftNo[arrLeftNoPtrCounter-1] = (arrLeftNo[arrLeftNoPtrCounter] - '0') - 1;
						arrFinalResult[arrFinalResultPtrCounter] =  (10 + (arrLeftNo[arrLeftNoPtrCounter] - '0')) - arrRightNo[arrRightNoPtrCounter];
						arrFinalResultPtrCounter--;
						
					}
					else
					{
						arrFinalResult[arrFinalResultPtrCounter] = (arrLeftNo[arrLeftNoPtrCounter] - '0') - arrRightNo[arrRightNoPtrCounter];
						arrFinalResultPtrCounter--;
					}
					
					arrRightNoPtrCounter--;
					arrLeftNoPtrCounter--;
				}
				
				
				while(arrLeftNoPtrCounter >= 0)
				{
					
					arrFinalResult[arrFinalResultPtrCounter] = (arrLeftNo[arrLeftNoPtrCounter] - '0');
					arrFinalResultPtrCounter--;
					arrLeftNoPtrCounter--;
				}
				
		}
		
	}
	
	
	if (LastChar == '*')
	{
		uint8 CarryVal = 0;
		uint8 arrAddOne[20];
		uint8 arrAddOneCounter = 19;
		uint8 arrAddTwo[20];
		uint8 arrAddTwoCounter = 19;
		uint8 boolIsFirstMultLevel = 1;
		uint8 boolIsTwoResLevelFinished = 0;
		while(arrRightNoPtrCounter >= 0)
		{
			
			while(arrLeftNoPtrCounter >= 0)
			{    
				if (boolIsFirstMultLevel == 1)
				{
					if ((arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0'))> 10 )
					{
						CarryVal = (arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0')) % 100;
						arrAddOne[arrAddOneCounter] = (arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0')) % 10;
						arrAddOneCounter--;
						
					}
				}
				else
				{
					if ((arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0')) > 10 )
					{
						CarryVal = (arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0')) % 100;
						arrAddTwo[arrAddTwoCounter] = (arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0')) % 10;
						arrAddTwoCounter--;
						
					}
					
					boolIsTwoResLevelFinished = 1;
				}
			}
			if (boolIsTwoResLevelFinished == 1)
			{
				
			}
			boolIsFirstMultLevel = 0;
			arrAddTwo[arrAddTwoCounter] = 0;
			arrAddTwoCounter--;
			
		}
	}
	if (LastChar == '/')
	{
		
	}
	
    arrLeftNoPtrCounter = 0;
	arrFinalResultPtrCounter++;
	while(arrFinalResultPtrCounter < NO_ARRAY_SIZE)
	{
		arrLeftNo[arrLeftNoPtrCounter] = arrFinalResult[arrFinalResultPtrCounter] + '0';
		arrFinalResultPtrCounter++;
		arrLeftNoPtrCounter++;
	}
	arrLeftNo[arrLeftNoPtrCounter] = '\0';
	
}

