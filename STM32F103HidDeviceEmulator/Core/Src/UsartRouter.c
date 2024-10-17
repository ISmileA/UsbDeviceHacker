/*
 * UsartRouter.c
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#include "UsartRouter.h"
#include "crc8.h"
#include "UsartAnswerModule.h"

void ParsingData(uint8_t *buffer, uint8_t len){
	if(buffer[0] == HEADER){
		if(buffer[3]+5 == len){
			if(crc8(buffer, buffer[3]+4) == buffer[buffer[3]+4]){
				answer(USART_OK);
				action.command = buffer[2];
				for(uint8_t i=0; i<buffer[3]; i++){
					action.data[i] = buffer[i+4];
				}
				action.device = buffer[1];
			}else
				answer(USART_ERROR);
		}
	}
}

