################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/hts221/hts221.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/hts221/hts221_reg.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lps22hb/lps22hb.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lps22hb/lps22hb_reg.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm303agr/lsm303agr.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm303agr/lsm303agr_reg.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm6dsl/lsm6dsl.c \
C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm6dsl/lsm6dsl_reg.c 

OBJS += \
./Drivers/BSP/Components/hts221.o \
./Drivers/BSP/Components/hts221_reg.o \
./Drivers/BSP/Components/lps22hb.o \
./Drivers/BSP/Components/lps22hb_reg.o \
./Drivers/BSP/Components/lsm303agr.o \
./Drivers/BSP/Components/lsm303agr_reg.o \
./Drivers/BSP/Components/lsm6dsl.o \
./Drivers/BSP/Components/lsm6dsl_reg.o 

C_DEPS += \
./Drivers/BSP/Components/hts221.d \
./Drivers/BSP/Components/hts221_reg.d \
./Drivers/BSP/Components/lps22hb.d \
./Drivers/BSP/Components/lps22hb_reg.d \
./Drivers/BSP/Components/lsm303agr.d \
./Drivers/BSP/Components/lsm303agr_reg.d \
./Drivers/BSP/Components/lsm6dsl.d \
./Drivers/BSP/Components/lsm6dsl_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/hts221.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/hts221/hts221.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/hts221.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/hts221_reg.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/hts221/hts221_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/hts221_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lps22hb.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lps22hb/lps22hb.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lps22hb.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lps22hb_reg.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lps22hb/lps22hb_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lps22hb_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lsm303agr.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm303agr/lsm303agr.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lsm303agr.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lsm303agr_reg.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm303agr/lsm303agr_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lsm303agr_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lsm6dsl.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm6dsl/lsm6dsl.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lsm6dsl.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lsm6dsl_reg.o: C:/Users/Beca\ Vessal/Documents/STM32WobbleBoard/DataLogFusion/Drivers/BSP/Components/lsm6dsl/lsm6dsl_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../../Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/lsm6dsl -I../../Drivers/BSP/Components/lsm303agr -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hb -I../../Drivers/BSP/IKS01A2 -I../../Drivers/BSP/Components/Common -I../../Middlewares/ST/STM32_MotionFX_Library/Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lsm6dsl_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/hts221.d ./Drivers/BSP/Components/hts221.o ./Drivers/BSP/Components/hts221_reg.d ./Drivers/BSP/Components/hts221_reg.o ./Drivers/BSP/Components/lps22hb.d ./Drivers/BSP/Components/lps22hb.o ./Drivers/BSP/Components/lps22hb_reg.d ./Drivers/BSP/Components/lps22hb_reg.o ./Drivers/BSP/Components/lsm303agr.d ./Drivers/BSP/Components/lsm303agr.o ./Drivers/BSP/Components/lsm303agr_reg.d ./Drivers/BSP/Components/lsm303agr_reg.o ./Drivers/BSP/Components/lsm6dsl.d ./Drivers/BSP/Components/lsm6dsl.o ./Drivers/BSP/Components/lsm6dsl_reg.d ./Drivers/BSP/Components/lsm6dsl_reg.o

.PHONY: clean-Drivers-2f-BSP-2f-Components

