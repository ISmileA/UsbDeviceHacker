/*
 * UsartRouter.c
 *
 *  Created on: Oct 14, 2024
 *      Author: ISmileA
 */

#include <modules/UsartAnswerModule.h>
#include <modules/UsartParserModule.h>
#include "crc8.h"

void ParsingData(uint8_t *buffer, uint16_t len){
	if(buffer[0] == HEADER){
		uint16_t length_now = (uint16_t)buffer[3] | (uint16_t)(buffer[4] << 8);
		if(length_now+6 == len){
			if(crc8(buffer, length_now+5) == buffer[length_now+5]){
				answer(USART_OK);
				action.command = buffer[2];
				action.length = (uint16_t)buffer[3] | (uint16_t)(buffer[4] << 8);
				for(uint8_t i=0; i<action.length; i++){
					action.data[i] = buffer[i+5];
				}
				action.device = buffer[1];
			}else
				answer(USART_ERROR);
		}
	}
}
