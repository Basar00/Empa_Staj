#include "debug0.h"
#include <stdio.h>

extern void PRV_SCU_CLK_Init(void);

void PRV_USER_Code(void)
{
    uint32_t raw_value = 0;
    uint32_t voltage_mv = 0;
    char buffer[64];

    //Sistem arayüzünü başlat
    PRV_SCU_CLK_Init();
    My_Debug_Init();


    //yaşanılan buglardan dolayı doğrudan bellek adresleriyle yazdım

    *((volatile uint32_t*)0x41010034) |= (1 << 20); // SCU_PCER2
    *((volatile uint32_t*)0x4101002C) |= (1 << 20); // SCU_PER2

    // AN2
    *((volatile uint32_t*)0x41010000) |= (7 << 8);

    // ADC0
    *((volatile uint32_t*)0x41012000) = 0x00000002; // AN2
    *((volatile uint32_t*)0x41012020) = 0x00000001; // ADEN = 1



    while (1)
    {
        // Çevrimi yapmaca
        *((volatile uint32_t*)0x41012020) |= (1 << 1);


        volatile uint32_t timeout = 100000;
        while (((*((volatile uint32_t*)0x41012024)) & (1 << 0)) && --timeout);

        // Ham veri
        raw_value = (*((volatile uint32_t*)0x41012030)) & 0x0FFF;

        // MV Hesabı
        voltage_mv = (raw_value * 3300) / 4095;

        // Yazdır
        sprintf(buffer, "BAT = %lu mV (raw: %lu)\r\n", voltage_mv, raw_value);
        My_Debug_Print(buffer);


        for (volatile uint32_t i = 0; i < 15000000; i++);
    }
}
