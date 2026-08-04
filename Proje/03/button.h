#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdint.h>
#include <stdbool.h>
#include "hal_pcu.h"

#define BTN_PORT PCU_ID_C
#define BTN_PIN  PCU_PIN_ID_9

extern volatile bool exti_button_flag;

void Button_Init(void);

#endif /* BUTTON_H_ */
