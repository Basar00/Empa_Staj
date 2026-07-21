#include "button.h"

void PRV_USER_Code(void)
{
    uint8_t led_on = 0;

    // 1. Donanım ve Buton başlangıç ayarları
    HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_4, PCU_PORT_HIGH);   // Ana LED Sönük (PB4)
    HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_11, PCU_PORT_HIGH);  // 2. LED Sönük (PB11)
    Button_Init();

    while (1)
    {
        // 2. Buton modülünden güncel olayı (event) al
        Button_Event_e olay = Button_Process();

        // 3. Main sadece event'e tepki verir (Hocanın istediği yapı)
        if (olay == BUTTON_EVENT_SHORT)
        {
            // Kısa Basış: Ana LED (PB4) Toggle (Aç / Kapa)
            led_on = !led_on;
            if (led_on == 1) {
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_4, PCU_PORT_LOW);
            } else {
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_4, PCU_PORT_HIGH);
            }
        }
        else if (olay == BUTTON_EVENT_LONG)
        {
            // Uzun Basış: 2. LED (PB11) üzerinden farklı bir pattern / flaş patlat
            for(int i = 0; i < 3; i++) {
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_11, PCU_PORT_LOW);
                for (volatile uint32_t d = 0; d < 2000; d++);
                HAL_PCU_SetOutputValue(PCU_ID_B, PCU_PIN_ID_11, PCU_PORT_HIGH);
                for (volatile uint32_t d = 0; d < 2000; d++);
            }
        }
    }
}
