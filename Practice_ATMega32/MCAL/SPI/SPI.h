/*
 * SPI.h
 *
 * Created: 07/07/2022 22:08:01
 *  Author: Mohamed
 */ 


#ifndef SPI_H_
#define SPI_H_


#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

typedef enum{
	MASTER,
	SLAVE
	}SPI_init_type;
	
void SPI_Init(SPI_init_type type);
u8 SPI_SendReceive(u8 data);

void SPI_SendNoBlock(u8 data);
u8 SPI_ReceiveNoBlock();

u8 SPI_ReceivePeriodic(u8* data);

#endif /* SPI_H_ */