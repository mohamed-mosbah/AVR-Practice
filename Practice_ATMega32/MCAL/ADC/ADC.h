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
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	}ADC_Channel_type;
	
typedef	enum{
	VREF_AREF=0,
	VREF_AVCC=1,
	VREF_256V=3
	}ADC_Volt_type;
	
typedef enum{
	ADC_SCALER_2=0,
	ADC_SCALER_4=2,	
	ADC_SCALER_8,	
	ADC_SCALER_16,	
	ADC_SCALER_32,	
	ADC_SCALER_64,	
	ADC_SCALER_128	
}ADC_Scaler_type;

void ADC_Init(ADC_Volt_type ref, ADC_Scaler_type scaler);
u16 ADC_Read(ADC_Channel_type ch);
void ADC_StartConversion(ADC_Channel_type ch);
u16 ADC_GetADCValue(void);
u16 ADC_GetADCValuePeriodicCheck(u16 *pdata);

#endif /* ADC_H_ */