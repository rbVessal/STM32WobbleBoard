################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a.c \
../Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_bus.c \
../Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_motion_sensors.c 

C_DEPS += \
./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a.d \
./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_bus.d \
./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_motion_sensors.d 

OBJS += \
./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a.o \
./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_bus.o \
./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_motion_sensors.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/B-U585I-IOT02A/Source/%.o: ../Drivers/BSP/B-U585I-IOT02A/Source/%.c Drivers/BSP/B-U585I-IOT02A/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../Core/Inc -I../Drivers/BSP/Components/ism330dhcx/Includes -I../Drivers/BSP/B-U585I-IOT02A/Includes -I../Drivers/BSP/Components/iis2mdc/Includes -I../Drivers/BSP/Components/Common/Includes -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../Libraries/STM32/Middleware/MotionFX/Includes -I../ExternalAppFiles/Includes -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-B-2d-U585I-2d-IOT02A-2f-Source

clean-Drivers-2f-BSP-2f-B-2d-U585I-2d-IOT02A-2f-Source:
	-$(RM) ./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a.d ./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a.o ./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_bus.d ./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_bus.o ./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_motion_sensors.d ./Drivers/BSP/B-U585I-IOT02A/Source/b_u585i_iot02a_motion_sensors.o

.PHONY: clean-Drivers-2f-BSP-2f-B-2d-U585I-2d-IOT02A-2f-Source

