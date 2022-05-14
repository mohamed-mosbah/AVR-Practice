/*
 * LCD_Cfg.h
 *
 * Created: 14/05/2022 13:23:41
 *  Author: Mohamed
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/* LCD Dimensions */
#define LCD_CELLS 16
#define LCD_LINES 2

/* LCD Control PINS */
#define		RS			PINB4
#define		EN			PINB5

/*
 * Choose seven segment connection:
 *      - LCD_4BIT
 *      - LCD_8BIT
 */
#define		LCD_MODE	LCD_4BIT

#if LCD_MODE == LCD_8BIT
/* Only use when using LCD in 8BIT mode */
#define		LCD_PORT	PA

/* Only use when using LCD in 4BIT mode */
#elif		LCD_MODE ==	LCD_4BIT

#define		D4			PINA4
#define		D5			PINA5
#define		D6			PINA6
#define		D7			PINA7

#endif
#endif /* LCD_CFG_H_ */