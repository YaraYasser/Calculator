

#ifndef KEYPADDRIVER_H_
#define KEYPADDRIVER_H_
#include "DIO.h"
#include "Port.h"
#include "Main.h"
#include <avr/io.h>
#include <util/delay.h>
#define NO_PRESS 0xff
#define CLEAR 0

void keyPad_vIntial(void);
uint8 keyPad_vScan(void);





#endif /* KEYPADDRIVER_H_ */