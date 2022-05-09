/*
 * KeyPad.h
 *
 * Created: 07/05/2022 13:49:18
 *  Author: Mohamed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "StdTypes.h"
#include "DIO_Interface.h"

#define FIRST_INPUT PIND0
#define FIRST_OUTPUT PINB0

#define ROWS 4
#define COLS 4
#define DEFAULT_KEY 't'

u8 KEYPAD_GetEntry(void);

#endif /* KEYPAD_H_ */