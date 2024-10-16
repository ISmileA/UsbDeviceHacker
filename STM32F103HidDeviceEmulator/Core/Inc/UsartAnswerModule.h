/*
 * UsartAnswerModule.h
 *
 *  Created on: Oct 15, 2024
 *      Author: arsen
 */

#ifndef INC_USARTANSWERMODULE_H_
#define INC_USARTANSWERMODULE_H_

#include "UsartController.h"
#include "crc8.h"

extern UART_HandleTypeDef huart3;

void answer(uint8_t data){
	uint8_t data_out[3] = {HEADER, data, 0};
	data_out[2] = crc8(data_out, 2);
	HAL_UART_Transmit(&huart3, data_out, 3, 100);
}


#endif /* INC_USARTANSWERMODULE_H_ */
