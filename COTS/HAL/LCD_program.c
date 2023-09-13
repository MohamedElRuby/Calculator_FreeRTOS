/*
 * LCD_program.c
 *
 *  Created on: Jul 23, 2023
 *      Author: hp
 */

#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "LCD_register.h"
#include "LCD_interface.h"
#include "../MCAL/DIO_interface.h"
#include "../MCAL/DIO_register.h"
#include "util/delay.h"


//init
void LCD_init(){
//rs=0 and rw=0 and latch ale hwa send 8 bits w b3den en high ,dlay 2ms, b3dha en low ,2ms

DIO_voidSetPinDirection(lcd_DATAPORT,4,DIO_u8_OUTPUT);
DIO_voidSetPinDirection(lcd_DATAPORT,5,DIO_u8_OUTPUT);
DIO_voidSetPinDirection(lcd_DATAPORT,6,DIO_u8_OUTPUT);
DIO_voidSetPinDirection(lcd_DATAPORT,7,DIO_u8_OUTPUT);

DIO_voidSetPinDirection(lcd_CONTROLPORT,lcd_EPIN,DIO_u8_OUTPUT);
DIO_voidSetPinDirection(lcd_CONTROLPORT,lcd_RSPIN,DIO_u8_OUTPUT);


	_delay_ms(100);

		LCD_SendCommand(0x02);
		LCD_SendCommand(0x28);
		LCD_SendCommand(0x0c);
		LCD_SendCommand(0x01);
		LCD_SendCommand(0x06);
		LCD_SendCommand(0x80);
}

//char
  void LCD_sendChar(u8 Data){


	       /* Set RS to high */
	  	  	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_RSPIN,1);

			DIO_voidSetPinValue(lcd_DATAPORT,4,GET_BIT(Data,4));
			DIO_voidSetPinValue(lcd_DATAPORT,5,GET_BIT(Data,5));
			DIO_voidSetPinValue(lcd_DATAPORT,6,GET_BIT(Data,6));
			DIO_voidSetPinValue(lcd_DATAPORT,7,GET_BIT(Data,7));

		    //latch
			DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,1);
			_delay_ms(2);
			DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,0);
			_delay_ms(2);


			DIO_voidSetPinValue(lcd_DATAPORT,4,GET_BIT(Data,0));
			DIO_voidSetPinValue(lcd_DATAPORT,5,GET_BIT(Data,1));
			DIO_voidSetPinValue(lcd_DATAPORT,6,GET_BIT(Data,2));
			DIO_voidSetPinValue(lcd_DATAPORT,7,GET_BIT(Data,3));

		    //latch
			DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN, 1);
		   _delay_ms(2);
		   	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN, 0);
			_delay_ms(2);

}

//send command
void LCD_SendCommand(u8 command){
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_RSPIN,0);
	_delay_ms(20);

	DIO_voidSetPinValue(lcd_DATAPORT,4,GET_BIT(command,4));
	DIO_voidSetPinValue(lcd_DATAPORT,5,GET_BIT(command,5));
	DIO_voidSetPinValue(lcd_DATAPORT,6,GET_BIT(command,6));
	DIO_voidSetPinValue(lcd_DATAPORT,7,GET_BIT(command,7));

    //latch
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,1);
	_delay_ms(2);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,0);
	_delay_ms(2);

	DIO_voidSetPinValue(lcd_DATAPORT,4,GET_BIT(command,0));
	DIO_voidSetPinValue(lcd_DATAPORT,5,GET_BIT(command,1));
	DIO_voidSetPinValue(lcd_DATAPORT,6,GET_BIT(command,2));
	DIO_voidSetPinValue(lcd_DATAPORT,7,GET_BIT(command,3));


    //latch
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,1);
	_delay_ms(2);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,0);
	_delay_ms(2);

}

void LCD_SendString (u8 *str){
	u8 i;

	for(i=0;str[i] != '\0';i++){
		LCD_sendChar(str[i]);
	}

}

void GoToXY(u8 x,u8 y){
	u8 address;
	if(y<2 && x<16){
		address=y*0x40+x;
		address=SET_BIT(address,7);
		LCD_SendCommand(address);

	}
}

void LCD_voidWriteNumber(s32 num)
{
	s8 j,i=0;
	u8 str[16];
	if(num==0)
	{
		LCD_sendChar('0');
	}
	else if(num<0)
	{
		LCD_sendChar('-');
		num=num*-1;
	}
	while(num)
	{
		str[i]=num%10+'0';
		num=num/10;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_sendChar(str[j]);
	}
}
