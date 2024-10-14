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

typedef struct RxDataTag{
	uint8_t header;
	uint8_t device;
	uint8_t command;
	uint8_t length;
	uint8_t data[32];
	uint8_t crc8;
} RxData;

typedef struct TxDataTag{
	uint8_t header;
	uint8_t data;
	uint8_t crc8;
} TxData;

void UsartCallback();
void UsartDataTransmit(uint8_t *buf, uint8_t len);


#endif /* INC_USARTCONTROLLER_H_ */
