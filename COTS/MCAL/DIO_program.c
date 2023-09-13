/*
 * DIO_program.c
 *
 *  Created on: May 1, 2023
 *      Author: ElRuby
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"

void DIO_voidSetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy)
{
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		if ( u8PinValCopy == PIN_HIGH )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
			case PORTA: SET_BIT(PORTA_Register,u8PinIdCopy); break;
			case PORTB: SET_BIT(PORTB_Register,u8PinIdCopy); break;
			case PORTC: SET_BIT(PORTC_Register,u8PinIdCopy); break;
			case PORTD: SET_BIT(PORTD_Register,u8PinIdCopy); break;
		    default : break;
			}
		}

		else if ( u8PinValCopy == PIN_LOW )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
			case PORTA: CLR_BIT(PORTA_Register,u8PinIdCopy); break;
			case PORTB: CLR_BIT(PORTB_Register,u8PinIdCopy); break;
			case PORTC: CLR_BIT(PORTC_Register,u8PinIdCopy); break;
			case PORTD: CLR_BIT(PORTD_Register,u8PinIdCopy); break;
			default : break;
			}
		}

		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}

}
u8 DIO_u8GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy)
{
	u8 u8Valuecopy;

	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
		case PORTA: u8Valuecopy = GET_BIT(PINA_Register,u8PinIdCopy); break;
		case PORTB: u8Valuecopy = GET_BIT(PINB_Register,u8PinIdCopy); break;
		case PORTC: u8Valuecopy = GET_BIT(PINC_Register,u8PinIdCopy); break;
		case PORTD: u8Valuecopy = GET_BIT(PIND_Register,u8PinIdCopy); break;
		default : break;
		}
	}
	else
	{
		/* Do nothing, Wrong Direction Required */
	}

	return u8Valuecopy;

}
void DIO_voidSetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy)
{
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		if ( u8PinDirCopy == PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
			case PORTA: SET_BIT(DDRA_Register,u8PinIdCopy); break;
			case PORTB: SET_BIT(DDRB_Register,u8PinIdCopy); break;
			case PORTC: SET_BIT(DDRC_Register,u8PinIdCopy); break;
			case PORTD: SET_BIT(DDRD_Register,u8PinIdCopy); break;
			default : break;
			}
		}

		else if ( u8PinDirCopy == PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
			case PORTA: CLR_BIT(DDRA_Register,u8PinIdCopy); break;
			case PORTB: CLR_BIT(DDRB_Register,u8PinIdCopy); break;
			case PORTC: CLR_BIT(DDRC_Register,u8PinIdCopy); break;
			case PORTD: CLR_BIT(DDRD_Register,u8PinIdCopy); break;
			default : break;
			}
		}

		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}

}
void DIO_TogglePinValue(u8 u8PortIdCopy,u8 u8PinIdCopy)
{
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
		case PORTA: TOG_BIT(PORTA_Register,u8PinIdCopy); break;
		case PORTB: TOG_BIT(PORTB_Register,u8PinIdCopy); break;
		case PORTC: TOG_BIT(PORTC_Register,u8PinIdCopy); break;
		case PORTD: TOG_BIT(PORTD_Register,u8PinIdCopy); break;
		default : break;
		}
	}
	else
	{
		/* Do nothing, Wrong Direction Required */
	}
}

/* IO Ports */
void DIO_SetPortDirection(u8 u8PortIdCopy,u8 u8PortDirCopy)
{
	switch(u8PortIdCopy)
	{
	case PORTA : DDRA_Register = u8PortDirCopy; break;
	case PORTB : DDRB_Register = u8PortDirCopy; break;
	case PORTC : DDRC_Register = u8PortDirCopy; break;
	case PORTD : DDRD_Register = u8PortDirCopy; break;
	default: break;
	}

}
void DIO_SetPortValue(u8 u8PortIdCopy,u8 u8PortValCopy)
{
	switch(u8PortIdCopy)
	{
	case PORTA : PORTA_Register = u8PortValCopy; break;
	case PORTB : PORTB_Register = u8PortValCopy; break;
	case PORTC : PORTC_Register = u8PortValCopy; break;
	case PORTD : PORTD_Register = u8PortValCopy; break;
	default: break;
	}


}
void DIO_TogglePortValue(u8 u8PortIdCopy)
{
	switch(u8PortIdCopy)
	{
	case PORTA : PORTA_Register ^= 0xFF; break;
	case PORTB : PORTB_Register ^= 0xFF; break;
	case PORTC : PORTC_Register ^= 0xFF; break;
	case PORTD : PORTD_Register ^= 0xFF; break;
	default: break;
	}

}
u8 DIO_GetPortValue(u8 u8PortIdCopy)
{
	u8 u8Valuecopy;

	switch(u8PortIdCopy)
	{
	case PORTA :u8Valuecopy = PINA_Register; break;
	case PORTB :u8Valuecopy = PINB_Register; break;
	case PORTC :u8Valuecopy = PINC_Register; break;
	case PORTD :u8Valuecopy = PIND_Register; break;
	default: break;
	}

	return u8Valuecopy;

}
