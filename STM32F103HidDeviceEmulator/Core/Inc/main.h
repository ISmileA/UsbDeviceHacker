#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

typedef struct{
	uint8_t device;
	uint8_t command;
	uint8_t length;
	uint8_t data[32];
} Action;

typedef struct {
	uint8_t id;
	uint8_t length;
	uint8_t data[512];
} Animation;

extern uint8_t rxcall;
extern Action action;
extern Animation animation;

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
