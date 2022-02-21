################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app_mems.c \
../Core/Src/com.c \
../Core/Src/crc.c \
../Core/Src/demo_serial.c \
../Core/Src/dma.c \
../Core/Src/gpio.c \
../Core/Src/iks01a2_mems_control.c \
../Core/Src/iks01a2_mems_control_ex.c \
../Core/Src/motion_fx_manager.c \
../Core/Src/rtc.c \
../Core/Src/serial_protocol.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/stm32l4xx_nucleo_bus.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c 

CPP_SRCS += \
../Core/Src/WobbleBoardApp.cpp \
../Core/Src/main.cpp 

C_DEPS += \
./Core/Src/app_mems.d \
./Core/Src/com.d \
./Core/Src/crc.d \
./Core/Src/demo_serial.d \
./Core/Src/dma.d \
./Core/Src/gpio.d \
./Core/Src/iks01a2_mems_control.d \
./Core/Src/iks01a2_mems_control_ex.d \
./Core/Src/motion_fx_manager.d \
./Core/Src/rtc.d \
./Core/Src/serial_protocol.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/stm32l4xx_nucleo_bus.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d 

OBJS += \
./Core/Src/WobbleBoardApp.o \
./Core/Src/app_mems.o \
./Core/Src/com.o \
./Core/Src/crc.o \
./Core/Src/demo_serial.o \
./Core/Src/dma.o \
./Core/Src/gpio.o \
./Core/Src/iks01a2_mems_control.o \
./Core/Src/iks01a2_mems_control_ex.o \
./Core/Src/main.o \
./Core/Src/motion_fx_manager.o \
./Core/Src/rtc.o \
./Core/Src/serial_protocol.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/stm32l4xx_nucleo_bus.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o 

CPP_DEPS += \
./Core/Src/WobbleBoardApp.d \
./Core/Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common/Include -I../Drivers/BSP/Components/hts221/Include -I../Drivers/BSP/Components/lps22hb/Include -I../Drivers/BSP/Components/lsm303agr/Include -I../Drivers/BSP/Components/lsm6dsl/Include -I../Drivers/BSP/IKS01A2/Include -I../Drivers/BSP/STM32L4xx_Nucleo/Include -I../Middlewares/ST/STM32_MotionFX_Library/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common/Include -I../Drivers/BSP/Components/hts221/Include -I../Drivers/BSP/Components/lps22hb/Include -I../Drivers/BSP/Components/lsm303agr/Include -I../Drivers/BSP/Components/lsm6dsl/Include -I../Drivers/BSP/IKS01A2/Include -I../Drivers/BSP/STM32L4xx_Nucleo/Include -I../Middlewares/ST/STM32_MotionFX_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/WobbleBoardApp.d ./Core/Src/WobbleBoardApp.o ./Core/Src/app_mems.d ./Core/Src/app_mems.o ./Core/Src/com.d ./Core/Src/com.o ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/demo_serial.d ./Core/Src/demo_serial.o ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/iks01a2_mems_control.d ./Core/Src/iks01a2_mems_control.o ./Core/Src/iks01a2_mems_control_ex.d ./Core/Src/iks01a2_mems_control_ex.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/motion_fx_manager.d ./Core/Src/motion_fx_manager.o ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/serial_protocol.d ./Core/Src/serial_protocol.o ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_nucleo_bus.d ./Core/Src/stm32l4xx_nucleo_bus.o ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/usart.d ./Core/Src/usart.o

.PHONY: clean-Core-2f-Src

