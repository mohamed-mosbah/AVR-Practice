/*
 * SPI.c
 *
 * Created: 07/07/2022 22:08:15
 *  Author: Mohamed
 */ 

#include "SPI.h"

// data order is least to most
// leading edge is rising
void SPI_Init(SPI_init_type type){
	if(type == MASTER)
	{
		SET_BIT(SPCR,MSTR);
	}
	else if(type== SLAVE) 
	{
		CLR_BIT(SPCR,MSTR);
	}
	
	//enable SPI
	SET_BIT(SPCR,SPE);
}

u8 SPI_SendReceive(u8 data)
{
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}


void SPI_SendNoBlock(u8 data)
{
	SPDR = data;
}

u8 SPI_ReceiveNoBlock()
{
	return SPDR;
}

u8 SPI_ReceivePeriodic(u8* data)
{
	if(GET_BIT(SPSR,SPIF))
	{
		*data = SPDR;
		return 1;
	}
	return 0;
}