/*
 * Timer_interface.h
 *
 *  Created on: Aug 4, 2023
 *      Author: hp
 */

#ifndef COTS_MCAL_TIMER_INTERFACE_H_
#define COTS_MCAL_TIMER_INTERFACE_H_

void CounterInit();

void Tim0Init();

u8 CounterGetValue();

void Tim0_VID_SET_CALL_BACK(void (*PTR)(void));

void TIM0_voidSetTimerReg(u8 Copy_u8Value);

void TIM0_voidSetCompareVal(u8 Copy_u8Value);

void Tim1Init();

void WDG_On(void);

void WDG_Off(void);

void WDG_Refresh(void);

#endif /* COTS_MCAL_TIMER_INTERFACE_H_ */
