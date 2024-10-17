/*
 * MouseController.h
 *
 *  Created on: Oct 16, 2024
 *      Author: arsen
 */

#ifndef INC_MOUSECONTROLLER_H_
#define INC_MOUSECONTROLLER_H_

#include "UsartController.h"
#include "usbd_hid.h"

void MouseCommandSetup(Action *act);

void MouseSet(uint8_t *data);
void MouseClick(uint8_t buttons);
void MouseRemove();


#endif /* INC_MOUSECONTROLLER_H_ */
