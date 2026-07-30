#include "debug0.h"
#include "hal_adc.h"
#include <stdio.h>
#include <stdint.h>

extern void PRV_SCU_CLK_Init(void);

void bit_set(uint8_t *reg, uint8_t bit) {
    *reg |= (1 << bit);
}

void bit_clear(uint8_t *reg, uint8_t bit) {
    *reg &= ~(1 << bit);
}

void bit_toggle(uint8_t *reg, uint8_t bit) {
    *reg ^= (1 << bit);
}

uint8_t bit_read(uint8_t reg, uint8_t bit) {
    return (reg & (1 << bit)) ? 1 : 0;
}

// ADC0 ve AN0 Manuel Konfigürasyonu
void App_ADC_Force_Config(void)
{
    //ADC0
    HAL_ADC_Init(ADC_ID_0);

    //ADC Mod Ayarları
    ADC_CFG_t tAdcCfg;
    tAdcCfg.eMode = ADC_MODE_SINGLE;         
    tAdcCfg.eBaseTrgSrc = ADC_TRG_SRC_ADST;   
    tAdcCfg.eRef = ADC_REF_INT;      
    tAdcCfg.un8SeqCnt = 1;              
    tAdcCfg.un8SamplingTime = 10;           
    tAdcCfg.bAutoRestart = false;   
    tAdcCfg.bChInfo = false;
    tAdcCfg.bTrgInfo = false;
    tAdcCfg.bSleep = false;
    HAL_ADC_SetConfig(ADC_ID_0, &tAdcCfg);

    //AN0
    ADC_SEQ_TRG_CFG_t tSeqCfg;
    tSeqCfg.eType = ADC_TRG_TYPE_SINGLE;
    tSeqCfg.eTrgSrc = ADC_TRG_SRC_ADST;
    tSeqCfg.utCfg.tSgl.un8ChNum = 0;
    HAL_ADC_SetSeqConfig(ADC_ID_0, &tSeqCfg);
}

void PRV_USER_Code(void)
{
    char buffer[128];
    ADC_SEQ_DATA_t adc_seq_data;
    uint16_t mic_value = 0;
    uint8_t mic_status = 0x00;

    PRV_SCU_CLK_Init();
    My_Debug_Init();

    //Manuel Olarak AN0
    App_ADC_Force_Config();

    for (volatile uint32_t i = 0; i < 3000000; i++);

    // UART Aktif
    bit_set(&mic_status, 3);

    My_Debug_Print("\r\n========================================\r\n");
    My_Debug_Print("    ANALOG MIKROFON ADC OKUMA TESTI     \r\n");
    My_Debug_Print("========================================\r\n");

    while (1)
    {

        HAL_ADC_Start(ADC_ID_0);
        HAL_ADC_SetWaitComplete(ADC_ID_0, 10000);

        HAL_ADC_GetData(ADC_ID_0, 0, &adc_seq_data);
        mic_value = adc_seq_data.un16Result;

        bit_set(&mic_status, 0);

        uint32_t mv = ((uint32_t)mic_value * 3300) / 4095;
        uint16_t volt_int = mv / 1000;
        uint16_t volt_frac = mv % 1000;

        bit_clear(&mic_status, 1);
        bit_clear(&mic_status, 2);

        char level_str[16] = "SESSIZ";

                // Sessiz ortam 1800 - 2100 arası
                if (mic_value >= 1800 && mic_value <= 2100)
                {
                    sprintf(level_str, "SESSIZ");
                }
                else if ((mic_value >= 1500 && mic_value < 1800) || (mic_value > 2100 && mic_value <= 2400))
                {
                    sprintf(level_str, "NORMAL");
                    bit_set(&mic_status, 1); // Ses Algılandı
                }
                else //  x < 1500, 2400 > x
                {
                    sprintf(level_str, "YUKSEK SES");
                    bit_set(&mic_status, 1); 
                    bit_set(&mic_status, 2); // Yüksek Ses Alarmı
                }
       
        sprintf(buffer, "MIC RAW = %4d | Vadc = %d.%03dV | LEVEL = %-10s | STATUS = 0x%02X\r\n",
                mic_value, volt_int, volt_frac, level_str, mic_status);
        My_Debug_Print(buffer);

        if (bit_read(mic_status, 2))
        {
            My_Debug_Print(">>> DIKKAT! YUKSEK SES! <<<\r\n");
        }

        for (volatile uint32_t i = 0; i < 1000000; i++);
    }
}
