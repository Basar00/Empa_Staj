#include "led.h"
//bütün ledlerle denedim
static const PCU_PIN_ID_e led_pinleri[led_sayisi] = {PCU_PIN_ID_1, PCU_PIN_ID_2, PCU_PIN_ID_3, PCU_PIN_ID_4, PCU_PIN_ID_5, PCU_PIN_ID_6, PCU_PIN_ID_8, PCU_PIN_ID_9, PCU_PIN_ID_10, PCU_PIN_ID_11, PCU_PIN_ID_12, PCU_PIN_ID_13, PCU_PIN_ID_14, PCU_PIN_ID_15};
static uint8_t active_index = 0;

void Led_Init(void) {
    for(int i = 0; i < led_sayisi; i++) {
        HAL_PCU_SetInOutMode(PCU_ID_B, led_pinleri[i], PCU_INOUT_OUTPUT_PUSH_PULL);
    }
}


static void local_delay(volatile uint32_t count) {
    while(count--) {
        // Boş döngü
    }
}

void Led_SelfTest(void) {
    for (int i = 0; i < led_sayisi; i++) {
        HAL_PCU_SetOutputValue(PCU_ID_B, led_pinleri[i], (PCU_PORT_e)0); // aç
        local_delay(2000);
        HAL_PCU_SetOutputValue(PCU_ID_B, led_pinleri[i], (PCU_PORT_e)1); // kapa
    }
}

//ileri veya Geri
void Led_ChaseStep(bool reverse) {
    // ledleri güncelle
    for (int i = 0; i < led_sayisi; i++) {
        if (i == active_index) {
            HAL_PCU_SetOutputValue(PCU_ID_B, led_pinleri[i], (PCU_PORT_e)0); // Yak
        } else {
            HAL_PCU_SetOutputValue(PCU_ID_B, led_pinleri[i], (PCU_PORT_e)1); // Söndür
        }
    }

    // İndeksi ilerlet veya gerilet
    if (reverse == false) {
        active_index++;
        if (active_index >= led_sayisi) active_index = 0;
    } else {
        if (active_index == 0) active_index = led_sayisi - 1;
        else active_index--;
    }
}
