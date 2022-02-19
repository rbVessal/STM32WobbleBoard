################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/app_mems.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/com.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/demo_serial.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/iks01a2_mems_control.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/iks01a2_mems_control_ex.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/main.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/motion_fx_manager.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/serial_protocol.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/stm32l4xx_hal_msp.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/stm32l4xx_it.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/stm32l4xx_nucleo_bus.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c 

OBJS += \
./Application/User/app_mems.o \
./Application/User/com.o \
./Application/User/demo_serial.o \
./Application/User/iks01a2_mems_control.o \
./Application/User/iks01a2_mems_control_ex.o \
./Application/User/main.o \
./Application/User/motion_fx_manager.o \
./Application/User/serial_protocol.o \
./Application/User/stm32l4xx_hal_msp.o \
./Application/User/stm32l4xx_it.o \
./Application/User/stm32l4xx_nucleo_bus.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o 

C_DEPS += \
./Application/User/app_mems.d \
./Application/User/com.d \
./Application/User/demo_serial.d \
./Application/User/iks01a2_mems_control.d \
./Application/User/iks01a2_mems_control_ex.d \
./Application/User/main.d \
./Application/User/motion_fx_manager.d \
./Application/User/serial_protocol.d \
./Application/User/stm32l4xx_hal_msp.d \
./Application/User/stm32l4xx_it.d \
./Application/User/stm32l4xx_nucleo_bus.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/app_mems.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/app_mems.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/app_mems.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/com.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/com.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/com.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/demo_serial.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/demo_serial.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/demo_serial.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/iks01a2_mems_control.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/iks01a2_mems_control.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/iks01a2_mems_control.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/iks01a2_mems_control_ex.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/iks01a2_mems_control_ex.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/iks01a2_mems_control_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/motion_fx_manager.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/motion_fx_manager.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/motion_fx_manager.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/serial_protocol.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/serial_protocol.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/serial_protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l4xx_hal_msp.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/stm32l4xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32l4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l4xx_it.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/stm32l4xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32l4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l4xx_nucleo_bus.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Src/stm32l4xx_nucleo_bus.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32l4xx_nucleo_bus.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/app_mems.d ./Application/User/app_mems.o ./Application/User/com.d ./Application/User/com.o ./Application/User/demo_serial.d ./Application/User/demo_serial.o ./Application/User/iks01a2_mems_control.d ./Application/User/iks01a2_mems_control.o ./Application/User/iks01a2_mems_control_ex.d ./Application/User/iks01a2_mems_control_ex.o ./Application/User/main.d ./Application/User/main.o ./Application/User/motion_fx_manager.d ./Application/User/motion_fx_manager.o ./Application/User/serial_protocol.d ./Application/User/serial_protocol.o ./Application/User/stm32l4xx_hal_msp.d ./Application/User/stm32l4xx_hal_msp.o ./Application/User/stm32l4xx_it.d ./Application/User/stm32l4xx_it.o ./Application/User/stm32l4xx_nucleo_bus.d ./Application/User/stm32l4xx_nucleo_bus.o ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/sysmem.d ./Application/User/sysmem.o

.PHONY: clean-Application-2f-User

