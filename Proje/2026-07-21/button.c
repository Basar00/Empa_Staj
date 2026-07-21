#include "button.h"

// State değişkenleri MCU RAM'inde tutulur
static uint32_t basili_kalma_sayaci = 0;
static uint8_t uzun_basis_tetiklendi = 0;

void Button_Init(void)
{
    // Başlangıç ayarları gerekiyorsa buraya yazılır
}

Button_Event_e Button_Process(void)
{
    PCU_PORT_e anlik_durum;
    HAL_PCU_GetInputValue(PCU_ID_C, PCU_PIN_ID_9, &anlik_durum);

    if (anlik_durum == PCU_PORT_LOW) // Butona basılıyor
    {
        basili_kalma_sayaci++;

        // Uzun basış eşiği
        if (basili_kalma_sayaci >= 10000 && uzun_basis_tetiklendi == 0)
        {
            uzun_basis_tetiklendi = 1;
            return BUTTON_EVENT_LONG; // Uzun basış olayı üret
        }
    }
    else // Butondan parmak çekildi
    {
        if (basili_kalma_sayaci > 100 && uzun_basis_tetiklendi == 0)
        {
            basili_kalma_sayaci = 0;
            return BUTTON_EVENT_SHORT; // Kısa basış olayı üret
        }

        basili_kalma_sayaci = 0;
        uzun_basis_tetiklendi = 0;
    }

    return BUTTON_EVENT_NONE;
}
