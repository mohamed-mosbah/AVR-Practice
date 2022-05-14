/*
 * LCD.c
 *
 * Created: 07/05/2022 13:08:05
 *  Author: Mohamed
 */ 

#include "LCD.h"
#include "DIO_Interface.h"
#include "LCD_Cfg.h"

static u8 cell = 0;
static u8 line = 0;

#if LCD_MODE==LCD_8BIT

void WriteInstruction(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteInstruction(0x38);
	_delay_ms(1);
	WriteInstruction(0x0C);
	_delay_ms(1);
	WriteInstruction(0x01);
	_delay_ms(2);
	WriteInstruction(0x06); //0x06 for no shift //0x07 for shift
}
#elif LCD_MODE == LCD_4BIT

void WriteInstruction(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,(DIO_PinVoltage_type)GET_BIT(ins,7));
	DIO_WritePin(D6,(DIO_PinVoltage_type)GET_BIT(ins,6));
	DIO_WritePin(D5,(DIO_PinVoltage_type)GET_BIT(ins,5));
	DIO_WritePin(D4,(DIO_PinVoltage_type)GET_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	
	DIO_WritePin(D7,(DIO_PinVoltage_type)GET_BIT(ins,3));
	DIO_WritePin(D6,(DIO_PinVoltage_type)GET_BIT(ins,2));
	DIO_WritePin(D5,(DIO_PinVoltage_type)GET_BIT(ins,1));
	DIO_WritePin(D4,(DIO_PinVoltage_type)GET_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,(DIO_PinVoltage_type)GET_BIT(data,7));
	DIO_WritePin(D6,(DIO_PinVoltage_type)GET_BIT(data,6));
	DIO_WritePin(D5,(DIO_PinVoltage_type)GET_BIT(data,5));
	DIO_WritePin(D4,(DIO_PinVoltage_type)GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	
	DIO_WritePin(D7,(DIO_PinVoltage_type)GET_BIT(data,3));
	DIO_WritePin(D6,(DIO_PinVoltage_type)GET_BIT(data,2));
	DIO_WritePin(D5,(DIO_PinVoltage_type)GET_BIT(data,1));
	DIO_WritePin(D4,(DIO_PinVoltage_type)GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteInstruction(0x02);
	WriteInstruction(0x28);
	_delay_ms(1);
	WriteInstruction(0x0c);
	_delay_ms(1);
	WriteInstruction(0x01);
	_delay_ms(2);
	WriteInstruction(0x06); //0x06 for no shift //0x07 for shift
}
#endif


/********************************* LCD Services ********************************/

void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
	IncrementCursor();
}

void LCD_WriteString(u8 * str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

void LCD_Clear(void)
{
	WriteInstruction(0x01);
	cell=0;
	
	_delay_ms(2);
}

void LCD_WriteNumber(s32 num)
{
	u8 i=0, str[20];
	s8 j=0;
	if(num==0)
	{
		LCD_WriteChar('0');
		return ;
	}
	if(num<0)
	{
		LCD_WriteChar('-');
		num=num*-1;
	}
	while (num)
	{
		str[i]=num%10+'0';
		num/=10;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
}
void LCD_WriteBinary(u8 num)
{
	s8 i;
	u8 flag=0;
	for(i=7;i>=0;i--)
	{
		if((GET_BIT(num,i)==1) && (flag==0))
		{
			flag=1;
			LCD_WriteChar(GET_BIT(num,i)+'0');
		}
		else if(flag==1)
		{
			LCD_WriteChar(GET_BIT(num,i)+'0');
		}
	}
}

void LCD_WriteBinary_8B(u8 num)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		LCD_WriteChar(GET_BIT(num,i)+'0');
	}
}

void LCD_WriteHex(u8 num)
{
	u8 Lnibble=num & 0x0f;
	u8 Hnibble=num >> 4;
	if(Hnibble<=9)
	{
		LCD_WriteChar(Hnibble+'0');
	}else
	{
		LCD_WriteChar(Hnibble-10+'A');
	}
	if(Lnibble<=9)
	{
		LCD_WriteChar(Lnibble+'0');
	}else
	{
		LCD_WriteChar(Lnibble-10+'A');
	}
}
void LCD_SetCursor(u8 line, u8 cell)
{
	if (line ==0)
	{
		WriteInstruction(0x80|cell);
	}else if (line ==1)
	{
		WriteInstruction(0x80|0x40|cell);
	}
}

void LCD_ClearLocation(u8 line, u8 cell)
{
	LCD_SetCursor(line,cell);
	LCD_WriteChar(' ');
}


static void DecrementCursor(void)
{
	if (cell == 0)
	{
		if (line == 0)
		{
			line = LCD_LINES_MAX_OFFSET;
			cell = LCD_CELLS_MAX_OFFSET;
		}
		else
		{
			line -= 1;
			cell = LCD_CELLS_MAX_OFFSET;
		}
	}
	else
	{
		cell -= 1;
	}
	LCD_SetCursor(line, cell);
}

static void IncrementCursor(void)
{
	if (cell == LCD_CELLS_MAX_OFFSET)
	{
		if (line == LCD_LINES_MAX_OFFSET)
		{
			line = 0;
			cell = 0;
		}
		else
		{
			line += 1;
			cell = 0;
		}
	}
	else
	{
		cell += 1;
	}
	LCD_SetCursor(line, cell);
}

void LCD_ClearLast(void)
{
	DecrementCursor();
	LCD_WriteChar(' ');
	DecrementCursor();
}