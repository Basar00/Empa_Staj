# Günlük Rapor — Gün 03

## Bugün ne yaptım?

- GPIO portlarının Çıkış (Output) modunda yapılandırılması ve LedBlink1 projesinin oluşturulması.
- Bit düzeyinde lojik operatörler kullanılarak LED yakıp söndürme uygulaması.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- LED anahtarlama hızının mikrodenetleyici saat frekansına göre gecikme (delay) döngüsüyle dengelenmesi.

## Teorik sorular

*1.* GPIO (General Purpose Input/Output) nedir?
- Mikrodenetleyicinin dış dünya ile dijital sinyaller üzerinden haberleşmesini, veri alıp vermesini sağlayan genel amaçlı pinlerdir.

*2.* Push-Pull ile Open-Drain çıkış modları arasındaki fark nedir?
- Push-Pull modunda pin hem lojik 1 (VDD) hem de lojik 0 (GND) seviyesine aktif olarak çekilir.
- Open-Drain modunda pin sadece lojik 0 (GND) seviyesine çekilebilir, lojik 1 seviyesi için harici bir Pull-up direnci gerekir.

*3.* Pull-up ve Pull-down dirençleri neden kullanılır?
- Giriş pininin boşta (floating) kaldığı durumlarda elektriksel gürültülerden etkilenmemesi ve sabit bir lojik seviyede (0 veya 1) kalması için kullanılır.

*4.* Clock Gating (Saat sinyali tetikleme) kavramı nedir?
- Enerji tasarrufu sağlamak amacıyla, kullanılmayan çevresel birimlerin (örneğin GPIO portlarının) saat sinyallerinin kapatılmasıdır.

*5.* Bir LED'i doğrudan mikrodenetleyici piniyle sürerken neden seri direnç bağlarız?
- Pin üzerinden geçen akımı sınırlayarak hem LED'in yanmasını hem de MCU portunun aşırı akımdan zarar görmesini engellemek için.