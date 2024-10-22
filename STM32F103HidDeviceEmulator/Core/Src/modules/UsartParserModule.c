/*
 * UsartRouter.c
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#include <modules/UsartAnswerModule.h>
#include <modules/UsartParserModule.h>
#include "crc8.h"

void ParsingData(uint8_t *buffer, uint8_t len){
	if(buffer[0] == HEADER){
		if(buffer[3]+5 == len){
			if(crc8(buffer, buffer[3]+4) == buffer[buffer[3]+4]){
				answer(USART_OK);
				action.command = buffer[2];
				action.length = buffer[3];
				for(uint8_t i=0; i<action.length; i++){
					action.data[i] = buffer[i+4];
				}
				action.device = buffer[1];
			}else
				answer(USART_ERROR);
		}
	}
}

