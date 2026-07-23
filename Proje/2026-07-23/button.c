#include "button.h"

void Button_Init(void) {
    HAL_PCU_SetInOutMode(PCU_ID_C, PCU_PIN_ID_9, PCU_INOUT_INPUT);
}

ButtonEvent_e Button_Check(void) {
    PCU_PORT_e btn_val;
    HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &btn_val);
    bool is_pressed = (btn_val == 0);

    if (is_pressed) {
        // Basılı tutulduğu süreyi say
        uint32_t press_duration = 0;

        while (is_pressed) {
            press_duration++;
            for(volatile uint32_t d = 0; d < 100; d++);

            HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &btn_val);
            is_pressed = (btn_val == 0);

            // Uzun basma
            if (press_duration > 200) {
                // Debounce
                while(btn_val == 0) {
                    HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &btn_val);
                }
                return LONG_PRESS;
            }
        }

        // Kısa basma
        if (press_duration > 20) { // deboucne filtresi
            return SHORT_PRESS;
        }
    }
    return NO_PRESS;
}
