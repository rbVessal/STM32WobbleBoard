################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MEMS/Target/com.c \
../MEMS/Target/demo_serial.c \
../MEMS/Target/iks01a2_mems_control.c \
../MEMS/Target/iks01a2_mems_control_ex.c \
../MEMS/Target/motion_fx_manager.c \
../MEMS/Target/serial_protocol.c 

C_DEPS += \
./MEMS/Target/com.d \
./MEMS/Target/demo_serial.d \
./MEMS/Target/iks01a2_mems_control.d \
./MEMS/Target/iks01a2_mems_control_ex.d \
./MEMS/Target/motion_fx_manager.d \
./MEMS/Target/serial_protocol.d 

OBJS += \
./MEMS/Target/com.o \
./MEMS/Target/demo_serial.o \
./MEMS/Target/iks01a2_mems_control.o \
./MEMS/Target/iks01a2_mems_control_ex.o \
./MEMS/Target/motion_fx_manager.o \
./MEMS/Target/serial_protocol.o 


# Each subdirectory must supply rules for building sources it contributes
MEMS/Target/%.o: ../MEMS/Target/%.c MEMS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../MEMS/App -I../MEMS/Target -I../Core/Inc -I../Drivers/BSP/STM32L4xx_Nucleo/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dsl/Include -I../Drivers/BSP/Components/lsm303agr/Include -I../Drivers/BSP/Components/hts221/Include -I../Drivers/BSP/Components/lps22hb/Include -I../Drivers/BSP/IKS01A2/Include -I../Drivers/BSP/Components/Common/Include -I../Middlewares/ST/STM32_MotionFX_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MEMS-2f-Target

clean-MEMS-2f-Target:
	-$(RM) ./MEMS/Target/com.d ./MEMS/Target/com.o ./MEMS/Target/demo_serial.d ./MEMS/Target/demo_serial.o ./MEMS/Target/iks01a2_mems_control.d ./MEMS/Target/iks01a2_mems_control.o ./MEMS/Target/iks01a2_mems_control_ex.d ./MEMS/Target/iks01a2_mems_control_ex.o ./MEMS/Target/motion_fx_manager.d ./MEMS/Target/motion_fx_manager.o ./MEMS/Target/serial_protocol.d ./MEMS/Target/serial_protocol.o

.PHONY: clean-MEMS-2f-Target

