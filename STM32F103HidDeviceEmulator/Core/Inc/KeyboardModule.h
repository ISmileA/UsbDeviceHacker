/*
 * KeyboardModule.h
 *
 *  Created on: Oct 18, 2024
 *      Author: arsen
 */

#ifndef INC_KEYBOARDMODULE_H_
#define INC_KEYBOARDMODULE_H_

#include "UsartController.h"
#include "usbd_hid.h"

void KeyboardSetup(Action *act);

void KeyboardSet(uint8_t *data);
void KeyboardClick(uint8_t *data);
void KeyboardRemove();


#endif /* INC_KEYBOARDMODULE_H_ */