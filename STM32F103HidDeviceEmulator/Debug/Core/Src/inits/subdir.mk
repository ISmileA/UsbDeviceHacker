################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/inits/gpio.c \
../Core/Src/inits/usart.c 

OBJS += \
./Core/Src/inits/gpio.o \
./Core/Src/inits/usart.o 

C_DEPS += \
./Core/Src/inits/gpio.d \
./Core/Src/inits/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/inits/%.o Core/Src/inits/%.su Core/Src/inits/%.cyclo: ../Core/Src/inits/%.c Core/Src/inits/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-inits

clean-Core-2f-Src-2f-inits:
	-$(RM) ./Core/Src/inits/gpio.cyclo ./Core/Src/inits/gpio.d ./Core/Src/inits/gpio.o ./Core/Src/inits/gpio.su ./Core/Src/inits/usart.cyclo ./Core/Src/inits/usart.d ./Core/Src/inits/usart.o ./Core/Src/inits/usart.su

.PHONY: clean-Core-2f-Src-2f-inits

