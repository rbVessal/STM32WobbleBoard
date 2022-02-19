################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MEMS/App/app_mems.c 

C_DEPS += \
./MEMS/App/app_mems.d 

OBJS += \
./MEMS/App/app_mems.o 


# Each subdirectory must supply rules for building sources it contributes
MEMS/App/%.o: ../MEMS/App/%.c MEMS/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../MEMS/App -I../MEMS/Target -I../Core/Inc -I../Drivers/BSP/STM32L4xx_Nucleo/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dsl/Include -I../Drivers/BSP/Components/lsm303agr/Include -I../Drivers/BSP/Components/hts221/Include -I../Drivers/BSP/Components/lps22hb/Include -I../Drivers/BSP/IKS01A2/Include -I../Drivers/BSP/Components/Common/Include -I../Middlewares/ST/STM32_MotionFX_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MEMS-2f-App

clean-MEMS-2f-App:
	-$(RM) ./MEMS/App/app_mems.d ./MEMS/App/app_mems.o

.PHONY: clean-MEMS-2f-App

