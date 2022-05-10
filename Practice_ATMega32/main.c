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


int main(void)
{
	DIO_Init();
	LCD_Init();
	LCD_Clear();
	LCD_WriteString("Mohamed");
    while (1) 
    {
		u8 k=KEYPAD_GetEntry();
		if(k!=DEFAULT_KEY)
		{
			
			LCD_WriteChar(k);
		}
    }
}

