#include <stdint.h>
#include <stdbool.h>
#include "hal_pcu.h"
#include "led.h"
#include "button.h"

void PRV_USER_Code(void) {
    // Modüller
    LED_Init();
    Button_Init();

    // Değişkenler
    uint8_t active_led = 0;
    uint32_t chase_timer = 0;
    bool dir_forward = true;

    // Hız Kademeleri
    const uint32_t SPEED_FAST = 120;   // Hızlı
    const uint32_t SPEED_MEDIUM = 350; // İstediğin o hafif yavaşlatılmış ideal base hız
    const uint32_t SPEED_SLOW = 750;   // Yavaş

    uint32_t current_speed = SPEED_MEDIUM; // Başlangıç hızı orta kademe

    // İlk LED'i yak
    LED_UpdateChase(active_led);

    while (1) {

        // ==========================================
        // KESME VE HIZ DEĞİŞTİRME
        // ==========================================
        if (exti_button_flag) {
            exti_button_flag = false;

            //Butona bas hızı değiştir
            if (current_speed == SPEED_MEDIUM) {
                current_speed = SPEED_FAST;
            } else if (current_speed == SPEED_FAST) {
                current_speed = SPEED_SLOW;
            } else {
                current_speed = SPEED_MEDIUM;
            }

            // Debounce (Ark Önleme)
            for (volatile uint32_t d = 0; d < 150; d++);
            exti_button_flag = false;
        }

        // ==========================================
        // KAYAN IŞIK
        // ==========================================
        chase_timer++;

        
        if (chase_timer > current_speed) {
            chase_timer = 0;

            if (dir_forward) {
                active_led++;
                if (active_led > 2) active_led = 0;
            } else {
                if (active_led == 0) active_led = 2;
                else active_led--;
            }

            LED_UpdateChase(active_led);
        }
    }
}
