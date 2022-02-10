################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/iis2mdc/Source/iis2mdc.c \
../Drivers/BSP/Components/iis2mdc/Source/iis2mdc_reg.c 

C_DEPS += \
./Drivers/BSP/Components/iis2mdc/Source/iis2mdc.d \
./Drivers/BSP/Components/iis2mdc/Source/iis2mdc_reg.d 

OBJS += \
./Drivers/BSP/Components/iis2mdc/Source/iis2mdc.o \
./Drivers/BSP/Components/iis2mdc/Source/iis2mdc_reg.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/iis2mdc/Source/%.o: ../Drivers/BSP/Components/iis2mdc/Source/%.c Drivers/BSP/Components/iis2mdc/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../Core/Inc -I../Drivers/BSP/Components/ism330dhcx/Includes -I../Drivers/BSP/B-U585I-IOT02A/Includes -I../Drivers/BSP/Components/iis2mdc/Includes -I../Drivers/BSP/Components/Common/Includes -I../Libraries/STM32/Middleware/MotionFX/Includes -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-iis2mdc-2f-Source

clean-Drivers-2f-BSP-2f-Components-2f-iis2mdc-2f-Source:
	-$(RM) ./Drivers/BSP/Components/iis2mdc/Source/iis2mdc.d ./Drivers/BSP/Components/iis2mdc/Source/iis2mdc.o ./Drivers/BSP/Components/iis2mdc/Source/iis2mdc_reg.d ./Drivers/BSP/Components/iis2mdc/Source/iis2mdc_reg.o

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-iis2mdc-2f-Source

