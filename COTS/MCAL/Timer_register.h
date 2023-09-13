/*
 * Timer_register.h
 *
 *  Created on: Aug 4, 2023
 *      Author: hp
 */

#ifndef COTS_MCAL_TIMER_REGISTER_H_
#define COTS_MCAL_TIMER_REGISTER_H_

#define TCCR0_Register  *((volatile u8*)0x53)
#define OCR0_Register  *((volatile u8*)0x5C)
#define TIFR_Register  *((volatile u8*)0x58)
#define TIMSK_Register  *((volatile u8*)0x59)
#define TCNT0_Register  *((volatile u8*)0x52)

#define TCCR1A_Register  *((volatile u8*)0x4F)
#define TCCR1B_Register  *((volatile u8*)0x4E)
#define TCNT1_Register  *((volatile u16*)0x4C)
#define OCR1A_Register  *((volatile u16*)0x4A)
#define OCR1B_Register  *((volatile u16*)0x48)
#define ICR1_Register  *((volatile u16*)0x46)

#define WDTCR  	  *((volatile u8*)0x41)
#define MCUCSR    *((volatile u8*)0x54)

#define WDG_TIME_OUT_163_MS  1
#define WDG_TIME_OUT_325_MS  5
#define WDG_TIME_OUT_65_MS   7
#define WDG_TIME_OUT_13_S    9
#define WDG_TIME_OUT_26_S    11
#define WDG_TIME_OUT_52_S    14
#define WDG_TIME_OUT_1_S     20
#define WDG_TIME_OUT_21_S    25

#endif /* COTS_MCAL_TIMER_REGISTER_H_ */
