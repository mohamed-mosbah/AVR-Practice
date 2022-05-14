/*
 * Calculator.h
 *
 * Created: 13/05/2022 00:10:30
 *  Author: Mohamed
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "StdTypes.h"

typedef enum
{
	ADD='+',
	SUB='-',
	DEV='/',
	MUL='*',
	EQUAL='=',
	CLEAR='C',
	NO_OP=0
}operation_type;

void Calculator_run(void);

typedef enum{
	NOT_VALID_ENTRY=0,
	VALID_ENTRY
}validity_type;


#endif /* CALCULATOR_H_ */