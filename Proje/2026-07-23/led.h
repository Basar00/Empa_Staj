#ifndef LED_H
#define LED_H

#include <stdint.h>
#include <stdbool.h>
#include "hal_pcu.h"

#define LED_COUNT 3

void Led_Init(void);
void Led_SelfTest(void);
void Led_ChaseStep(bool reverse);

#endif
