/*
 * crc8.h
 *
 *  Created on: Oct 14, 2024
 *      Author: ISmileA
 */

#ifndef INC_CRC8_H_
#define INC_CRC8_H_

#include "main.h"

uint8_t crc8(uint8_t *buffer, uint8_t size) {
	uint8_t crc = 0;
	for (uint8_t i = 0; i < size; i++) {
		uint8_t data = buffer[i];
		for (int j = 8; j > 0; j--) {
		crc = ((crc ^ data) & 1) ? (crc >> 1) ^ 0x8C : (crc >> 1);
		data >>= 1;
		}
	}
	return crc;
}


#endif /* INC_CRC8_H_ */
