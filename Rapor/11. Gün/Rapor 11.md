# Günlük Rapor — Gün 11

## Bugün ne yaptım?

- Kartın üzerindeki I2C kanal 2 (PB6 ve PB7) pinlerinin yapılandırması. I2C hattının kilitlenmesini önlemek için pinlerin Open-Drain + Pull-up olarak ayarlanması.
- `0x08` ile `0x77` arasındaki adreslerin taranarak hattaki aktif sensörleri saptanması.
- SHT40 sıcaklık ve nem sensörünün `0x44` olan donanım adresi I2C tarayıcı ile tespit edildi ve hattın düzgün çalıştığı doğrulandı.
- SHT40 sensörü register haritalı değil komut tabanlı çalıştığı için `0x89` komutu ile I2C haberleşmesi kuruldu.


## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- `HAL_I2C_Transmit()` fonksiyonunun boş parametre (`NULL, 0`) yerine `dummy` bayt istemesi ve NACK dönen boş adreslerde sonsuz döngüye girerek hattı kilitlemesi sorunuyla karşılaşıldı. 

- Seri numarası okumadan hemen sonra okuma yapıldığında `0x00000000` dönmesi sorunu, datasheet'te belirtilen 1 milisaniyelik EEPROM hazırlık süresi göz önüne alınıp araya delay eklendi.

## GÖREV 2: TABLO

| Sensör / Donanım | Tipik Slave Addr (7-Bit) | Komut / Reg Adresi | Okunan Değer (UART Çıktısı) | Beklenen Değer (Datasheet) |
|---|---|---|---|---|
| SHT40 | 0x44 | 0x89 | 0x0B994324 | özel 32-bit ID |
| MPU6050 | 0x68 | 0x75 | - | 0x68 |


## GÖREV 3: Teorik sorular

*1.* I2C nedir?
- Inter-Integrated Circuit, mikrodenetleyiciler ile sensörler ve çevre birimleri arasında kısa mesafeli haberleşme sağlayan senkron, yarı-çift yönlü ve adres tabanlı bir seri haberleşme protokolüdür.

*2.* UART ve SPI’dan farkı nedir?
- UART asenkondur ve sadece 1-to-1 haberleşir
- I2C senkrondur ve tek hatta çoklu multi-slave destekler. 
- SPI 4 veya daha fazla pin gerektirirken, I2C sadece 2 pinle çalışarak pin tasarrufu sağlar.

*3.* SDA ve SCL ne işe yarar?
- SDA (Serial Data Line): Cihazlar arasındaki veri alışverişini taşıyan çift yönlü veri hattıdır.
- SCL (Serial Clock Line): Master cihaz tarafından üretilen ve veri iletiminin zamanlamasını senkronize eden saat sinyali hattıdır.

*4.* Master ve Slave nedir?
- Master:  I2C hattında haberleşmeyi başlatan, SCL saat sinyalini üreten ve haberleşmeyi sonlandıran kontrolcü cihazdır. 
- Slave: Master tarafından kendi adresi çağrıldığında komuta cevap veren ve veri gönderen/alan çevre birimidir.

*5.* 7-bit ve 10-bit adres nedir?
- 7-bit: Standart olan ve 128 cihaza kadar destek veren yapıdır. En sağa Read/Write biti eklenerek 8-bit paket oluşturulur.
- 10-bit adresleme: Adres çakışmalarını önlemek ve daha fazla cihaz bağlayabilmek için geliştirilen, 1024 cihaz kapasiteli genişletilmiş adresleme yapısıdır.

*6.* ACK / NACK nedir?
- ACK: Her 8 bitlik veri iletiminden sonra, alıcının veriyi başarılı bir şekilde aldığını bildirmek için SDA hattını LOW seviyesine çekmesidir. 
- NACK: Alıcının adresi tanımadığını, meşgul olduğunu veya veri paketinin sonuna gelindiğini belirtmek için SDA hattını HIGH bırakmasıdır (1). 

*7.* START ve STOP koşulları nasıl oluşur?
- START: SCL hattı HIGH iken, SDA hattının HIGH'dan LOW'a geçirilmesiyle oluşur ve haberleşmenin başladığını belirtir. 
- STOP: SCL hattı HIGH iken, SDA hattının LOW'dan HIGH'a geçirilmesiyle oluşur ve haberleşmeyi sonlandırır ve hattı boşa çıkarır.

*8.* Clock Stretching nedir?
- Bir Slave cihazın master'dan gelen veriyi işlemekte gecikmesi veya veri hazırlaması gerektiğinde, master'ı bekletmek amacıyla SCL hattını donanımsal olarak LOW seviyesinde zorla tutmasıdır. 
- Master, SCL hattı tekrar HIGH olana kadar saat sinyali üretmeyi durdurur ve bekler.

*9.* Pull-up direnç neden kullanılır?
- I2C pinleri donanımsal olarak Open-Drain mantığıyla çalışır yani çipler hattı sadece LOW (0V) seviyesine çekebilir, aktif olarak HIGH veremez. Bu nedenle SDA ve SCL hatlarının boşta iken HIGH seviyesinde sabit kalabilmesi ve kısa devre olmadan sinyal iletebilmesi için VDD hattına bağlı Pull-up dirençleri zorunludur.