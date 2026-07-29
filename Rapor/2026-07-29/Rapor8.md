# Günlük Rapor — Gün 08

| Alan | Değer |
|------|-------|
| **Stajyer** | C — Başar Yıldırım |
| **Tarih** | 2026-07-29 |
| **Konu** | ADC ile batarya mV, eşik, LED |

## Bugün ne yaptım?

- ABOV üzerinde UART seri haberleşme altyapısı kullanılarak Bit Düzeyinde Register Manipülasyonu uygulaması.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- veri aktarımında bazI parazitler/kararsızlıklar yaşandı
- printf problemleri


## Teorik sorular

*1.* Bit nedir? Byte ile arasındaki fark nedir?
- Bit - En küçük veri birimidir. 
- her bir byte 8 bittir. 


*2.* Binary sayı sistemi neden mikrodenetleyicilerde önemlidir?
- Binary ikili mantıksal durumlarda çok önemlidir. GPIO pin durumları tamemen buna dayanır. 0 ve 1 değeri verir.


*3.* Aşağıdaki işlemin sonucu nedir?

uint8_t value = 0x00;

value |= (1 << 3);

- Hexa: 0x08
- Binary: 0b00001000


*4.* Aşağıdaki kod ne yapar?

value &= ~(1 << 5);

- 5 . biti temizler.


*5.* Aşağıdaki işlemin sonucu nedir?

uint8_t value = 0x08;

value ^= (1 << 3);

- 3 . biti reverselenir, sonuç 0 olur 


*6.* Maskeleme (bit masking) nedir? Neden kullanılır?
- Bit değiştirmek veya seçmek için kullanılır.  


*7.* Bir register içerisindeki sadece 4. biti değiştirmek istiyorsunuz. Diğer bitlerin değişmemesi için hangi yöntem kullanılır?
- maskeleme ve lojik operatörler yöntemi kullanılır:
- set(1) için -> reg|= (1 << 4);
- clear(0) için -> reg&= ~(1 << 4);
- toggle için -> reg^=(1 << 4);


*8.* Aşağıdaki değerin decimal karşılığını bulun:

0b10101010

- 2^7 + 2^5 + 2^3 + 2^1 = 170


*9.* STM32 gibi mikrodenetleyicilerde GPIO kontrolünde neden bit işlemleri kullanılır?
- Hız, performans - tek bir clock cycle da donanımsal düzeyde çalışır.
- Hassasiyet - pin durumu değişirken


*10.* Aşağıdaki kodun amacı nedir?

#define LED_PIN 5

GPIOA->ODR |= (1 << LED_PIN);
Açıklayınız.

- STM32 işlemcisinde GPIOA portuna bağlı olan 5. pine 3.3v vererek bu pine bağlı LED'i yakar. ODR portun çıkış verisini tutar. |= (OR) işlemi sayesinde portun diğer pinlerindeki mevcut çıkış durumları korunarak sadece 5. pin mantıksal 1 yapılır.
