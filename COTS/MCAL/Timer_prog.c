/*
 * Timer_prog.c
 *
 *  Created on: Aug 4, 2023
 *      Author: hp
 */
#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "Timer_interface.h"
#include "Timer_register.h"
#include "Timer_config.h"

void (* callback_PTR)(void)=NULL;


void CounterInit(){
	SET_BIT(TCCR0_Register,0); //External clock source on T0 pin. Clock on rising edge
	SET_BIT(TCCR0_Register,1);
	SET_BIT(TCCR0_Register,2);

	TCNT0_Register=0x00;

}

void Tim0Init(){

#if Timer_MODE == NormalMode
	CLR_BIT(TCCR0_Register,3);
    CLR_BIT(TCCR0_Register,6);
#elif Timer_MODE == PWM
	SET_BIT(TCCR0_Register,3);
    CLR_BIT(TCCR0_Register,6);
#elif Timer_MODE == CTC
	CLR_BIT(TCCR0_Register,3);
    SET_BIT(TCCR0_Register,6);
#elif Timer_MODE == FASTPWM
	SET_BIT(TCCR0_Register,3);
    SET_BIT(TCCR0_Register,6);
#endif



	//for PWM mode selection
	CLR_BIT(TCCR0_Register,4);
	SET_BIT(TCCR0_Register,5);

	TCNT0_Register=0;

	SET_BIT(TCCR0_Register,1); //set prescaler to /8


}

void TIM0_voidSetTimerReg(u8 Copy_u8Value){
	TCNT0_Register=Copy_u8Value;
}

void TIM0_voidSetCompareVal(u8 Copy_u8Value){
	OCR0_Register=Copy_u8Value;
}

u8 CounterGetValue(){
	return TCNT0_Register;
}

void Tim0_VID_SET_CALL_BACK(void (*PTR)(void)){
	callback_PTR=PTR;
}

void __vector_11 (void) __attribute__ ((signal,used,externally_visible)); //to avoid optmization
void __vector_11 (void){
callback_PTR();
}


void WDG_On(void){
	SET_BIT(WDTCR,3);

#if WDG_PRESCALE==WDG_TIME_OUT_163_MS
	CLR_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
#elif WDG_PRESCALE==WDG_TIME_OUT_325_MS
	SET_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
#elif WDG_PRESCALE==WDG_TIME_OUT_65_MS
	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
#elif WDG_PRESCALE==WDG_TIME_OUT_13_S
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
#elif WDG_PRESCALE==WDG_TIME_OUT_26_S
	CLR_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
#elif WDG_PRESCALE==WDG_TIME_OUT_52_S
	SET_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
#elif WDG_PRESCALE==WDG_TIME_OUT_1_S
	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
#elif WDG_PRESCALE==WDG_TIME_OUT_21_S
	SET_BIT(WDTCR,0);
	SETBIT(WDTCR,1);
	SET_BIT(WDTCR,2);
#endif
}

void WDG_Off(void){
	CLR_BIT(WDTCR,3);
	SET_BIT(WDTCR,4);
}

void WDG_Refresh(void){
	asm("WDR");
}
