#ifndef BUTTON_H
#define BUTTON_H

#include "hal_pcu.h"

// Butonun dışarıya bildireceği olaylar (Event'ler)
typedef enum {
    BUTTON_EVENT_NONE = 0,
    BUTTON_EVENT_SHORT,
    BUTTON_EVENT_LONG
} Button_Event_e;

// Dışarıdan çağrılacak fonksiyonlar
void Button_Init(void);
Button_Event_e Button_Process(void);

#endif
