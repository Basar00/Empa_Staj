# Günlük Rapor — Gün 02

## Bugün ne yaptım?

- ABOV AUDK32_A34xxxx serisi mikrodenetleyici mimarisinin veri kitapçığının (datasheet) incelenmesi.
- Eclipse / Keil tabanlı IDE geliştirme ortamının kurulması ve ilk boş projenin derlenmesi.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- CMSIS ve HAL kütüphanesi dizin yollarının (include paths) IDE derleyici ayarlarına tanıtılması.

## Teorik sorular

*1.* CMSIS (Cortex Microcontroller Software Interface Standard) nedir?
- ARM Cortex-M işlemci çekirdekleri ile donanım katmanı arasında standart bir yazılım arayüzü sağlayan donanımdan bağımsız kütüphanedir.

*2.* HAL (Hardware Abstraction Layer) kütüphanesinin kullanım amacı nedir?
- Donanım register'larına doğrudan müdahale etmek yerine, alt seviye donanım karmaşasını gizleyerek daha okunabilir ve taşınabilir fonksiyonlarla kod geliştirmeyi sağlar.

*3.* Bağlayıcı (Linker Script / `.ld` veya `.sct` dosyası) ne işe yarar?
- Derlenen kodun ve değişkenlerin mikrodenetleyicinin bellek haritasında (Flash, SRAM) hangi adres aralıklarına yerleştirileceğini belirler.

*4.* volatile anahtar kelimesi C dilinde neden kullanılır?
- Değişkenin değerinin donanım veya kesmeler (interrupt) tarafından derleyicinin haberi olmadan değişebileceğini belirtir, derleyicinin o değişken üzerinde optimizasyon yapmasını engeller.

*5.* Cross-compiler (Çapraz Derleyici) nedir?
- Bir mimaride (örneğin x86_64 PC) çalışıp, farklı bir hedef mimari (örneğin ARM Cortex-M4) için çalıştırılabilir makine kodu üreten derleyicidir.