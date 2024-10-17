/*
 * UsartRouter.h
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#ifndef INC_USARTROUTER_H_
#define INC_USARTROUTER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "UsartController.h"




void ParsingData(uint8_t *buffer, uint8_t len);

#ifdef __cplusplus
}
#endif

#endif /* INC_USARTROUTER_H_ */
