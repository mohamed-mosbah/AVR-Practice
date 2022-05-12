/*
 * Motor.c
 *
 * Created: 12/05/2022 03:15:51
 *  Author: Mohamed
 */ 


#include "Motor.h"
#include "Motor_Private.h"

static DIO_Pin_type MotorPinsArray[4][2]={
	//motors	IN1		IN2
	/*M1*/		{PIND0,PIND1},
	/*M1*/		{PIND0,PIND1},
	/*M1*/		{PIND0,PIND1},
	/*M1*/		{PIND0,PIND1},
};

void MOTOR_Init(void)
{
	
}

void MOTOR_CW(MOTIR_type motor)
{
	DIO_WritePin(MotorPinsArray[motor][IN1],HIGH);
	DIO_WritePin(MotorPinsArray[motor][IN2],LOW);
}
void MOTOR_CCW(MOTIR_type motor)
{
	DIO_WritePin(MotorPinsArray[motor][IN1],LOW);
	DIO_WritePin(MotorPinsArray[motor][IN2],HIGH);
}
void MOTOR_Stop(MOTIR_type motor)
{
	DIO_WritePin(MotorPinsArray[motor][IN1],LOW);
	DIO_WritePin(MotorPinsArray[motor][IN2],LOW);
}