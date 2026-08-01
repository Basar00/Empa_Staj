# Günlük Rapor — Gün 09

## Bugün ne yaptım?

- ABOV mikrodentleyicisinde 12-bit ADC biriminin Single/Sequence modda yapılandırılması.
- AN0 pinine bağlı mikrofon modülünün çıkış voltajının okunması ve Vadc dönüştürülerek UART üzerinden basılması.
- Ortam ses seviyesine göre bit manipülasyonu ile STATUS register yönetimi ve Peak alarmı tetiklenmesi.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- ADC çevriminin bitmesini beklemeden (WaitComplete) verinin çekilmeye çalışılması sonucu eski/sabit değer okunması problemi.

## Teorik sorular

*1.* ADC (Analog-to-Digital Converter) nedir?
- Sürekli zamanlı analog gerilim sinyallerini, mikrodenetleyicilerin işleyebileceği dijital değerlere çeviren donanım birimidir.

*2.* Çözünürlük (Resolution) nedir? 12-bit ADC kaç farklı değer üretebilir?
- Çözünürlük, analog sinyalin kaç basamakta temsil edileceğini belirtir. 12-bit bir ADC 2^12 = 4096 farklı adım (0 - 4095 arası değer) üretir.

*3.* ADC Referans Voltajı (Vref) nedir ve neden önemlidir?
- ADC'nin ölçebileceği maksimum analog gerilim seviyesidir. Dijital adım aralığı Vref / (2^n) formülü ile belirlenir.

*4.* Örnekleme Süresi (Sampling Time) neyi ifade eder?
- ADC'nin içindeki örnekle ve tut kondansatörünün, analog pindeki gerilim seviyesine tam olarak şarj olabilmesi için verilen bekleme süresidir.

*5.* 12-bit çözünürlüğe ve 3.3V referansa sahip bir ADC'den 2048 değeri okunduysa gerçek gerilim değeri nedir?
- (2048 * 3.3V) / 4095 ≈ 1.65V