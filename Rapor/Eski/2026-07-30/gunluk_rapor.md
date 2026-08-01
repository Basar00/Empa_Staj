# Günlük Rapor — Gün 10

| Alan | Değer |
|------|-------|
| **Stajyer** | C — Başar Yıldırım |
| **Tarih** | 2026-07-31 |
| **Konu** | Mikrofon stream + Python grafik (1 kHz) |

## Bugün ne yaptım?

- Mikrofon verisini UART üzerinden sürekli stream yaparak Python tarafına aktardık. 'mic_plot.py' script'i ile zaman-genlik grafiğini canlı olarak çizdirdik.

## Görev durumu

| Madde | Yapıldı |
|--------|---------|
| Firmware stream | ☑ |
| Python canlı grafik | ☑ |
| 1 kHz sinüs testi | ☑ |

## Takıldığım yer

- Herhangi bir sorun olmadı.


## Teorik sorular

1. Dün tek tek MIC = … yazmak neden dalga şeklini göstermez?
- 

2. 1 kHz sinüs için teorik minimum örnekleme frekansı (Nyquist) nedir? Pratikte neden daha yüksek isteriz?
- 

3. Örnekleme çok yavaş olursa grafikte ne görürsün?
- 

4. Mikrofon sessizken grafik neden sıfırda değil, orta bir seviyede (bias) durur?
- 

5. UART baud rate düşük, örnek hızı yüksek olursa ne olur?
- 

6. MIC=2048 ile sadece 2048 satırı arasında Python için fark var mı? Hangisini tercih edersin, neden?
- 

7. Peak-to-peak (tepe–tepe) ne demektir? Ses seviyesi ile ilişkisi nedir?
- 

8. Aynı 1 kHz tonu daha uzaktan çalarsan grafikte ne değişir, ne değişmez?
- 

9. Dijital mikrofon (PDM/I2S) kullansaydık bugünkü UART+ADC grafiği aynı şekilde kurulur muydu?
- 

10. Canlı grafikte gördüğün “sinüs” neden laboratuvar osiloskopundaki kadar temiz olmayabilir? (en az 2 sebep)
- 

