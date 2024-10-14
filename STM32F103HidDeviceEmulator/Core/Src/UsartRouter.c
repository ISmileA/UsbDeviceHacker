/*
 * UsartRouter.c
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#include "UsartRouter.h"
#include "crc8.h"


void ParsingData(RxData *rxdata){
	if(rxdata->header == HEADER){
		if(rxdata->length+5 == sizeof(rxdata)){
			if(crc8(rxdata, sizeof(rxdata)-1) == rxdata->crc8){

			}
		}
	}
}


