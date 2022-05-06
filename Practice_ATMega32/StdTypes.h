/*
 * StdTypes.h
 *
 * Created: 07/05/2022 01:42:12
 *  Author: Mohamed
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

/*
 * StdTypes.h
 *
 * Created: 24/04/2022 19:19:24
 *  Author: Mohamed
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char	u8;
typedef signed char		s8;
typedef unsigned short	u16;
typedef signed short	s16;
typedef unsigned long	u32;
typedef signed long		s32;
typedef  float f32;

#define		NULL		0
#define		NULLPTR		((void*)0)
	
#define		MAX_U16		((u16)65535)
#define		MIN_U16		((u16)0)
#define		MIN_S16		((s16)32767)
#define		MIN_s16		((s16)-32768)

typedef enum{
	FALSE,
	TRUE
}bool_type;

#endif /* STDTYPES_H_ */



#endif /* STDTYPES_H_ */