#include "debug0.h"
#include "hal_adc.h"
#include <stdio.h>
#include <stdint.h>

extern void PRV_SCU_CLK_Init(void);

void App_ADC_Init(void)
{
    HAL_ADC_Init(ADC_ID_0);

    ADC_CFG_t tAdcCfg = {
        .eMode           = ADC_MODE_SINGLE,
        .eBaseTrgSrc     = ADC_TRG_SRC_ADST,
        .eRef            = ADC_REF_INT,
        .un8SeqCnt       = 1,
        .un8SamplingTime = 2,
        .bAutoRestart    = false
    };
    HAL_ADC_SetConfig(ADC_ID_0, &tAdcCfg);

    ADC_SEQ_TRG_CFG_t tSeqCfg = {
        .eType            = ADC_TRG_TYPE_SINGLE,
        .eTrgSrc          = ADC_TRG_SRC_ADST,
        .utCfg.tSgl.un8ChNum = 0
    };
    HAL_ADC_SetSeqConfig(ADC_ID_0, &tSeqCfg);
}

void PRV_USER_Code(void)
{
    char buffer[16];
    ADC_SEQ_DATA_t adc_seq_data;

    PRV_SCU_CLK_Init();
    My_Debug_Init();
    App_ADC_Init();

    for (volatile uint32_t i = 0; i < 1000000; i++);

    while (1)
    {
        // ADC
        HAL_ADC_Start(ADC_ID_0);
        HAL_ADC_SetWaitComplete(ADC_ID_0, 1000);
        HAL_ADC_GetData(ADC_ID_0, 0, &adc_seq_data);

        int len = sprintf(buffer, "%d\r\n", adc_seq_data.un16Result);

        My_Debug_Print(buffer);

        for (volatile uint32_t i = 0; i < 2000; i++);
    }
}
