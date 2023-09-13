/*
 * ADC.c
 *
 *  Created on: Sep 23, 2022
 *      Author: aminz
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_register.h"

void ADC_Init (void)
{
	//enable adc
	SET_BIT(ADCSRA_Reg,7);

	// ADC Clock
	// Prescaler Configuration as 128
	SET_BIT(ADCSRA_Reg,2);
	SET_BIT(ADCSRA_Reg,1);
	SET_BIT(ADCSRA_Reg,0);

	//V refrence
	SET_BIT(ADMUX_Reg,6);
	CLR_BIT(ADMUX_Reg,7);

	//Adjustment
	CLR_BIT(ADMUX_Reg,5);

}

u16 ADC_Read (u8 Channel)
{

	//u16 ADCH;
	//u16 ADCL;
	//u16 ADC;

	//channel select
	ADMUX_Reg &= (~(0x1F));
	ADMUX_Reg |= Channel;

	//start conversion
	SET_BIT(ADCSRA_Reg,6);

	//wait till flag is raised
	while(!GET_BIT(ADCSRA_Reg,4));

	//ADCL=ADCL_Reg;
	//ADCH=ADCH_Reg;
	//ADC = ADCH<<8 | ADCL;

	//CLEAR ACDIF flag
	SET_BIT(ADCSRA_Reg,4);

	//return ADC reading
	return ADC_Reg;

}

u32 Mappping (u32 Range1_min,u32 Range1_max,u32 Range1_input,u32 Range2_min,u32 Range2_max){

	u32 Range2_output=Range2_max-(((Range1_max-Range1_input)*(Range2_max-Range2_min))/(Range1_max-Range1_min));

	return Range2_output;


}
