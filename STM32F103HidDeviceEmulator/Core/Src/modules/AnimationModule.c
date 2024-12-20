/*
 * AnimationModule.c
 *
 *  Created on: Oct 19, 2024
 *      Author: ISmileA
 */

#include <modules/AnimationModule.h>
#include <math.h>

extern USBD_HandleTypeDef hUsbDeviceFS;
uint32_t time = 0;
uint8_t flag = 1;
uint8_t f = 0;
uint16_t data_set = 0;

int16_t x = 0, x_pos = 0, y_pos = 0, y = 0;

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

void AnimationSet(uint8_t *data, uint16_t len){
	flag = 1;
	animation.id = data[0];
	animation.length = len-1;
	for(uint8_t i=0; i<animation.length; i++)
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
		case(MOUSE_ROUND_ANIMATION):
			MouseRoundAnimation();
			break;
	}
}

void MouseMoveAnimation(){
	if((HAL_GetTick()-time) >= 5){
		uint8_t data_out[5] = {0x01, animation.data[1], 0, 0, 0};
		switch((char)animation.data[0]){
			case('r'):
				data_out[2] = 1+2*animation.data[2];
				break;
			case('l'):
				data_out[2] = 255-2*animation.data[2];
				break;
			case('b'):
				data_out[3] = 1+2*animation.data[2];
				break;
			case('t'):
				data_out[3] = 255-2*animation.data[2];
				break;
		}
		USBD_HID_SendReport(&hUsbDeviceFS, data_out, 5);
		time = HAL_GetTick();
	}
}
void KeyboardTextAnimation(){
	static uint32_t repeat_timer = 0;
	if((HAL_GetTick()-time) > 5){
		if(flag){
			uint8_t sp = 0, symb = 0;
			if (animation.data[data_set] >= (uint8_t)'0' && animation.data[data_set] <= (uint8_t)'9'){
				if (animation.data[data_set] == 48)
					symb = animation.data[data_set]-9;
				else
					symb = animation.data[data_set]-19;
				sp = 0;
			}else if(animation.data[data_set] >= (uint8_t)'A' && animation.data[data_set] <= (uint8_t)'Z'){
				symb = animation.data[data_set]-61;
				sp = 2;
			}else if(animation.data[data_set] >= (uint8_t)'a' && animation.data[data_set] <= (uint8_t)'z'){
				symb = animation.data[data_set]-93;
				sp = 0;
			}else if(animation.data[data_set] == (uint8_t)' '){
				symb = animation.data[data_set]+12;
				sp = 0;
			}else
				symb = 85;
			uint8_t data_out[9] = {0x02, sp, 0, symb, 0, 0, 0, 0, 0};
			data_set++;

			USBD_HID_SendReport(&hUsbDeviceFS, data_out, 9);
			HAL_Delay(30);
			uint8_t data_res[9] = {0x02, 0, 0, 0, 0, 0, 0, 0, 0};
			USBD_HID_SendReport(&hUsbDeviceFS, data_res, 9);
			HAL_Delay(30);

			if(data_set >= animation.length-1){
				data_set = 0;
				flag = 0;
				repeat_timer = HAL_GetTick();
			}
		}else if (animation.data[animation.length-1] != 0){
			if((HAL_GetTick()-repeat_timer) >= animation.data[animation.length-1]*100){
				flag = 1;
				repeat_timer = HAL_GetTick();
			}
		}
		time = HAL_GetTick();
	}
}
void MouseRoundAnimation(){
	uint16_t radius = animation.data[0], speed = animation.data[1], buttons = animation.data[2];
	if((HAL_GetTick()-time) >= 5){
		switch(f){
			case(0):
				x = 1+2*speed;
				if(x_pos == 0)
					y_pos = radius;
				x_pos+=x;
				y = abs(y_pos-(uint16_t)sqrt(radius*radius-x_pos*x_pos));
				y_pos-=y;
				if(x_pos >= radius){
					f = 1;
				}
				break;
			case(1):
				x = -(1+2*speed);
				x_pos+=x;
				y = abs(y_pos-(uint16_t)sqrt(radius*radius-x_pos*x_pos));
				y_pos+=y;
				if(x_pos <= 0){
					f = 2;
				}
				break;
			case(2):
				x = -(1+2*speed);
				x_pos+=x;
				y = -abs(y_pos-(uint16_t)sqrt(radius*radius-x_pos*x_pos));
				y_pos+=y;
				if(x_pos <= -radius){
					f = 3;
				}
				break;
			case(3):
				x = (1+2*speed);
				x_pos+=x;
				y = -abs(y_pos-(uint16_t)sqrt(radius*radius-x_pos*x_pos));
				y_pos-=y;
				if(x_pos >= 0){
					f = 0;
				}
				break;
		}
		uint8_t data_out[5] = {0x01, buttons, (uint8_t)x, (uint8_t)y, 0};
		USBD_HID_SendReport(&hUsbDeviceFS, data_out, 5);
		time = HAL_GetTick();
	}

}
