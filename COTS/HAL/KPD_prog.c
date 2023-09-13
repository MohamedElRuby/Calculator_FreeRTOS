/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/


/********************************** Header Files INCLUSIONS ****************************/
#include "STD_TYPES.h".
#include "BIT_MATH.h"

#include "util/delay.h"

#include "DIO_interface.h"
#include "KPD_interface.h"
/***************************************************************************************/

/************* KeyPad Key Index ***************/                         
/*         Col_3    Col_2   Col_1   Col_0     */
/*	                                          */
/* row_0      1        2       3       4      */
/*	                                          */
/* row_1  	  5        6       7       8      */
/*	                                          */
/* row_2	  9        10      11      12     */
/*	                                          */
/* row_3	  13       14      15      16     */
/**********************************************/


/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_au8SwitchVal[4][4] =
{
			{'7','8','9','%'},
			{'4','5','6','x'},
			{'1','2','3','-'},
			{'#','0','=','+'},
};

/***************************************************************************************/


/***************************************** Macros **************************************/
#define PORT PORTA

#define COL_INIT   0

#define COL_FIN    4

#define ROW_INIT   4

#define ROW_FIN    8

#define NOT_PRESSED    0
/***************************************************************************************/


/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void KPD_vidINIT(void)
{

	u8 LOC_u8Column;

	u8 LOC_u8Row;

	for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++) {
		/* DIRECTION of  the Column                                                                                           */
		DIO_voidSetPinDirection(PORT, LOC_u8Column, PIN_OUTPUT);

	}

	/* SET rows to input PULLUP                                                                               */
	for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++) {
		DIO_voidSetPinDirection(PORT, LOC_u8Row, PIN_INPUT);
		DIO_voidSetPinValue(PORT, LOC_u8Row, PIN_HIGH);
	}


}

u8 KPD_u8GetPressedKey(void)
{

  u8 LOC_u8Column;

  u8 LOC_u8Row;

  /* Initialize the switch status to NOT Pressed                                                                     */
  u8 LOC_u8Retrun = NOT_PRESSED;

  /* Looping on columns of the Key Pad                                                                               */
  for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
  {
    /* Activate the Column                                                                                           */
	  DIO_voidSetPinValue(PORT, LOC_u8Column, PIN_LOW);

    /* Loop on the rows of the Key Pad                                                                               */
    for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
    {
      /* Check the status of the switch                                                                              */
      if (!DIO_u8GetPinValue(PORT, LOC_u8Row))
      {
        /* Get the value of the currently pressed switch                                                             */
        LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];

        /* Wait until the switch is released (Single Press)                                                          */
        while (!DIO_u8GetPinValue(PORT, LOC_u8Row))
          ;

        /* Delay to avoid bouncing                                                                                   */
        _delay_ms(10);

      }
    }

    /* Deactivate the Column                                                                                         */
    DIO_voidSetPinValue(PORT, LOC_u8Column, PIN_HIGH);
  }

  return LOC_u8Retrun;
}
