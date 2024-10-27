#include <modules/AnimationModule.h>
#include <modules/KeyboardModule.h>
#include <modules/MouseModule.h>
#include "main.h"
#include "inits/usart.h"
#include "inits/rcc.h"
#include "usb_device.h"
#include "inits/gpio.h"


extern UART_HandleTypeDef huart3;

uint8_t rxcall;
Action action = {0, 0, 0, {}};
Animation animation = {0, 0, {}};

void SystemClock_Config(void);

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_USB_DEVICE_Init();
	MX_USART3_UART_Init();
	HAL_UART_Receive_IT(&huart3,&rxcall,1);

	while (1)
	{
		switch(action.device){
			case(MOUSE):
				MouseCommandSetup(&action);
				action.device = 0;
				break;
			case(KEYBOARD):
				KeyboardSetup(&action);
				action.device = 0;
				break;
			case(ANIMATION):
				AnimationSetup(&action);
				action.device = 0;
				break;
		}
		Animate();
	}
}

