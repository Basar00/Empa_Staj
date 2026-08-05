# Günlük Rapor — Gün 13

## Bugün ne yaptım?
- **LIS2DE12 İvmeölçer Entegrasyonu:** I2C kullanılarak LIS2DE12TR ivmeölçer sensöründen X, Y ve Z eksen verilerinin okunması.

- **Adres Tespiti ve Konfigürasyon:** Kart üzerindeki pin pull-up durumuna göre doğru I2C adresi tespiti.

- **Shake Algılama:** Okunan ham eksen değerlerinin mutlak değerleri karşılaştırılarak anlık yön tespiti ve ivme değişim farkları üzerinden sarsıntı algılama algoritması kuruldu.

## Görev durumu

- Adres uyumsuzlukları ve register okurkenki kilitlenmeler nedeniyle kod tam anlamıyla çalıştırılamadı, görev eksik kaldı.

## Takıldığım yer

* **I2C Adres Uyuşmazlığı:** Datasheet üzerinde belirtilen standart `0x18` adresi yerine kart üzerindeki donanımsal pull-up bağlantısı yüzünden adresin `0x19` olması ilk başta cihazın bulunamamasına neden oldu.
* **Register Okuma Sıralaması:** receive kombinasyonlarında hatanın kilitlenmesi.

## Teorik sorular

*1* İvmeölçer ne ölçer? Kart düz ve sabitken neden bir eksen ≈ ±1 g civarında görünür?
- İvmeölçer, cisme binen eylemsizlik kuvvetlerini ölçer. 
- Kart düz ve sabitken bile yerçekimi kuvveti 1g sensörün z ekseni üzerinde sürekli bir ivme etkisi yarattığı için o eksen ±1 g civarında okunur.

*2* LIS2DE12’nin tipik 7-bit I2C adresleri nelerdir? SA0 / SDO neden iki adres üretir?
- Tipik 7-bit adresler `0x18` veya `0x19`'dur. 
- SA0 (SDO) pini, I2C adresini LSB belirler. bu pinin lojik yüksek veya düşük çekilmesi iki farklı adres üretmesini sağlar.

*3* WHO_AM_I register’ı ne işe yarar? Beklenen değer nedir?
- Entegrenin çip modelini doğrulayan bir register'dır.
- Beklenen değer `0x33`'tür.

*4* Power-up sonrası sadece OUT_X okumak neden çoğu zaman yetmez? CTRL / ODR’nin rolü nedir?
- Enerji verildiğinde sensör varsayılan olarak power-down modunda başlar. `CTRL` register'ı ve ODR ayarları yapılmadan iç clock ve ADC devreleri çalışmayacağı için sürekli `0` okunur.

*5* OUT_* değerini uint8_t yerine int8_t olarak yorumlamak neden önemli?
- İvmeölçer verileri hem pozitif hem negatif yönlü ivmeleri belirtir. Bu yüzden veriler ikiye tümleyen işaretli formatta yorumlanır.

*6* Full-scale ±2 g ile ±16 g arasında pratikte ne fark eder?
- ±2 g seçildiğinde resolution çok yüksek olur ancak düşük ivme sınırlarında bile saturationa ulaşır. ±16 g ise yüksek hızlı veya şiddetli shakeleri ölçmeye yarar ancak resolution azalır.

*7* Aynı I2C bus’ta SHT40 (0x44) ve LIS2DE12 (0x18) birlikte durabilir mi? Neden?
- Evet, durabilir. İki cihazın I2C adresleri tamamen farklıdır ve bu sayede Master aynı bus üzerinden adres belirterek her iki cihazla çakışmadan haberleşebilir.

*8* STATUS register’daki “data ready” biti olmasa sürekli okursan ne olur? (kısa düşün)
- Sensör yeni veri üretmeden eski veriyi tekrar okuyabilir.