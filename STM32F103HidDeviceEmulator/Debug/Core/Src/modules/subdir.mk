################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modules/AnimationModule.c \
../Core/Src/modules/KeyboardModule.c \
../Core/Src/modules/MouseModule.c \
../Core/Src/modules/UsartParserModule.c 

OBJS += \
./Core/Src/modules/AnimationModule.o \
./Core/Src/modules/KeyboardModule.o \
./Core/Src/modules/MouseModule.o \
./Core/Src/modules/UsartParserModule.o 

C_DEPS += \
./Core/Src/modules/AnimationModule.d \
./Core/Src/modules/KeyboardModule.d \
./Core/Src/modules/MouseModule.d \
./Core/Src/modules/UsartParserModule.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modules/%.o Core/Src/modules/%.su Core/Src/modules/%.cyclo: ../Core/Src/modules/%.c Core/Src/modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modules

clean-Core-2f-Src-2f-modules:
	-$(RM) ./Core/Src/modules/AnimationModule.cyclo ./Core/Src/modules/AnimationModule.d ./Core/Src/modules/AnimationModule.o ./Core/Src/modules/AnimationModule.su ./Core/Src/modules/KeyboardModule.cyclo ./Core/Src/modules/KeyboardModule.d ./Core/Src/modules/KeyboardModule.o ./Core/Src/modules/KeyboardModule.su ./Core/Src/modules/MouseModule.cyclo ./Core/Src/modules/MouseModule.d ./Core/Src/modules/MouseModule.o ./Core/Src/modules/MouseModule.su ./Core/Src/modules/UsartParserModule.cyclo ./Core/Src/modules/UsartParserModule.d ./Core/Src/modules/UsartParserModule.o ./Core/Src/modules/UsartParserModule.su

.PHONY: clean-Core-2f-Src-2f-modules

