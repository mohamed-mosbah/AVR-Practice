/*
 * Practice_ATMega32.c
 *
 * Created: 07/05/2022 01:35:47
 * Author : Mohamed
 */ 

#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Calculator.h"


int main(void)
{
	DIO_Init();
	LCD_Init();
	
	Calculator_run();
	
  
}

