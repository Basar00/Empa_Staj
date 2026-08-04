#include "debug0.h"

extern void PRV_SCU_CLK_Init(void);

void PRV_USER_Code(void)
{
    PRV_SCU_CLK_Init();
    My_Debug_Init();

    //Girilen saniyede bir Merhaba bas
    while (1)
    {
        My_Debug_Print("Merhaba\r\n");

        for (volatile uint32_t i = 0; i < 30000000; i++);
    }
}
