#include "debug0.h"
#include "hal_adc.h"
#include <stdio.h>
#include <stdint.h>

extern void PRV_SCU_CLK_Init(void);

// Bit İşlemleri Yardımcı Fonksiyonları
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

// ADC0 ve AN0 (Kanal 0) Manuel Konfigürasyonu
void App_ADC_Force_Config(void)
{
    // 1. ADC0 Birimini Başlat
    HAL_ADC_Init(ADC_ID_0);

    // 2. ADC Mod Ayarları
    ADC_CFG_t tAdcCfg;
    tAdcCfg.eMode = ADC_MODE_SINGLE;           // Tekli/Manuel okuma modu
    tAdcCfg.eBaseTrgSrc = ADC_TRG_SRC_ADST;    // Yazılımsal Start (ADST) ile tetikleme
    tAdcCfg.eRef = ADC_REF_INT;                // İç Referans
    tAdcCfg.un8SeqCnt = 1;                     // 1 adet Sequence kullanılacak
    tAdcCfg.un8SamplingTime = 10;              // Örnekleme süresi
    tAdcCfg.bAutoRestart = false;              // Otomatik restart kapalı
    tAdcCfg.bChInfo = false;
    tAdcCfg.bTrgInfo = false;
    tAdcCfg.bSleep = false;
    HAL_ADC_SetConfig(ADC_ID_0, &tAdcCfg);

    // 3. Sequence 0 Tetikleme ve AN0 (Kanal 0) Bağlantısı
    ADC_SEQ_TRG_CFG_t tSeqCfg;
    tSeqCfg.eType = ADC_TRG_TYPE_SINGLE;
    tSeqCfg.eTrgSrc = ADC_TRG_SRC_ADST;
    tSeqCfg.utCfg.tSgl.un8ChNum = 0;           // AN0 (Kanal 0 - MIC_IN2)
    HAL_ADC_SetSeqConfig(ADC_ID_0, &tSeqCfg);
}

void PRV_USER_Code(void)
{
    char buffer[128];
    ADC_SEQ_DATA_t adc_seq_data;
    uint16_t mic_value = 0;
    uint8_t mic_status = 0x00;

    // 1. Sistem saatini ve Debug UART'ı ilklendir
    PRV_SCU_CLK_Init();
    My_Debug_Init();

    // 2. ADC Birimini Manuel Olarak AN0 (Kanal 0)'a Zorla
    App_ADC_Force_Config();

    // Voltaj/Açılış parazitini yutmak için bekleme
    for (volatile uint32_t i = 0; i < 3000000; i++);

    // UART Aktif (Bit 3 SET)
    bit_set(&mic_status, 3);

    My_Debug_Print("\r\n========================================\r\n");
    My_Debug_Print("    ANALOG MIKROFON ADC OKUMA TESTI     \r\n");
    My_Debug_Print("========================================\r\n");

    while (1)
    {
        // --- 3. ADC ÇEVRİMİNİ BAŞLAT VE BİTMESİNİ BEKLE ---
        HAL_ADC_Start(ADC_ID_0);
        HAL_ADC_SetWaitComplete(ADC_ID_0, 10000);

        // Sequence 0 üzerinden oku
        HAL_ADC_GetData(ADC_ID_0, 0, &adc_seq_data);
        mic_value = adc_seq_data.un16Result;

        // ADC Okuma Tamamlandı (Bit 0 SET)
        bit_set(&mic_status, 0);

        // --- 4. GERİLİM DÖNÜŞÜMÜ ---
        uint32_t mv = ((uint32_t)mic_value * 3300) / 4095;
        uint16_t volt_int = mv / 1000;
        uint16_t volt_frac = mv % 1000;

        // --- SES SEVİYESİ VE PEAK/ALARM KONTROLÜ ---
        bit_clear(&mic_status, 1);
        bit_clear(&mic_status, 2);

        char level_str[16] = "SESSIZ";

        // Sessizlikte 1800-2050 bandında gezindiği için yeni threshold'lar:
        // --- SENSÖR HASSASİYETİNE GÖRE YENİ DÜZENLEME ---
                // Sessiz ortam offset'i: 1800 - 2100 arası
                if (mic_value >= 1800 && mic_value <= 2100)
                {
                    sprintf(level_str, "SESSIZ");
                }
                else if ((mic_value >= 1500 && mic_value < 1800) || (mic_value > 2100 && mic_value <= 2400))
                {
                    sprintf(level_str, "NORMAL");
                    bit_set(&mic_status, 1); // Ses Algılandı (Bit 1 SET)
                }
                else // 2400'ün üstü veya 1500'ün altı (Artık üfleme ve konuşma da buraya düşecek!)
                {
                    sprintf(level_str, "YUKSEK SES");
                    bit_set(&mic_status, 1); // Ses Algılandı (Bit 1 SET)
                    bit_set(&mic_status, 2); // Yüksek Ses Alarmı (Bit 2 SET)
                }
        // --- 5. UART ÜZERİNDEN YAZDIRMA ---
        sprintf(buffer, "MIC RAW = %4d | Vadc = %d.%03dV | LEVEL = %-10s | STATUS = 0x%02X\r\n",
                mic_value, volt_int, volt_frac, level_str, mic_status);
        My_Debug_Print(buffer);

        if (bit_read(mic_status, 2))
        {
            My_Debug_Print(">>> ALARM! ANI YUKSEK SES DETECTED! <<<\r\n");
        }

        for (volatile uint32_t i = 0; i < 1000000; i++);
    }
}
