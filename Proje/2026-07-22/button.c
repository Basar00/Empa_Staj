#include "button.h"

// Volatile kesme bayrağı
volatile bool exti_button_flag = false;

// ISR (Kesme İşleyicisi)
void Button_ISR_Handler(uint32_t status, void *context) {
    (void)status;
    (void)context;

    // 1. Sinyal (Bayrak) Kaldır
    exti_button_flag = true;

    // 2. KESME BAYRAĞINI TEMİZLE (Kilitlenmeyi Önler!)
    // ABOV HAL kütüphanesinde EXTI bayrağını temizleyen kodu buraya eklemelisin.
    // Eğer HAL kendi temizliyorsa bu adıma gerek yok, ama takılıyorsa sebep budur.
    // Örnek: HAL_PCU_ClearInterruptFlag(BTN_PORT, BTN_PIN);
}

void Button_Init(void) {
    HAL_PCU_SetInOutMode(BTN_PORT, BTN_PIN, PCU_INOUT_INPUT);

    // Sadece basıldığı an (Düşen Kenar)
    HAL_PCU_SetIntrPort(BTN_PORT, BTN_PIN, PCU_INTR_MODE_EDGE, PCU_INTR_TRG_LOW_FALLING, 0);

    PCU_IRQ_CFG_t irq_cfg = {0};
    irq_cfg.eId = BTN_PORT;
    irq_cfg.eOps = PCU_OPS_INTR;
    irq_cfg.pfnHandler = Button_ISR_Handler;
    irq_cfg.pContext = NULL;
    irq_cfg.un32IRQPrio = 3;
    HAL_PCU_SetIRQ(&irq_cfg);
}
