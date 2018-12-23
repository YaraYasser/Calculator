/*
 * macros.h
 *
 * Created: 12/22/2018 8:14:37 AM
 *  Author: user
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg,bit) (reg) |= (1<<(bit))
#define CLR_BIT(reg,bit) (reg) &= ~(1<< (bit))
#define READ_BIT(reg,bit) ( ((reg)>>(bit)) & 1 )



#endif /* MACROS_H_ */