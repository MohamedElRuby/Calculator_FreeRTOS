/*
 * LCD_register.h
 *
 *  Created on: Jul 23, 2023
 *      Author: hp
 */
#ifndef COTS_HAL_LCD_REGISTER_H_
#define COTS_HAL_LCD_REGISTER_H_

#include "../MCAL/DIO_register.h"

#define LCD_clr 		 	    0x01
#define LCD_Home		 	    0x02
#define LCD_EnteryMode 		    0x01
#define LCD_DispOn              0x0C
#define LCD_DispOff        	    0x08
#define LCD_SetFunction4bit     0x20
#define LCD_SetFunc             0x80




#define lcd_DATAPORT          PORTB
#define lcd_CONTROLPORT       PORTC
#define lcd_RSPIN     		  3
//#define lcd_RWPIN
#define lcd_EPIN      		  2



#endif

