/*
 * Sensors.h
 *
 * Created: 16/05/2022 01:43:19
 *  Author: Mohamed
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "StdTypes.h"
#include "ADC.h"

#define		POT_CH		CH_1
#define		LM35_CH		CH_2

u16 POT_ReadVolt(void); //reading volt on a potentiometer in mVolts
u16 ReadTemp();
u16 POT_ReadPercentage(void); 

#endif /* SENSORS_H_ */