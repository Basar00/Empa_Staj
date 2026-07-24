#include "button.h"
#include "led.h"


void Button_Init(void) {
    HAL_PCU_SetInOutMode(PCU_ID_C, PCU_PIN_ID_9, PCU_INOUT_INPUT);
}

ButtonEvent_e Button_Check(void) {
    PCU_PORT_e buton;
    HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &buton);
    bool basildi = (buton == 0);

    if (basildi) {
        // Basılı tutulduğu süreyi sayma
        uint32_t basma_suresi = 0;

        while (basildi) {
            basma_suresi++;
            for(volatile uint32_t d = 0; d < 100; d++);

            HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &buton);
            basildi = (buton == 0);

            // Uzun basma
            if (basma_suresi > 200) {
                // Debounce
                while(buton == 0) {
                	Led_FlashAll();

                    for(volatile uint32_t d = 0; d < 8000; d++);

                    HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &buton);
                }
                return LONG_PRESS;
            }
        }

        // Kısa basma
        if (basma_suresi > 20) { // deboucne filtresi
            return SHORT_PRESS;
        }
    }
    return NO_PRESS;
}
