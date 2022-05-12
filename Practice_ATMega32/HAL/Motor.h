/*
 * Motor.h
 *
 * Created: 12/05/2022 03:16:04
 *  Author: Mohamed
 */ 

#ifndef MOTOR_H_
#define MOTOR_H_

#include "StdTypes.h"
#include "DIO_Interface.h"

typedef enum{
	M1,
	M2,
	M3,
	M4
}MOTIR_type;

void MOTOR_Init(void);

void MOTOR_CW(MOTIR_type);
void MOTOR_CCW(MOTIR_type);
void MOTOR_Stop(MOTIR_type);



/*******************************pin config***********************/

#define		IN1_MOTOR1		PIND4
#define		IN2_MOTOR1		PIND5

#define		IN1_MOTOR2		PIND6
#define		IN2_MOTOR2		PIND7

#define		IN1_MOTOR3		PIND4
#define		IN2_MOTOR3		PIND5

#define		IN1_MOTOR4		PIND6
#define		IN2_MOTOR4		PIND7




#endif /* MOTOR_H_ */