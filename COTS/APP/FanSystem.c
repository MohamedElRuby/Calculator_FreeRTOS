///*
// * FanSystem.c
// *
// *  Created on: Sep 3, 2023
// *      Author: hp
// */
//
//#include "../Libary/BIT_MATH.h"
//#include "../Libary/STD_TYPES.h"
//
//#include "../FreeRTOS/FreeRTOS.h"
//#include "../FreeRTOS/task.h"
//#include "../FreeRTOS/semphr.h"
//
//#include "LCD_interface.h"
//
//#include "../MCAL/DIO_register.h"
//#include "../MCAL/DIO_interface.h"
//#include "ADC_interface.h"
//#include "util/delay.h"
//
//
//TaskHandle_t T1=NULL;
//TaskHandle_t T2=NULL;
//TaskHandle_t T3=NULL;
//SemaphoreHandle_t LCDsem;
//
//QueueHandle_t xQueue;
//
//
//u16 Sesnor1_Read;
//u16 Sesnor2_Read;
//u16 result;
//
//
//void Sensor1(){
//
//
//	while(1){
//		 if (xSemaphoreTake(LCDsem, 200) == pdTRUE) {
//
//			 	 	 	Sesnor1_Read=ADC_Read(0);
//			 	 	 	GoToXY(0,0);
//			 	 	 	LCD_SendCommand(0x01); //lcd clear
//			 	 	 	LCD_SendString("Temp 2: ");
//			 	 	 	result=ADC_Read(0);
//			 	 	 	Sesnor1_Read=((u16)((u32)result*5000/1023))/10;
//			 	 	 	LCD_voidWriteNumber(Sesnor1_Read);
//			 	 	 	//_delay_ms(500);
//			 	 	 	xSemaphoreGive(LCDsem);
//
//		        }
//
//	vTaskDelay(3000);
//
//	}
//
//}
//
//void Sensor2(){
//
//
//	while(1){
//		 if (xSemaphoreTake(LCDsem, 200) == pdTRUE) {
//	 	 	 			GoToXY(0,0);
//			 	 	 	LCD_SendCommand(0x01); //lcd clear
//			 	 	 	LCD_SendString("Temp 1:");
//			 	 	 	result=ADC_Read(1);
//			 	 	 	Sesnor2_Read=((u16)((u32)result*5000/1023))/10;
//			 	 	 	LCD_voidWriteNumber(Sesnor2_Read);
//			 	 	 //	_delay_ms(800);
//			 	 	 	xSemaphoreGive(LCDsem);
//
//		        }
//
//		 	vTaskDelay(1500);
//
//	}
//
//}
//
//void Fan(){
//	while(1){
//	if((Sesnor2_Read>50) || (Sesnor1_Read>50) ){
//		DIO_voidSetPinValue(PORTA,2,DIO_u8_HIGH);
//	}else {
//		DIO_voidSetPinValue(PORTA,2,DIO_u8_LOW);
//
//	}
//	vTaskDelay(100);
//	}
//}
//
//
//
//
//void FanSystem () {
//	 DIO_voidSetPinDirection(PORTA,0,DIO_u8_INPUT);
//	 DIO_voidSetPinDirection(PORTA,1,DIO_u8_INPUT);
//	 DIO_voidSetPinDirection(PORTA,2,DIO_u8_OUTPUT);
//
//
//	// buffer=xQueuecreate(10,1);
//	 LCD_init();
//	 ADC_Init();
//
//
//	 LCDsem = xSemaphoreCreateMutex();
//
//	 xQueue = xQueueCreate(10, 4);
//
//
//	 xTaskCreate(Sensor1, NULL, 200, NULL, 1, &T1);
//	 xTaskCreate(Sensor2, NULL, 200, NULL, 2, &T2);
//	 xTaskCreate(Fan, NULL, 200, NULL, 3, &T3);
//	 //xTaskCreate(AyHaga, NULL, 200, NULL, 2 , NULL);
//
//
//	 vTaskStartScheduler();
//
//
//	while(1);
//
//}
