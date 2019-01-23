
#include "Calculator.h"
#include "LCD.h"
/* static variables*/
static uint8 LastOperator = 0;
static uint8 arrLeftNo[NO_ARRAY_SIZE];
static short arrLeftNoPtrCounter = 0;
static uint8 arrRightNo[NO_ARRAY_SIZE];
static short arrRightNoPtrCounter = 0;
static uint8 arrAddOne[20];
static uint8 arrAddOneCounter = 19;
static uint8 arrAddTwo[20];
static uint8 arrAddTwoCounter = 18;
static short endOfArrSizeLeftOperand = 0;	
static short endOfArrSizeRightOperand = 0;

short Calc_vAddition(uPtrInt8 arrLeft,short arrLeftCounter,uPtrInt8 arrRight,short arrRightCounter,uPtrInt8 res,short resCounter)
{
	uint8 boolCarryFlag = 0;	
	short endOfArrSize;
	if(endOfArrSizeLeftOperand <= endOfArrSizeRightOperand)
	{
		endOfArrSize = endOfArrSizeLeftOperand;
	}
	else
	{
		endOfArrSize = endOfArrSizeRightOperand;
	}
	while((arrLeftCounter >= endOfArrSize) && (arrRightCounter >= endOfArrSize))
	{
				
		if(boolCarryFlag == 1){
			arrRight[arrRightCounter] += 1;
			boolCarryFlag = 0;
		}
		if((arrRight[arrRightCounter] + (arrLeft[arrLeftCounter] - '0')) > 9)
		{
			res[resCounter] = (arrRight[arrRightCounter] + (arrLeft[arrLeftCounter] - '0')) % 10;
			resCounter--;
			boolCarryFlag = 1;
		}
		else
		{
			res[resCounter] = arrRight[arrRightCounter] + (arrLeft[arrLeftCounter] - '0');
			resCounter--;
		}
		arrRightCounter--;
		arrLeftCounter--;
		if((arrRightCounter == endOfArrSize) || (arrLeftCounter == endOfArrSize))
		{
			break;
		}
		
	}
	
	if(boolCarryFlag == 1)
	{
		
		if(arrLeftCounter > endOfArrSizeLeftOperand)
		{
			res[resCounter] = (arrLeft[arrLeftCounter] - '0') + 1;
			resCounter--;
			arrLeftCounter--;
		}
		else if (arrRightCounter > endOfArrSizeRightOperand)
		{
			res[resCounter] = arrRight[arrRightCounter] + 1;
			resCounter--;
			arrRightCounter--;
		}
		else
		{
			res[resCounter] = 1;
			resCounter--;
		}
	}
	while(arrLeftCounter >= endOfArrSizeLeftOperand)
	{
		
		res[resCounter] = (arrLeft[arrLeftCounter] - '0');
			
		resCounter--;
		arrLeftCounter--;
		
		
	}
	while(arrRightCounter >= endOfArrSizeRightOperand)
	{
		res[resCounter] = arrRight[arrRightCounter];
		resCounter--;
		arrRightCounter--;
	}
	return resCounter;
}


void Calc_vOperate(){
	
	uint8 arrFinalResult[NO_ARRAY_SIZE];
	short arrFinalResultPtrCounter = 19;
	if(arrRightNoPtrCounter != 0)
	{
		arrRightNoPtrCounter--;
		
	}
	
	if(arrLeftNoPtrCounter != 0)
	{
		arrLeftNoPtrCounter--;
		
	}


	if (LastOperator  == '+')
	{
		
		arrFinalResultPtrCounter = Calc_vAddition(arrLeftNo,arrLeftNoPtrCounter,arrRightNo, arrRightNoPtrCounter,arrFinalResult,arrFinalResultPtrCounter);
	}
	
	
	
	
	if (LastOperator == '-')
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
	
	
	if (LastOperator  == '*')
	{
		uint8 CarryVal = 0;
		uint8 boolIsFirstMultLevel = 1;
		uint8 boolIsTwoResLevelFinished = 0;
		short baseSizeOfLeft = arrLeftNoPtrCounter;
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
					else
					{
						arrAddOne[arrAddOneCounter] = (arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0'));
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
					else
					{
						arrAddTwo[arrAddTwoCounter] = arrRightNo[arrRightNoPtrCounter] * (arrLeftNo[arrLeftNoPtrCounter] - '0');
						arrAddTwoCounter--;
						
					}
					boolIsTwoResLevelFinished = 1;
				}
				arrLeftNoPtrCounter--;
			}
			if (boolIsTwoResLevelFinished == 1)
			{
				endOfArrSizeLeftOperand = arrAddOneCounter;
				endOfArrSizeRightOperand = arrAddTwoCounter;
				arrFinalResultPtrCounter = Calc_vAddition(arrAddOne,19,arrAddTwo, 19,arrFinalResult,arrFinalResultPtrCounter);
				
			}
			else
			{
				for(int i=19;i>arrAddOneCounter;i--)
				{
					arrFinalResult[arrFinalResultPtrCounter] = arrAddOne[i];
					
					arrFinalResultPtrCounter--;
				}
					
			}
			
			boolIsFirstMultLevel = 0;
			arrAddTwo[arrAddTwoCounter] = 0;
			arrAddTwoCounter--;
			arrRightNoPtrCounter--;
			arrLeftNoPtrCounter = baseSizeOfLeft;
		}
	}
	if (LastOperator == '/')
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


uPtrInt8 Calc_vCalculate(uint8 parNo)
{
	
	if(parNo == '=')
	{
		
		Calc_vOperate();
		return arrLeftNo;
	}
	
   if((parNo == '+') || (parNo == '-') || (parNo == '/') || (parNo == '*'))
	{
		if (LastOperator != 0)
		{
			Calc_vOperate();
		}
		LastOperator = parNo;
		
	}
	else
	{
		if(LastOperator == 0)
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
