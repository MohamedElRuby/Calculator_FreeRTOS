/*
 * DIO_interface.h
 *
 *  Created on: May 1, 2023
 *      Author: ElRuby
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7


/* PORT Directions */
#define PORT_INPUT  0x00
#define PORT_OUTPUT 0xff
/* PORT Value Options */
#define PORT_LOW  0x00
#define PORT_HIGH 0xff
/* PIN Directions */
#define PIN_INPUT  0
#define PIN_OUTPUT 1
/* PIN Value Options */
#define PIN_LOW  0
#define PIN_HIGH 1

#define DIO_u8_LOW 0
#define DIO_u8_HIGH 1

#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1




/* IO Pins */
void DIO_voidSetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy);
u8 DIO_u8GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy);
void DIO_voidSetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy);
void DIO_TogglePinValue(u8 u8PortIdCopy,u8 u8PinIdCopy);

/* IO Ports */
void DIO_SetPortDirection(u8 u8PortIdCopy,u8 u8PortDirCopy);
void DIO_SetPortValue(u8 u8PortIdCopy,u8 u8PortValCopy);
void DIO_TogglePortValue(u8 u8PortIdCopy);
u8 DIO_GetPortValue(u8 u8PortIdCopy);



#endif /* DIO_INTERFACE_H_ */
