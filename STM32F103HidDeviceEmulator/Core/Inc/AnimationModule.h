/*
 * AnimationModule.h
 *
 *  Created on: Oct 19, 2024
 *      Author: arsen
 */

#ifndef INC_ANIMATIONMODULE_H_
#define INC_ANIMATIONMODULE_H_

#include "UsartController.h"
#include "usbd_hid.h"

#define MOUSE_MOVE_ANIMATION 0x01

void AnimationSetup(Action *act);
void AnimationSet(uint8_t *data, uint8_t len);
void AnimationRemove();

void Animate();

void MouseMoveAnimation();
void MouseRoundAnimation();


#endif /* INC_ANIMATIONMODULE_H_ */
