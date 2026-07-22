#include "button.h"

// Volatile kesme bayrağı
volatile bool exti_button_flag = false;

// ISR
void Button_ISR_Handler(uint32_t status, void *context) {
    (void)status;
    (void)context;

    //SinyalKaldır
    exti_button_flag = true;
}

void Button_Init(void) {
    HAL_PCU_SetInOutMode(BTN_PORT, BTN_PIN, PCU_INOUT_INPUT);

    // Falling edge
    HAL_PCU_SetIntrPort(BTN_PORT, BTN_PIN, PCU_INTR_MODE_EDGE, PCU_INTR_TRG_LOW_FALLING, 0);

    PCU_IRQ_CFG_t irq_cfg = {0};
    irq_cfg.eId = BTN_PORT;
    irq_cfg.eOps = PCU_OPS_INTR;
    irq_cfg.pfnHandler = Button_ISR_Handler;
    irq_cfg.pContext = NULL;
    irq_cfg.un32IRQPrio = 3;
    HAL_PCU_SetIRQ(&irq_cfg);
}
