/*
 * LCD_interface.h
 *
 *  Created on: Jul 23, 2023
 *      Author: hp
 */

#ifndef COTS_HAL_LCD_INTERFACE_H_
#define COTS_HAL_LCD_INTERFACE_H_


//init
void LCD_init();

//char
void LCD_sendChar(u8 Data);

//send command
void LCD_SendCommand(u8 command);

//Send String
void LCD_SendString (u8 *str);

void GoToXY(u8 x,u8 y);

void LCD_voidWriteNumber(s32 num);

#endif /* COTS_HAL_LCD_INTERFACE_H_ */
