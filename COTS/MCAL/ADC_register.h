/*
 * ADC_register.h
 *
 *  Created on: Sep 23, 2022
 *      Author: aminz
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u16*)0x24) 		// ADC Low Register

#define ADC_Reg 	*((volatile u16*)0x24) 		// ADC all Register


#endif /* ADC_REGISTER_H_ */
