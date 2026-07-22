#ifndef LED_H_
#define LED_H_

#include <stdint.h>
#include <stdbool.h>
#include "hal_pcu.h"


#define LED1_PORT PCU_ID_B
#define LED1_PIN  PCU_PIN_ID_10

#define LED2_PORT PCU_ID_B
#define LED2_PIN  PCU_PIN_ID_11


#define LED3_PORT PCU_ID_B
#define LED3_PIN  PCU_PIN_ID_12

void LED_Init(void);
void LED_UpdateChase(uint8_t active_index);

#endif /* LED_H_ */
