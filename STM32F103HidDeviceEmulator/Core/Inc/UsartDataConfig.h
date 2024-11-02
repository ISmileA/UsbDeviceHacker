/*
 * UsartDataConfig.h
 *
 *  Created on: Oct 14, 2024
 *      Author: ISmileA
 */

#ifndef INC_USARTDATACONFIG_H_
#define INC_USARTDATACONFIG_H_

#define HEADER 0xC5

#define MOUSE 0x01
#define KEYBOARD 0x02
#define ANIMATION 0x03

#define SET_COMMAND 0x01
#define REMOVE_COMMAND 0x02
#define CLICK_COMMAND 0x03
#define GET_COMMAND 0x04

#define USART_OK 0x01
#define USART_ERROR 0x00

#endif /* INC_USARTDATACONFIG_H_ */
