/*
 * Tim1_register.h
 *
 *  Created on: Aug 6, 2023
 *      Author: hp
 */

#ifndef COTS_MCAL_TIM1_REGISTER_H_
#define COTS_MCAL_TIM1_REGISTER_H_

#define TCCR1A_Register  *((volatile u8*)0x4F)
#define TCCR1B_Register  *((volatile u8*)0x4E)
#define TCNT1_Register  *((volatile u16*)0x4C)
#define OCR1A_Register  *((volatile u16*)0x4A)
#define OCR1B_Register  *((volatile u16*)0x48)
#define ICR1_Register  *((volatile u16*)0x46)
#define TIMSK_Register  *((volatile u8*)0x59)

void Tim1Init();

void Tim1_SetRisingEdge();

void Tim1_SetFailingEdge();

u16 Tim1_GetValue();

void Tim1_VID_SET_CALL_BACK(void (*PTR)(void));

#endif /* COTS_MCAL_TIM1_REGISTER_H_ */
