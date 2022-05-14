/*
 * KeyPad.c
 *
 * Created: 07/05/2022 13:49:08
 *  Author: Mohamed
 */ 

#include "KeyPad.h"
#include "StdTypes.h"

extern const u8 KeysArray[ROWS][COLS];

u8 KEYPAD_GetEntry(void)
{
	u8 row;
	u8 col;
	u8 key = DEFAULT_KEY;
	for(row=0;row<ROWS;row++)
	{
		DIO_WritePin(FIRST_OUTPUT+row,HIGH);
	}
	for(row=0;row<=ROWS;row++)
	{
		DIO_WritePin(FIRST_OUTPUT+row,LOW);
		for(col=0;col<COLS;col++)
		{
			if(!DIO_ReadPin(FIRST_INPUT+col))
			{
				while (!DIO_ReadPin(FIRST_INPUT+col));
				key= KeysArray[row][col];
			}
		}
		DIO_WritePin(FIRST_OUTPUT+row,HIGH);
	}
	return key;
	
}
