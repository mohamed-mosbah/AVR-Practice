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
	
void SPI_Init(SPI_init_type);



#endif /* SPI_H_ */