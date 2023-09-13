################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/FreeRTOS/croutine.c \
../COTS/FreeRTOS/event_groups.c \
../COTS/FreeRTOS/heap_1.c \
../COTS/FreeRTOS/list.c \
../COTS/FreeRTOS/mpu_wrappers.c \
../COTS/FreeRTOS/port.c \
../COTS/FreeRTOS/queue.c \
../COTS/FreeRTOS/stream_buffer.c \
../COTS/FreeRTOS/tasks.c \
../COTS/FreeRTOS/timers.c 

OBJS += \
./COTS/FreeRTOS/croutine.o \
./COTS/FreeRTOS/event_groups.o \
./COTS/FreeRTOS/heap_1.o \
./COTS/FreeRTOS/list.o \
./COTS/FreeRTOS/mpu_wrappers.o \
./COTS/FreeRTOS/port.o \
./COTS/FreeRTOS/queue.o \
./COTS/FreeRTOS/stream_buffer.o \
./COTS/FreeRTOS/tasks.o \
./COTS/FreeRTOS/timers.o 

C_DEPS += \
./COTS/FreeRTOS/croutine.d \
./COTS/FreeRTOS/event_groups.d \
./COTS/FreeRTOS/heap_1.d \
./COTS/FreeRTOS/list.d \
./COTS/FreeRTOS/mpu_wrappers.d \
./COTS/FreeRTOS/port.d \
./COTS/FreeRTOS/queue.d \
./COTS/FreeRTOS/stream_buffer.d \
./COTS/FreeRTOS/tasks.d \
./COTS/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
COTS/FreeRTOS/%.o: ../COTS/FreeRTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\Libary" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\MCAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\HAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\Nti_FreeRTOS_ATmega128\COTS\FreeRTOS" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


