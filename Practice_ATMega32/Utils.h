/*
 * Utils.h
 *
 * Created: 24/04/2022 19:17:17
 *  Author: Mohamed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define GET_BIT(REG,BIT)	((REG>>BIT)&1)
#define SET_BIT(REG,BIT)	(REG=REG|(1<<BIT))
#define CLR_BIT(REG,BIT)	(REG=REG&~(1<<BIT))
#define TOG_BIT(REG,BIT)	(REG=REG^(1<<BIT))


#endif /* UTILS_H_ */