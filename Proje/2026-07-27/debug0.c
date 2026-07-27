#include "debug0.h"
#include "hal_uart.h"
#include <string.h>

#define DEBUG_UART_PORT   UART_ID_0

void My_Debug_Init(void)
{
    // MCUBrew32 başlatmayı ürettiği için burası boş kalabilir
}

void My_Debug_Print(const char *text)
{
    if (text == NULL)
    {
        return;
    }

    uint32_t len = strlen(text);

    // Bütün metni tek seferde UART üzerinden fırlatıyoruz
    HAL_UART_Transmit(DEBUG_UART_PORT, (uint8_t *)text, len, 1000);
}
