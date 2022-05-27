/*
 * Calculator.c
 *
 * Created: 13/05/2022 00:08:07
 *  Author: Mohamed
 */ 
#include "Calculator.h"
#include "Calculator_Private.h"
#include "LCD.h"
#include "KeyPad.h"

#define F_CPU 8000000
#include <util/delay.h>


static u16 operand_1=0;
static u16 operand_2=0;
static operation_type operation;
static bool_type flag_reset=FALSE;
static u32 result=0;

validity_type first_operand_flag=NOT_VALID_ENTRY;
validity_type second_operand_flag=NOT_VALID_ENTRY;

bool_type first_operand_saved=FALSE;
bool_type second_operand_saved=FALSE;

void Calculator_run(void)
{
	//CALC_Welcome_screen();
	CALC_EntryMood();	
}
static void CALC_EntryMood()
{
	while(1)
	{
		u8 Entry = KEYPAD_GetEntry();
		if(Entry!=DEFAULT_KEY)
		{
			if(Entry=='C')
			{
				LCD_Clear();
				operand_1=0;
				operand_2=0;
				operation=NO_OP;
				first_operand_saved=FALSE;
				second_operand_saved=FALSE;
				flag_reset=1;
				result=0;
				continue;
			} else if((Entry>='0')&&(Entry<='9'))
			{
				LCD_WriteChar(Entry);
				if (first_operand_saved== FALSE)
				{
					operand_1=operand_1*10+(Entry-'0');
				}else if(first_operand_saved== TRUE)
				{
					operand_2=operand_2*10+(Entry-'0');
				}
			} else if(Entry=='=')
			{
				if(first_operand_saved==TRUE)
				{
					if(operation==ADD)
					{
						result = operand_1+operand_2;
					}else if(operation==SUB)
					{
						result = operand_1-operand_2;
					}else if(operation==DEV)
					{
						result = operand_1/operand_2;
					}else if(operation==MUL)
					{
						result = operand_1*operand_2;
					}
					LCD_SetCursor(1,0);
					LCD_WriteNumber(result);
				}
			} else if ((Entry==ADD)||(Entry==MUL)||(Entry==DEV)||(Entry==SUB))
			{
				operation=Entry;
				LCD_WriteChar(Entry);
				if(first_operand_saved==FALSE)
				{
					first_operand_saved=TRUE;
				}
			}
			
		
		}
	}
		
}

static void CALC_Welcome_screen(void)
{
	LCD_WriteString("Welcome");
	_delay_ms(1000);
	LCD_Clear();
}