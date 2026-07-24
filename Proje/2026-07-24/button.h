#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include <stdbool.h>
#include "hal_pcu.h"

typedef enum {
    NO_PRESS = 0,
    SHORT_PRESS,
    LONG_PRESS
}
ButtonEvent_e;

void Button_Init(void);
ButtonEvent_e Button_Check(void);

#endif
