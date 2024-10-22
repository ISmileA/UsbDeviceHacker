/*
 * UsartController.h
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#ifndef INC_USARTCONTROLLER_H_
#define INC_USARTCONTROLLER_H_

#include "main.h"
#include "UsartDataConfig.h"


typedef struct {
	uint8_t device;
	uint8_t command;
	uint8_t length;
	uint8_t data[32];
} RxData;


void UsartCallback();


#endif /* INC_USARTCONTROLLER_H_ */
