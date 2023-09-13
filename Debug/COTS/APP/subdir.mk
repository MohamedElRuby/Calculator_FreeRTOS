################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/APP/Calculator.c \
../COTS/APP/FanSystem.c \
../COTS/APP/main.c 

OBJS += \
./COTS/APP/Calculator.o \
./COTS/APP/FanSystem.o \
./COTS/APP/main.o 

C_DEPS += \
./COTS/APP/Calculator.d \
./COTS/APP/FanSystem.d \
./COTS/APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
COTS/APP/%.o: ../COTS/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\Libary" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\MCAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\HAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\FreeRTOS" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


