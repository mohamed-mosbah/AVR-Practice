/*
 * ADC.h
 *
 * Created: 14/05/2022 22:52:45
 *  Author: Mohamed
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"

typedef enum{
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	CH_8
	}ADC_Channel_type;
	
typedef	enum{
	VREF_AREF=0,
	VREF_AVCC,
	VREF_256V=3
	}ADC_Volt_type;

void ADC_Init(ADC_Volt_type ref);
u16 ADC_Read(ADC_Channel_type ch);



#endif /* ADC_H_ */