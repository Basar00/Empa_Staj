# Günlük Rapor — Gün 12

## Bugün ne yaptım?
- **Sensirion SHT4x Kütüphane Entegrasyonu:** Sensirion'un resmi `embedded-i2c-sht4x` C kütüphanesi projeye dahil edildi.

- **ABOV HAL Köprüsünün Kurulması (`sensirion_i2c_hal.c`):** Kütüphanenin donanımdan bağımsız çalışmasını sağlayan soyut HAL katmanı fonksiyonları (`init`, `write`, `read`, `sleep_usec`), ABOV mikrodentleyicisinin `I2C_ID_2` haberleşme sürücüleriyle entegre edildi.

- **Sıcaklık ve Nem Ölçüm:** SHT40 sensörü `0x44` üzerinden Hassasiyet `0xFD` ölçümü gerçekleştirildi.

- **Bonus — Ledli Sıcaklık Alarmı:** Ortam sıcaklığının **32.00 °C** sınırını aşması durumunda, kart üzerindeki 14 LED'in fonksiyonu tetiklenerek ritmik yanıp sönmesi sağlandı sıcaklık normale döndüğünde led kapanma sistemi kuruldu.

## Görev durumu

Her şey tam yapıldı. (+Bonuslar da yapıldı.)

## Takıldığım yer

- **`multiple definition`:** bazı derleme ve çakışma sorunları yaşadım.

- **`ERR:SHT (1)` Boş Okuma Hatası:** I2C haberleşmesi düzgün çalışmasına rağmen kütüphanenin sürekli `1` dönmesi.
 `sht4x_init(0x44);` fonksiyonunun çağrılmadığı, bu nedenle kütüphanenin `0x00` adresinden boş baytlar okuyup paket doğrulamasını geçememesi. Adres tanımı ekleyerek sorun çözüldü.

- `printf` sorunları `My_Debug_Print` ile çözüldü.


## Teorik sorular
*1* SHT40’ın tipik 7-bit I2C adresi nedir? Write frame’de bus’a giden ilk byte kabaca ne olur?
- **7-bit Adres:** `0x44`.
- **Write Frame:** Master adresi sola 1 bit kaydırıp en sağdaki R/W bitini `0` yaptığı için I2C bus üzerinde `0x88` olarak görünür.

*2* SHT40’ta klasik WHO_AM_I register yerine ne kullanılır? Dünkü LIS/MPU yaklaşımından farkı nedir?
- SHT40, Register Mapped hafıza yapısı yerine State Machine ile çalışır. Sabit bir kimlik registerını okumak yerine cihaza `0x89` komutu gönderilir kimlik bilgisi hesaplanılıp geriye yanıt olarak gönderir.

*3* Bir ölçüm cevabında gelen 6 byte’ın sırası nedir? CRC neden vardır?
- `[T_MSB] [T_LSB] [T_CRC] [RH_MSB] [RH_LSB] [RH_CRC]`

- I2C hatlarındaki parazit ve gürültüler nedeniyle bitlerin iletim sırasında bozulup bozulmadığını matematiksel olarak doğrulamaktır. Hatalı paketler veri bütünlüğünü korumak amacıyla atılır.

*4* Ölçüm komutundan hemen sonra beklemeden okursan ne olur? Sleep / delay’in rolü nedir?
- `0xFD` gittiğinde sensör içindeki ADC ve sinyal işleme bloğu ortamdan fiziksel veri toplamaya başlar. Beklemeden okuma yapılırsa sensör meşgul olduğu için I2C hattına `NACK` verir veya eski verileri göndererek CRC hatasına neden olur.

*5* Sensirion kütüphanesinde neden tüm projeyi baştan yazmak yerine sadece HAL katmanını değiştiriyoruz?
- Sensörün komut seti, dönüşüm formülleri ve CRC algoritması her işlemicide aynıdır. Kütüphaneyi donanıma bağımlı haberleşme fonksiyonlarından soyutlamak, aynı sürücünün STM32, ABOV, ESP32 veya Linux üzerinde tek satır sensör kodu değişmeden çalışmasını sağlar.

*6* `HAL_I2C_IsDeviceReady()` başarılı ama `sht4x_measure` sürekli hata veriyorsa ilk bakacağın 3 şey nedir?
- 1. `sht4x_init(0x44)` Çağrıldı mı?
- 2. Bekleme Süresi (`sleep_usec`) Yeterli mi?
- 3. HAL Köprüsü Dönüş Değerleri:

*7* Ham tick ile °C / %RH arasındaki ilişkiyi kim tanımlar (datasheet mi, senin uydurman mı)?
- **Sensirion** tanımlar. Kalibrasyon ve fonksiyonlar üretici tarafından belirlenmiştir.

*8* Pull-up olmasa dün scanner ve bugün SHT40 ölçümü neden ikisi birden bozulur? 
- I2C pinleri donanımsal olarak **Open-Drain** yapısındadır. entegreler hattı sadece `LOW` seviyesine çekebilir, aktif olarak `HIGH` veremez. 
- Pull-up dirençleri olmazsa SDA ve SCL hatları boşta `HIGH` seviyesine yükselemez. start/stop koşulu üretmez.