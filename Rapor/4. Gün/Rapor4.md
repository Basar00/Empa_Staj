# Günlük Rapor — Gün 04

## Bugün ne yaptım?

- GPIO pinlerinin Giriş (Input) modunda ayarlanması ve harici buton durumunun okunması.
- Mekanik buton sıçramalarının (Contact Bounce) yazılımsal Debounce algoritması ile filtrelenmesi.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- Butona basıldığında oluşan parazit sinyallerin yanlış veya birden fazla tetikleme üretmesi.

## Teorik sorular

*1.* Contact Bounce (Buton Sıçraması) nedir?
- Mekanik butonlara basıldığında veya bırakıldığında kontakların milisaniyeler içinde defalarca açılıp kapanması sonucu oluşan pasif sinyal dalgalanmasıdır.

*2.* Debounce işlemi yazılımsal olarak nasıl gerçekleştirilir?
- İlk sinyal değişiminden sonra buton durumunu doğrulamak için kısa bir bekleme süresi (örneğin 10-20 ms) verilir ve pin durumu tekrar okunur.

*3.* Polling (Sürekli Sorgulama) yöntemi ile Interrupt (Kesme) yönteminin farkı nedir?
- Polling yönteminde işlemci döngü içerisinde sürekli pinin durumunu kontrol eder, CPU zamanı harcar.
- Interrupt yönteminde ise işlemci normal işine devam eder; donanımsal bir olay (örneğin buton basımı) gerçekleştiğinde kesme tetiklenir ve alt program çalıştırılır.

*4.* Edge-triggered (Kenar Tetiklemeli) kesme ne demektir?
- Sinyalin seviyesinde (0 veya 1) değil, sadece seviye geçiş anlarında (yükselen kenar / düşen kenar) kesme üretilmesidir.

*5.* Schmitt Trigger giriş yapısı ne işe yarar?
- Gürültülü veya yavaş değişen analog/dijital sinyallerde alt ve üst eşik voltaj değerleri (histerezis) oluşturarak net ve kararlı bir dijital çıkış elde edilmesini sağlar.