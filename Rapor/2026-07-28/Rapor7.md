# Günlük Rapor — Gün 07

| Alan | Değer |
|------|-------|
| **Stajyer** | C — Başar Yıldırım |
| **Tarih** | 2026-07-28 |
| **Konu** | Timer, tick, periyodik görev |

## Bugün ne yaptım?

- ABOV A34G43x mikrodenetleyicisi üzerinde ADC kanal yapılandırması, ham veriyi (raw) milivolta (mV) dönüştüren sistem.


## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- Bazı buglar ve uygun pini ararken bazı sorunlar yaşadım.


## Datasheet

### A) Kart dökümanı / şema

| Soru | Cevabın |
|------|---------|
| Pil sense net’inin adı? (VBAT, BAT_ADC, …) | VBAT |
| Hangi MCU pin’i? (port + pin) | PA2 |
| Gerilim bölücü var mı? Dirençler? | Yok |
| Bölücü oranı \(k\)? | 1 |

### B) MCU datasheet (A34G43x — ADC)

| Soru | Cevabın |
|------|---------|
| Bu pin hangi **ADC kanalı**? | AN2 |
| Çözünürlük kaç bit? | 12 bit |
| Vref kaynağı / tipik Vref? | 3.3V AVDD |
| Max giriş voltajı? | AVDD |


## Teorik sorular

*1.* ADC açılımı nedir? Analog sinyali neden doğrudan mikrodenetleyici işleyemez?
- ADC = Analog to Digital Converter 

- Mikrodenetleyiciler sadece 0 ve 1 i algılayabildikleri için dışarıdan gelen fiziksel olayları doğrudan işleyemez. İlk başta analog büyüklükleri sayısal koda çevirmesi gerekir.


*2.* 12 bit bir ADC’de teorik olarak kaç farklı dijital seviye vardır? Maksimum ham değer genelde kaçtır?
- 12 bitlik için 2^12= 4096

- Max raw = 4095


*3.* Adım boyutu (LSB gerilimi) formülü nedir? Vref = 3.3 V ve 12 bit için yaklaşık adım boyutu kaç mV’dur?
- VRef  / 2^n-1  -> 3.3v/2^12 - 1 
LSB = 0,81 mv


*4.* Ham ADC değeri raw = 1024, Vref = 3.3 V, 12 bit, bölücü yok. (V_{adc}) yaklaşık kaç volttur? (Hesap göster)
- Vadc = raw. (VRef/2^n)  = 1024.(3.3v/2^12)
Vadc = 0,825V


*5.* Pil gerilimi 4.2 V iken ADC giriş aralığı 3.3 V ise ne yapılır? Neden doğrudan bağlanmaz?
- Pil gerilimini düşürmek için Voltage divider eklenebilir.

-  GPIO ve ADC giriş pinlerinin max tolerans sınırları vardır. Voltage Dviider, pinin maksimum çalışma gerilimini aşarsa mikrodenetleyici zarar görüp yanabilir.


*6.* “ADC kanalı” ne demektir? Pil ölçümünde yanlış kanal seçersen ne olur?
- Fiziksel olarak farklı dış pinlerinden gelen analog sinyalleri, içerideki ortak ADC çevirici birimine bağlayan "mux" geçitleridir.

- Pilin bağlı olduğu pin yerine boşta duran bir pin okunursa -> pilden bağımsız olarak mantıksız, sabit, rastgele veya yanlış gerilim değerleri okunur.
 

*7.* Tek çevrim (single) ile sürekli (continuous) çevrim modu arasındaki fark nedir? Pil izleme için hangisi daha doğal gelir? Neden?
- Single Mode: Tetiklendiğinde yalnızca bir kez analog ölçüm yapar, sonucu kaydeder ve ADC durur.

- Continuous: Durmaksızın otomatik olarak analog örnekleme yapmaya devam eder.

- Pil seviyesi çok yavaş değiştiğinden belirli aralıklarla bakmak güç açısından en mantıklısı olur.


*8.* Datasheet’te pil ölçümü için hangi bilgileri ararsın? En az 3 madde yaz.
- ADC Çözünürlüğü ve Kanal Yapısı: Kaç bit olduğu ve kaç adet analog giriş kanalına sahip olduğu.

- Referans Gerilimi Özellikleri: Dahili referans voltaj kaynağı olup olmadığı veya harici referans sınırlarının ne olduğu.

- Maksimum Giriş Gerilimi Sınırları: Pinlerin dayanabileceği mutlak maksimum gerilim değerleri.


*9.* Kart şemasında gerilim bölücü oranı (k = 2) ve ADC pininde 1.80 V ölçülüyorsa pil gerilimi kaç volttur?
- Vp = 2. 1.80V = 3,60


*10.* Çözünürlük artınca hassasiyet nasıl değişir? Hız genelde nasıl etkilenir?
- Hassasiyet: Artar. Çözünürlük bit değeri arttıkça LSB küçülür.

- Hız: Genelde yavaşlar. Çözürünürlük için devrelerin daha fazla örnekleme ve yerleşme süresine ihtiyaç duymasına yol açar ve saniyedeki MSPS azaltır.
