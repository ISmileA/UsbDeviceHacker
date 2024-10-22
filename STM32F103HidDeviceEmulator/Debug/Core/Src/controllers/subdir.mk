################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/controllers/UsartController.c 

OBJS += \
./Core/Src/controllers/UsartController.o 

C_DEPS += \
./Core/Src/controllers/UsartController.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/controllers/%.o Core/Src/controllers/%.su Core/Src/controllers/%.cyclo: ../Core/Src/controllers/%.c Core/Src/controllers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -IC:/Users/arsen/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-controllers

clean-Core-2f-Src-2f-controllers:
	-$(RM) ./Core/Src/controllers/UsartController.cyclo ./Core/Src/controllers/UsartController.d ./Core/Src/controllers/UsartController.o ./Core/Src/controllers/UsartController.su

.PHONY: clean-Core-2f-Src-2f-controllers

