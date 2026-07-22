# Günlük Rapor — Gün 03

| Alan | Değer |
|------|-------|
| **Stajyer** | C — Başar Yıldırım |
| **Tarih** | 2026-07-22 |
| **Konu** | UART polling, komut parse, OK / ERR |

## Bugün ne yaptım?

- Buton kontrolünü EXTI interrupt ve falling edge tetiklemesiyle entegre ettim.

- Mechanical bounce durumunu software filtering ile hallettim.

- Butona her basıldığında animasyonun hız değerini 3 farklı kademe arasında değiştiren yapı kurdum.


GitHub Zor Görev Teslimi: [https://github.com/Basar00/Empa_Staj/tree/0973a06cca03af976d90c7a240120e0d3c826db5/Proje/2026-07-22]

**Kavramlar:**
- Non-blocking Architecture
- EXTI (External Interrupt)
- Falling Edge Triggering
- Software Debouncing
- Modular Programming

## Görev durumu

| Seviye | Yapıldı |
|--------|---------|
| Kolay | ☑ |
| Orta | ☑ |
| Zor | ☑ |

## Takıldığım yer

- Both edge modunda mechanical bounce nedeniyle oluşan false trigger'lar ve speed counter kalibrasyonu.

## Yarın

- Bugünün işi tam bittiği için önümüzdeki konulardan devam edeceğim.


## Teorik Sorular

1. **GPIO**
- Input modu, işlemcinin dış dünyayı dinlediği moddur. Örneğin butona basıldı mı diye pinin voltajını okuduğumuz durum.
- Output modu ise işlemcinin dışarıya komut verdiği moddur. LED'leri yakmak için pinlere 1 veya 0 gönderdiğimiz durum.


2. **Pull-up, Pull-down ve Floating**
- Pull-up pini boştayken zorla Hıgh'da tutar, Pull-down zorla LOW'da tutar. Floating de pin açıkta kalır.

- Floating Pinini havada bırakırsak çevredeki elektriksel sinyallerden etkilenip kafasına göre 1 veya 0 okur ve butonun kendi kendine rastgele basılıyormuş gibi algılatır.


3. **MCU, MPU ve SoC**
- MCU, içinde işlemcisi, RAM'i, pini her şeyi hazır olan minik bilgisayardır. Kullandığımız "A34G43x" gibi. 
- MPU beyin gibidir. Çlışması için yanına harici RAM/Hafıza takılması gerekir. 
- SoC ise bunların üstüne Wi-Fi, Bluetooth, ekran kartı vb. eklenmiş en dolu ve en karmaşık çiptir.


4.  **Global değişken, static değişken, local değişken, fonksiyon ve string sabitleri**
- Global ve static değişkenler kalıcı oldukları için RAM'in Data/BSS kısmında oturur. Döngü içindeki i gibi yerel (local) değişkenler anlık lazım olduğu için Stack bölgesinde açılıp işi bitince silinir.


5. **Polling ve Interrupt**
- Polling, sorugucudur. İşlemciye sürekli "Butona basıldı mı?" gibi sorular sordurup sistemi yormaktadır. 
- Interrupt ise habercidir. Buton gibi ne zaman basılacağı belli olmayan işlerde enerji tasarrufu ve sıfır gecikme için Interrupt tercih edilmelidir.


6. **Interrupt Service Routine (ISR)**
- ISR, donanımsal bir kesme sinyali geldiğinde işlemcinin o anki işini askıya alarak çalıştırdığı özel fonksiyondur. ISR'lar sistemin anlık akışını böldüğü için mümkün olduğunca kısa sürmelidir.
- Delay ile beklemek veya printf ile yavaş veri yazdırmak işlemcinin kilitlenmesine ve diğer önemli kesmelerin kaçırılmasına neden olur. Bu yüzden ISR içinde sadece flag güncellenmeli ve asıl işlemler main döngüsüne bırakılmalıdır.


7. **NVIC (Nested Vector Interrupt Controller)**
- NVIC: işlemciye gelen birden fazla kesmenin sırasını ve yönetimini sağlayan donanımsal birimdir. 
- Kesme önceliği (priority): aynı anda birden fazla kesme geldiğinde hangisinin önce işleneceğini belirler.
- İç içe kesme: düşük öncelikli bir kesme çalışırken daha acil bir kesme gelirse işlemcinin mevcut işi yarıda kesip acil olanı çalıştırabilmesi durumudur.


8. **Debounce**
- Bounce: Mekanik butonlar basıldığı anda metal kontakların titreşmesi nedeniyle kısa sürede ard arda sahte sinyaller üretilmesidir.
- Donanımsal çözüm - devreye RC filtre eklenir.
- Yazılımsal çözüm - kod içine küçük gecikmeler veya sayaçlar eklenir ve bu gürültüler yok sayılır.



9. **Neden Falling Edge Interrupt?**
- Pull-up direncine bağlı bir buton bırakıldığında HIGH, basıldığında LOW seviyesine geçer. 
- Falling Edge - Voltajın yüksekten alçăpa düştüğü bu anı en hızlı şekilde yakalamak için kullanılır. 
- Rising Edge - Parmağın butondan çekildiği anı  yakalamak gerektiğinde ise kullanılır.


10. **Neden volatile?**
- İşlemci hızlanmak için bazı değişkenleri geçici hafızada tutar ve RAM'e bakmaz. Arka planda kesme çalışıp bu değişkenin değerini değiştirdiğinde, işlemci eski değerle devam edebilir ve değişimi fark edemez. volatile, işlemciye her seferinde mutlaka RAM'deki güncel değere bakmasını söyler yoksa program bayrak değişimini göremez ve kilitlenir.