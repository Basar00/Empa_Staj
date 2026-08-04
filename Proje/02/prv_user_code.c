#include "button.h"

void PRV_USER_Code(void)
{
    uint8_t led_on = 0;

    HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_4, PCU_PORT_HIGH); 
    HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_11, PCU_PORT_HIGH);
    Button_Init();

    while (1)
    {
        // event al
        Button_Event_e olay = Button_Process();

        //event'e tepki
        if (olay == BUTTON_EVENT_SHORT)
        {
            // Kısa Basış
            led_on = !led_on;
            if (led_on == 1) {
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_4, PCU_PORT_LOW);
            } else {
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_4, PCU_PORT_HIGH);
            }
        }
        else if (olay == BUTTON_EVENT_LONG)
        {
            // Uzun Basış: flaş
            for(int i = 0; i < 3; i++) {
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_11, PCU_PORT_LOW);
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_10, PCU_PORT_LOW);
                for (volatile uint32_t d = 0; d < 2000; d++);
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_11, PCU_PORT_HIGH);
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_10, PCU_PORT_HIGH);
                for (volatile uint32_t d = 0; d < 2000; d++);
            }
        }
    }
}
