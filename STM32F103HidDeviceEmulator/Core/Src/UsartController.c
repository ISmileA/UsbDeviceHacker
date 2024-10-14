/*
 * UsartController.c
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#include "UsartRouter.h"

uint8_t flag = 0;
uint8_t length = 0;
uint8_t parsedData = 0;
uint8_t buffer[32] = {};


void UsartCallback(){
	uint8_t byte = USART1->DR;
	if(byte == HEADER || flag){
		flag = 1;
		buffer[parsedData] = byte;
		if(parsedData == 3)
			length = byte;
		if(parsedData >= length+4){
			RxData *rxdata = &buffer;
			length = 0;
			flag = 0;
			ParsingData(rxdata);
		}
		parsedData++;
	}
}

void UsartDataTransmit(uint8_t *buf, uint8_t len){
	for (int i = 0; i < len; i++){
		while ((USART1->SR & USART_SR_TXE) == 0);
		USART1->DR = buf[i];
	}
}

