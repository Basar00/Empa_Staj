#include "abov_config.h"
#include "hal_i2c.h"
#include <stdio.h>

#include "sht4x_i2c.h"
#include "sensirion_i2c_hal.h"
#include "led.h"

extern void My_Debug_Print(const char *str);

static void SHT40_Delay_300ms(void)
{
    sensirion_i2c_hal_sleep_usec(300000);
}

void PRV_USER_Code(void)
{
    char log_buf[80];
    int16_t err;
    int32_t temp_milli_c = 0;
    int32_t hum_milli_rh = 0;


    Led_Init();
    sensirion_i2c_hal_init();
    sht4x_init(0x44);


    Led_AllOff();

    My_Debug_Print("\r\n==============================================\r\n");
    My_Debug_Print("  SHT40 SICAKLIK & NEM + FLASH ALARM MODU\r\n");
    My_Debug_Print("==============================================\r\n");


    while (1)
    {
        err = sht4x_measure_high_precision(&temp_milli_c, &hum_milli_rh);

        if (err == 0)
        {
            int32_t t_int  = temp_milli_c / 1000;
            int32_t t_frac = (temp_milli_c % 1000) / 10;
            if (t_frac < 0) t_frac = -t_frac;

            int32_t h_int  = hum_milli_rh / 1000;
            int32_t h_frac = (hum_milli_rh % 1000) / 100;

            snprintf(log_buf, sizeof(log_buf), "T=%ld.%02ld C   RH=%ld.%ld %%\r\n",
                     (long)t_int, (long)t_frac, (long)h_int, (long)h_frac);
            My_Debug_Print(log_buf);


            if (temp_milli_c >= 30000)
            {
                My_Debug_Print(" [DİKKAT!] BURASI YANIYOR KAÇIN\r\n");

                Led_FlashAll();
            }
            else
            {
                Led_AllOff();
            }
        }
        else
        {
            snprintf(log_buf, sizeof(log_buf), "ERR:SHT (%d)\r\n", err);
            My_Debug_Print(log_buf);
            Led_AllOff();
        }
        SHT40_Delay_300ms();
    }
}
