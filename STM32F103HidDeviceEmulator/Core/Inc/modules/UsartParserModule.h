/*
 * UsartRouter.h
 *
 *  Created on: Oct 14, 2024
 *      Author: arsen
 */

#ifndef INC_USARTPARSERMODULE_H_
#define INC_USARTPARSERMODULE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "controllers/UsartController.h"




void ParsingData(uint8_t *buffer, uint8_t len);

#ifdef __cplusplus
}
#endif

#endif /* INC_USARTPARSERMODULE_H_ */
