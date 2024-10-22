/*
 * AnimationModule.c
 *
 *  Created on: Oct 19, 2024
 *      Author: arsen
 */

#include <modules/AnimationModule.h>

extern USBD_HandleTypeDef hUsbDeviceFS;
uint32_t time = 0;
uint8_t flag = 1;
uint16_t data_set = 0;

void AnimationSetup(Action *act){
	switch(act->command){
		case(SET_COMMAND):
				AnimationSet(act->data, act->length);
				break;
		case(REMOVE_COMMAND):
				AnimationRemove();
				break;
	}
}

void AnimationSet(uint8_t *data, uint8_t len){
	flag = 1;
	animation.id = data[0];
	animation.length = len-1;
	for(uint8_t i=0; i<len-1; i++)
		animation.data[i] = data[i+1];
}

void AnimationRemove(){
	animation.id = 0;
}

void Animate(){
	switch(animation.id){
		case(MOUSE_MOVE_ANIMATION):
			MouseMoveAnimation();
			break;
		case(KEYBOARD_TEXT_ANIMATION):
			KeyboardTextAnimation();
			break;
	}
}

void MouseMoveAnimation(){
	if((HAL_GetTick()-time) >= 10){
		uint8_t data_out[5] = {0x01, animation.data[1], 0, 0, 0};
		switch((char)animation.data[0]){
			case('r'):
				data_out[2] = 1+2*animation.data[2];
				break;
			case('l'):
				data_out[2] = 254-2*animation.data[2];
				break;
			case('b'):
				data_out[3] = 1+2*animation.data[2];
				break;
			case('t'):
				data_out[3] = 254-2*animation.data[2];
				break;
		}
		USBD_HID_SendReport(&hUsbDeviceFS, data_out, 5);
		time = HAL_GetTick();
	}
}
void KeyboardTextAnimation(){
	if((HAL_GetTick()-time) > 5){
		if(flag){
			uint8_t data_out[9] = {0x02, animation.data[data_set+1], 0, animation.data[data_set], 0, 0, 0, 0, 0};
			data_set+=2;
			if(data_set >= animation.length-1){
				data_set = 0;
				flag = 0;
			}
			USBD_HID_SendReport(&hUsbDeviceFS, data_out, 9);
			HAL_Delay(30);
			uint8_t data_res[9] = {0x02, 0, 0, 0, 0, 0, 0, 0, 0};
			USBD_HID_SendReport(&hUsbDeviceFS, data_res, 9);
			HAL_Delay(30);
		}
		time = HAL_GetTick();
	}
}
