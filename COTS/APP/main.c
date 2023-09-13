#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Calculator.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "event_groups.h"

#include "LCD_interface.h"
#include "KPD_interface.h"

#include "DIO_register.h"
#include "DIO_interface.h"
#include "util/delay.h"


TaskHandle_t T1=NULL;
TaskHandle_t T2=NULL;
TaskHandle_t T3=NULL;

//Define Semaphore
SemaphoreHandle_t LCDsem;

//Define Queue
QueueHandle_t xQueue;
xQueueHandle T1_sus;

//Define Event Group
EventGroupHandle_t xEventGroup;

EventBits_t bitsToWaitFor = (1 << 4);
EventBits_t bitsWaited;


u8 KeyPressed=0;
u8 x;
u8 Password;


void GetPass(){

	u8 flag=0;
	while(1){
		if(flag==0){
			LCD_SendString("Enter Pass:");
			flag=1;
		}
		KeyPressed=KPD_u8GetPressedKey();
		if(KeyPressed != 0){
			GoToXY(x,1);
			LCD_sendChar(KeyPressed);
			xQueueSendToBack(xQueue, &KeyPressed, 10);
			x++;
			if(x==4){
				xEventGroupSetBits(xEventGroup,( 1 << 0 ));
				x=0;
			}
		}


	    vTaskDelay(50);

	}

}

void VerifyPass(){


	while(1){

		u8 xstatus;
		u8 pass[4]={'5','6','7','8'};
		u8 flag=0;

		xstatus = xEventGroupWaitBits(xEventGroup, (1 << 0), pdTRUE,pdTRUE,10);
		if (xstatus==1){

			if (xSemaphoreTake(LCDsem, 10) == pdTRUE) {

				for(u8 i=0;i<4;i++){
				xQueueReceive(xQueue, &Password, 10);
					if(Password != pass[i]){
					flag=1;
					break;
					}
				}
				if(flag==0){
					GoToXY(0,1);
					LCD_SendString("Welcome Sir");
					xEventGroupSetBits(xEventGroup,( 1 << 4 ));
					xSemaphoreGive(LCDsem);
					xQueueSend(T1_sus,0,10);
				//	vTaskSuspend(NULL);
					vTaskSuspend(T1);
					}
				else if(flag==1){
					GoToXY(0,1);
					LCD_SendString("haramyy!!");
					}
			}
		}
	 	vTaskDelay(300);
	}

}

void Calculate(){


	while(1){
			bitsWaited = xEventGroupWaitBits(xEventGroup, bitsToWaitFor, pdTRUE, pdTRUE, 10);
				if((bitsWaited & bitsToWaitFor) == bitsToWaitFor){
				u8 T1_sus_val = 0;
				u8 KeyVal;
				u8 i = 0;
				u8 flag = 0;
				u32 answer = 0;
				u8 num1[50],num2[50];

				start:
				LCD_SendCommand(0x01);
				GoToXY(0,0);
				LCD_SendString("Write Equation:");
				GoToXY(0,1);
				while(1){
					KeyVal= KPD_u8GetPressedKey();
					if(KeyVal != 0)
					{
						if( (KeyVal != '+') && (KeyVal != '-') && (KeyVal != 'x') && (KeyVal != '%') && (KeyVal != '#') )
						{
							LCD_sendChar(KeyVal);
							num1[i] = KeyVal;
							i++;
						}else if(KeyVal == '+')
						{
							LCD_sendChar(KeyVal);
							i=0;
							flag = 1;
							while(flag == 1)
							{
								KeyVal= KPD_u8GetPressedKey();
								if(KeyVal != 0)
								{
									if(KeyVal != '=')
									{
										LCD_sendChar(KeyVal);
										num2[i] = KeyVal;
										i++;
									}
									else if(KeyVal == '=')
									{
										LCD_sendChar(KeyVal);

										//GoToXY(1,0);
										answer = atoi(num1) + atoi(num2);
										LCD_voidWriteNumber(answer);
										LCD_SendString("      ");
									}
								}
							}
						}
							if(KeyVal == '#')
							{
								LCD_SendCommand(0x01);
								flag = 0;
								answer = 0;
								// Clear num1 array
									for (u8 j = 0; j < sizeof(num1); j++) {
										num1[j] = 0;
									}

									// Clear num2 array
									for (u8 j = 0; j < sizeof(num2); j++) {
										num2[j] = 0;
									}
								KeyVal = 0;
								i = 0;
								goto start;

								}else if(KeyVal == '%')
										{
											LCD_sendChar(KeyVal);
											i=0;
											flag = 1;
											while(flag == 1)
											{
												KeyVal= KPD_u8GetPressedKey();
												if(KeyVal != 0)
												{
													if(KeyVal != '=')
													{
														LCD_sendChar(KeyVal);
														num2[i] = KeyVal;
														i++;
													}
													else if(KeyVal == '=')
													{
														LCD_sendChar(KeyVal);
														answer = atoi(num1) / atoi(num2);
														LCD_voidWriteNumber(answer);
														LCD_SendString("      ");
													}
												}
											}
										}else if(KeyVal == '-')
												{
													LCD_sendChar(KeyVal);
													i=0;
													flag = 1;
													while(flag == 1)
													{
														KeyVal= KPD_u8GetPressedKey();
														if(KeyVal != 0)
														{
															if(KeyVal != '=')
															{
																LCD_sendChar(KeyVal);
																num2[i] = KeyVal;
																i++;
															}
															else if(KeyVal == '=')
															{
																LCD_sendChar(KeyVal);

																//GoToXY(1,0);
																answer = atoi(num1) - atoi(num2);
																LCD_voidWriteNumber(answer);
																LCD_SendString("      ");
															}
														}
													}


												}
												else if(KeyVal == 'x')
												{
													LCD_sendChar(KeyVal);
													i=0;
													flag = 1;
													while(flag == 1)
													{
														KeyVal= KPD_u8GetPressedKey();
														if(KeyVal != 0)
														{
															if(KeyVal != '=')
															{
																LCD_sendChar(KeyVal);
																num2[i] = KeyVal;
																i++;
															}
															else if(KeyVal == '=')
															{
																LCD_sendChar(KeyVal);
																answer = atoi(num1) * atoi(num2);
																LCD_voidWriteNumber(answer);
																LCD_SendString("      ");
															}
														}
													}
												  }
											}
										}
									}
				vTaskDelay(500);
				}
}







void main () {


		 LCD_init();
		 KPD_vidINIT();

		 LCDsem = xSemaphoreCreateMutex();
		 xQueue = xQueueCreate(10, 4);
		 xEventGroup = xEventGroupCreate();
		 T1_sus = xQueueCreate(1, sizeof(u16));

		 xTaskCreate(GetPass, NULL, 400, NULL, 1, &T1);
		 xTaskCreate(VerifyPass, NULL, 200, NULL, 1, &T2);
		 xTaskCreate(Calculate, NULL, 400, NULL, 2, &T3);


		 vTaskStartScheduler();


		while(1);



}

