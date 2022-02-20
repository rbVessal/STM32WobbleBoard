################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/hts221/Source/hts221.c \
../Drivers/BSP/Components/hts221/Source/hts221_reg.c 

C_DEPS += \
./Drivers/BSP/Components/hts221/Source/hts221.d \
./Drivers/BSP/Components/hts221/Source/hts221_reg.d 

OBJS += \
./Drivers/BSP/Components/hts221/Source/hts221.o \
./Drivers/BSP/Components/hts221/Source/hts221_reg.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/hts221/Source/%.o: ../Drivers/BSP/Components/hts221/Source/%.c Drivers/BSP/Components/hts221/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common/Include -I../Drivers/BSP/Components/hts221/Include -I../Drivers/BSP/Components/lps22hb/Include -I../Drivers/BSP/Components/lsm303agr/Include -I../Drivers/BSP/Components/lsm6dsl/Include -I../Drivers/BSP/IKS01A2/Include -I../Drivers/BSP/STM32L4xx_Nucleo/Include -I../Middlewares/ST/STM32_MotionFX_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-hts221-2f-Source

clean-Drivers-2f-BSP-2f-Components-2f-hts221-2f-Source:
	-$(RM) ./Drivers/BSP/Components/hts221/Source/hts221.d ./Drivers/BSP/Components/hts221/Source/hts221.o ./Drivers/BSP/Components/hts221/Source/hts221_reg.d ./Drivers/BSP/Components/hts221/Source/hts221_reg.o

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-hts221-2f-Source

