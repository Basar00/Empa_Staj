# Günlük Rapor — Gün 03

| Alan | Değer |
|------|-------|
| **Stajyer** | C — Başar Yıldırım |
| **Tarih** | 2026-07-23 |
| **Konu** | UART polling, komut parse, OK / ERR |

## Bugün ne yaptım?

- Açılışta 3 adet ledin sırayla yanıp sönmesini sağlayan self-test mekanizmasını yazdım.
- Buton okuma işlemine debounce ekleyerek mekanik titremeleri engellendi ve süre sayımıyla kısa/uzun basış ayrımı yaptım.
- Kısa basışta chase yönünü tersine çeviren, uzun basışta ise çalışma hızını değiştiren ve `if-else` ile entegre yaptım.  

**Kavramlar:**
- volatile 
- if-else, while-for
- switch
- const ve static const

## Görev durumu

| Seviye | Yapıldı |
|--------|---------|
| Kolay | ☑ |
| Orta | ☑ |
| Zor | ☑ |

## Zor Görev ##
https://github.com/Basar00/Empa_Staj/tree/8dd25fc9fe770cd0575f8104ad14f58b16cd6019/Proje/2026-07-23

## Takıldığım yer

- Bazı kütüphane ve delay sorunları.

## Yarın

- Önümüzdekilerden devam edeceğim.


## Teorik Sorular

1. # FOR #
- Led_Init(), Led_SelfTest(), volatile (gecikme döngüsü için) ve button.c (press duration kısmında) fonksiyonlarında kullandım. 
- 3 led vardı 13 - 14 - 15

2. # If #
- Buton algılama işlemi için-> butona basıldığında "basildi == true" ve while döngüsü içinde "basma_suresi" sayacını arttırarak basıl kalma süresini ayarlandım.

Mod-Yön
- Kısa basış istiyorsak (SHORT_PRESS) reverse==reverse! diyerek akışı terse çeviriyoruz.
- Uzun ise (LONG_PRESS) else if (event == LONG_PRESS)

"
if (event == SHORT_PRESS) {
    reverse = !reverse;
}
    else if (event == LONG_PRESS) {
        if (current_delay == Yavas_Chase) {
            current_delay = Hizli_Chase;
}   else {
         current_delay = Yavas_Chase;
}}"



3. # CONST #
-  const uint32_t Yavas_Chase = 1650;
   const uint32_t Hizli_Chase = 250;
   gibi kullanımda değişkenin değeri hiçbir zaman değişmez.(ROM da saklanır.)

- bool reverse = false;
uint8_t active_index = 0; 
gibi değişkenler ise RAM de tutulur. Bunlar anlık olarak güncellenir.

4. # Kesme/Debounce #
- Debounce seçtim daha pratik gözüktü.
