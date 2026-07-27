#include "debug0.h"

extern void PRV_SCU_CLK_Init(void);

void PRV_USER_Code(void)
{
    /* 1. Sistem saatlerini başlat */
    PRV_SCU_CLK_Init();

    /* 2. Debug kütüphanesini başlat */
    My_Debug_Init();

    /* 3. UART donanım hattı (TX pini) voltaj olarak HIGH oturana kadar azıcık bekle */
    for (volatile uint32_t i = 0; i < 2000000; i++);

    /* 4. Tera Term ekranını tamamen temizle ve imleci sol üste al (ANSI escape code) */
    My_Debug_Print("\033[2J\033[H");

    /* 5. Her 10 saniyede bir Merhaba bas */
    while (1)
    {
        My_Debug_Print("Merhaba\r\n");

        // 10 saniye bekleme döngüsü
        for (volatile uint32_t i = 0; i < 30000000; i++);
    }
}
