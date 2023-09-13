################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/MCAL/ADC_program.c \
../COTS/MCAL/DIO_program.c \
../COTS/MCAL/Tim1_program.c \
../COTS/MCAL/Timer_prog.c 

OBJS += \
./COTS/MCAL/ADC_program.o \
./COTS/MCAL/DIO_program.o \
./COTS/MCAL/Tim1_program.o \
./COTS/MCAL/Timer_prog.o 

C_DEPS += \
./COTS/MCAL/ADC_program.d \
./COTS/MCAL/DIO_program.d \
./COTS/MCAL/Tim1_program.d \
./COTS/MCAL/Timer_prog.d 


# Each subdirectory must supply rules for building sources it contributes
COTS/MCAL/%.o: ../COTS/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\Libary" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\MCAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\HAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\FreeRTOS" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


