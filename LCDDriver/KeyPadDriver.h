

#ifndef KEYPADDRIVER_H_
#define KEYPADDRIVER_H_
#include "DIO.h"
#include "Port.h"
#include "Main.h"
#include <avr/io.h>
#include <util/delay.h>
#define NO_PRESS 0xff
#define CLEAR 0
#define INPUT 0
#define OUTPUT 1
#define BUTTON_IN_COL_PRESSED 0
#define WRITE_START_PIN 0
#define WRITE_END_PIN 3
#define READ_START_PIN 4
#define READ_END_PIN 7


void keyPad_vIntial(void);
uint8 keyPad_vScan(void);





#endif /* KEYPADDRIVER_H_ */