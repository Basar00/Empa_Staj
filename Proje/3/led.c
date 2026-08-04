#include "led.h"

void LED_Init(void) {
    //3ledli Output
    HAL_PCU_SetInOutMode(LED1_PORT, LED1_PIN, PCU_INOUT_OUTPUT_PUSH_PULL);
    HAL_PCU_SetInOutMode(LED2_PORT, LED2_PIN, PCU_INOUT_OUTPUT_PUSH_PULL);
    HAL_PCU_SetInOutMode(LED3_PORT, LED3_PIN, PCU_INOUT_OUTPUT_PUSH_PULL);

    // Başlangıçta hepsini söndür
    LED_UpdateChase(99);
}

void LED_UpdateChase(uint8_t active_index) {
    // Sadece sırası gelen LED'i yak
    HAL_PCU_SetOutputValue(LED1_PORT, LED1_PIN, (active_index == 0) ? PCU_PORT_LOW : PCU_PORT_HIGH);
    HAL_PCU_SetOutputValue(LED2_PORT, LED2_PIN, (active_index == 1) ? PCU_PORT_LOW : PCU_PORT_HIGH);
    HAL_PCU_SetOutputValue(LED3_PORT, LED3_PIN, (active_index == 2) ? PCU_PORT_LOW : PCU_PORT_HIGH);
}
