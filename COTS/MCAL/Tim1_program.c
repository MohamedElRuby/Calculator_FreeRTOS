/*
 * Tim1_program.c
 *
 *  Created on: Aug 6, 2023
 *      Author: hp
 */
#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "Timer_interface.h"
#include "Tim1_register.h"

void (* Tim1_callback_PTR)(void)=NULL;

void Tim1Init(){
	CLR_BIT(TCCR1B_Register,0);
	SET_BIT(TCCR1B_Register,1);
	CLR_BIT(TCCR1B_Register,2);

	TCNT1_Register=0;
	ICR1_Register=0;

	SET_BIT(TCCR1B_Register,6); //SET RISING EDGE



}

void Tim1_SetRisingEdge(){
	SET_BIT(TCCR1B_Register,6);
}

void Tim1_SetFailingEdge(){
	CLR_BIT(TCCR1B_Register,6);

}

u16 Tim1_GetValue(){
	return ICR1_Register;
}

void Tim1_VID_SET_CALL_BACK(void (*PTR)(void)){
	Tim1_callback_PTR=PTR;
}

void __vector_6 (void) __attribute__ ((signal,used,externally_visible)); //to avoid optmization
void __vector_6 (void){
	Tim1_callback_PTR();
}

