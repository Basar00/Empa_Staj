#include "button.h"

// State
static uint32_t basili_kalma_sayaci = 0;
static uint8_t uzun_basis_tetiklendi = 0;

void Button_Init(void)
{
}

Button_Event_e Button_Process(void)
{
    PCU_PORT_e anlik_durum;
    HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &anlik_durum);

    if (anlik_durum == PCU_PORT_LOW) 
    {
        basili_kalma_sayaci++;

        // Uzun basış
        if (basili_kalma_sayaci >= 10000 && uzun_basis_tetiklendi == 0)
        {
            uzun_basis_tetiklendi = 1;
            return BUTTON_EVENT_LONG;
        }
    }
    else
    {
        if (basili_kalma_sayaci > 100 && uzun_basis_tetiklendi == 0)
        {
            basili_kalma_sayaci = 0;
            return BUTTON_EVENT_SHORT;
        }

        basili_kalma_sayaci = 0;
        uzun_basis_tetiklendi = 0;
    }

    return BUTTON_EVENT_NONE;
}
