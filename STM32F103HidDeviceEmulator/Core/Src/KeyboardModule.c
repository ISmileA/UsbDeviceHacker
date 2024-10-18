/*
 * KeyboardModule.c
 *
 *  Created on: Oct 18, 2024
 *      Author: arsen
 */

#include "KeyboardModule.h"
extern USBD_HandleTypeDef hUsbDeviceFS;

void KeyboardSetup(Action *act){
	switch(act->command){
		case(SET_COMMAND):
				KeyboardSet(act->data);
				break;
		case(CLICK_COMMAND):
				KeyboardClick(act->data);
				break;
		case(REMOVE_COMMAND):
				KeyboardRemove();
				break;
	}
}

void KeyboardSet(uint8_t *data){
	uint8_t data_out[9] = {};
	data_out[0] = 0x02;
	for(uint8_t i =0; i<8; i++)
		data_out[i+1] = data[i];
	USBD_HID_SendReport(&hUsbDeviceFS, data_out, 9);
}

void KeyboardClick(uint8_t *data){
	uint8_t data_out[9] = {};
	data_out[0] = 0x02;
	for(uint8_t i =0; i<8; i++)
		data_out[i+1] = data[i];
	USBD_HID_SendReport(&hUsbDeviceFS, data_out, 9);
	HAL_Delay(30);
	KeyboardRemove();
}

void KeyboardRemove(){
	uint8_t data_out[9] = {0x02, 0, 0, 0, 0, 0, 0, 0, 0};
	USBD_HID_SendReport(&hUsbDeviceFS, data_out, 9);
}

