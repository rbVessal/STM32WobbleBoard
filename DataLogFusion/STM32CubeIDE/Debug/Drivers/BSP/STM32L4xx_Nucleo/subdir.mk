################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.c 

OBJS += \
./Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.o 

C_DEPS += \
./Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.c Drivers/BSP/STM32L4xx_Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32L4xx_Nucleo

clean-Drivers-2f-BSP-2f-STM32L4xx_Nucleo:
	-$(RM) ./Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.d ./Drivers/BSP/STM32L4xx_Nucleo/stm32l4xx_nucleo.o

.PHONY: clean-Drivers-2f-BSP-2f-STM32L4xx_Nucleo

