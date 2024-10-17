/*
 * MouseController.c
 *
 *  Created on: Oct 17, 2024
 *      Author: arsen
 */

#include "MouseController.h"
extern USBD_HandleTypeDef hUsbDeviceFS;

void MouseCommandSetup(Action *act){
	switch(act->command){
		case(SET_COMMAND):
			MouseSet(act->data);
			break;
		case(CLICK_COMMAND):
			MouseClick(act->data[0]);
			break;
		case(REMOVE_COMMAND):
			MouseRemove();
			break;
	}
}

void MouseSet(uint8_t *data){
	uint8_t data_out[5] = {0x01, 0, 0, 0, 0};
	for(uint8_t i=0; i<4; i++)
		data_out[i+1] = data[i];
	USBD_HID_SendReport(&hUsbDeviceFS, data_out, 5);
}

void MouseClick(uint8_t buttons){
	uint8_t data_out[5] = {0x01, buttons, 0, 0, 0};
	USBD_HID_SendReport(&hUsbDeviceFS, data_out, 5);
	HAL_Delay(30);
	MouseRemove();
}

void MouseRemove(){
	uint8_t data_out[5] = {0x01, 0, 0, 0, 0};
	USBD_HID_SendReport(&hUsbDeviceFS, data_out, 5);
}

