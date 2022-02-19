################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors.c \
../Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors_ex.c \
../Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors.c \
../Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors_ex.c 

C_DEPS += \
./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors.d \
./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors_ex.d \
./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors.d \
./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors_ex.d 

OBJS += \
./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors.o \
./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors_ex.o \
./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors.o \
./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors_ex.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/IKS01A2/Source/%.o: ../Drivers/BSP/IKS01A2/Source/%.c Drivers/BSP/IKS01A2/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../MEMS/App -I../MEMS/Target -I../Core/Inc -I../Drivers/BSP/STM32L4xx_Nucleo/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dsl/Include -I../Drivers/BSP/Components/lsm303agr/Include -I../Drivers/BSP/Components/hts221/Include -I../Drivers/BSP/Components/lps22hb/Include -I../Drivers/BSP/IKS01A2/Include -I../Drivers/BSP/Components/Common/Include -I../Middlewares/ST/STM32_MotionFX_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-IKS01A2-2f-Source

clean-Drivers-2f-BSP-2f-IKS01A2-2f-Source:
	-$(RM) ./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors.d ./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors.o ./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors_ex.d ./Drivers/BSP/IKS01A2/Source/iks01a2_env_sensors_ex.o ./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors.d ./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors.o ./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors_ex.d ./Drivers/BSP/IKS01A2/Source/iks01a2_motion_sensors_ex.o

.PHONY: clean-Drivers-2f-BSP-2f-IKS01A2-2f-Source

