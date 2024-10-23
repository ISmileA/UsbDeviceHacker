/*
 * UsartController.c
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#include <modules/UsartParserModule.h>
#include "controllers/UsartController.h"

uint8_t length = 0;
uint8_t parsedData = 0;
uint8_t buffer[1024] = {};
uint32_t timer = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	uint8_t byte = rxcall;
	if((HAL_GetTick()-timer) > 2){
		length = 0;
		parsedData = 0;
	}
	if(byte == HEADER || parsedData > 0){
		buffer[parsedData] = byte;
		if(parsedData == 4)
			length = (uint16_t)(buffer[parsedData-1]) | (uint16_t)(buffer[parsedData] << 8);
		if(parsedData >= length+5){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			ParsingData(buffer, parsedData+1);
			length = 0;
			parsedData = 0;
		}else
			parsedData++;
	}
	timer = HAL_GetTick();
	HAL_UART_Receive_IT(huart,&rxcall,1);
}

