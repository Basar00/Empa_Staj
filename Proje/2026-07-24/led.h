#ifndef LED_H
#define LED_H

#include "hal_pcu.h"

#define led_sayisi 14

void Led_Init(void);
void Led_SelfTest(void);
void Led_ChaseStep(bool reverse);
void Led_ToggleSingle(void);
void Led_FlashAll(void);
void Led_AllOff(void);

#endif
