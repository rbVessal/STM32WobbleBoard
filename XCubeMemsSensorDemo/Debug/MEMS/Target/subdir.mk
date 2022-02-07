################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MEMS/Target/custom_motion_sensors.c \
../MEMS/Target/custom_motion_sensors_ex.c 

C_DEPS += \
./MEMS/Target/custom_motion_sensors.d \
./MEMS/Target/custom_motion_sensors_ex.d 

OBJS += \
./MEMS/Target/custom_motion_sensors.o \
./MEMS/Target/custom_motion_sensors_ex.o 


# Each subdirectory must supply rules for building sources it contributes
MEMS/Target/%.o: ../MEMS/Target/%.c MEMS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../MEMS/App -I../MEMS/Target -I../Drivers/BSP/B-U585I-IOT02A -I../Drivers/BSP/Components/ism330dhcx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MEMS-2f-Target

clean-MEMS-2f-Target:
	-$(RM) ./MEMS/Target/custom_motion_sensors.d ./MEMS/Target/custom_motion_sensors.o ./MEMS/Target/custom_motion_sensors_ex.d ./MEMS/Target/custom_motion_sensors_ex.o

.PHONY: clean-MEMS-2f-Target

