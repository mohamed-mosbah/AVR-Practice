/*
 * Exinterrupt.h
 *
 * Created: 12/06/2022 16:22:30
 *  Author: Mohamed
 */ 


#ifndef EXINTERRUPT_H_
#define EXINTERRUPT_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;

void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);




#endif /* EXINTERRUPT_H_ */