/*
 * LCD.h
 *
 * Created: 07/05/2022 13:07:54
 *  Author: Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "StdTypes.h"
#include "DIO_Interface.h"
#include "LCD_Private.h"

#define F_CPU 8000000
#include <util/delay.h>

/**********************************
* LCD_4BIT
* LCD_8BIT
**********************************/
#define		LCD_MODE	LCD_4BIT

#define		RS			PINB4
#define		EN			PINB5

#if LCD_MODE == LCD_8BIT
//Only used with LCD_8BIT mode
#define		LCD_PORT	PA

#elif		LCD_MODE ==	LCD_4BIT

#define		D4			PINA4
#define		D5			PINA5
#define		D6			PINA6
#define		D7			PINA7

#endif
void WriteInstruction(u8 ins);
void WriteData(u8 data);
void LCD_Init(void);

void LCD_Clear(void);

void LCD_WriteNumber(s32 num);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8 *str);

void LCD_WriteBinary(u8 num);
void LCD_WriteBinary_8B(u8 num);
void LCD_WriteHex(u8 num);

void LCD_SetCursor(u8 line, u8 cell);
void LCD_ClearLocation(u8 line, u8 cell);


#endif /* LCD_H_ */