################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/HAL/KPD_prog.c \
../COTS/HAL/LCD_program.c 

OBJS += \
./COTS/HAL/KPD_prog.o \
./COTS/HAL/LCD_program.o 

C_DEPS += \
./COTS/HAL/KPD_prog.d \
./COTS/HAL/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
COTS/HAL/%.o: ../COTS/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\Libary" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\MCAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\HAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\FreeRTOS" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


