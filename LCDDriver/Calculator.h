/*
 * Calculator.h
 *
 * Created: 12/24/2018 6:11:42 AM
 *  Author: user
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "Main.h"
#include "LCD.h"
#define NO_ARRAY_SIZE 20
short Calc_vAddition(uint8* arrLeft,short arrLeftCounter,uint8* arrRight,short arrRightCounter,uint8* res,short resCounter);
void Calc_vOperate();
uint8* Calc_vCalculate(uint8 parNo);
void Calc_vClear();
#endif /* CALCULATOR_H_ */