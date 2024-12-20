/*
 * AnimationModule.h
 *
 *  Created on: Oct 19, 2024
 *      Author: ISmileA
 */

#ifndef INC_ANIMATIONMODULE_H_
#define INC_ANIMATIONMODULE_H_

#include <modules/KeyboardModule.h>
#include "controllers/UsartController.h"
#include "usbd_hid.h"

#define MOUSE_MOVE_ANIMATION 0x01
#define KEYBOARD_TEXT_ANIMATION 0x02
#define MOUSE_ROUND_ANIMATION 0x03

void AnimationSetup(Action *act);
void AnimationSet(uint8_t *data, uint16_t len);
void AnimationRemove();

void Animate();

void MouseMoveAnimation();
void KeyboardTextAnimation();
void MouseRoundAnimation();


#endif /* INC_ANIMATIONMODULE_H_ */
