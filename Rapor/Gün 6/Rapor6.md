# Günlük Rapor — Gün 06

## Bugün ne yaptım?

- UART (Universal Asynchronous Receiver-Transmitter) seri haberleşme protokülünün konfigüre edilmesi.
- My_Debug_Print altyapısı kurularak PC terminali (Tera Term / VS Code) üzerinden 115200 Baudrate hızında hata ayıklama (debug) çıktısı alınması.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- Terminal ekranında karakterlerin bozuk görünmesi (Baudrate ve clock eşleşme problemi).

## Teorik sorular

*1.* UART protokolü neden "Asenkron" olarak adlandırılır?
- Alıcı ve verici arasında ortak bir saat (clock) hattı bulunmadığından; haberleşmenin senkronizasyonu önceden belirlenmiş baudrate hızı, start ve stop bitleri ile sağlandığı için.

*2.* Baudrate nedir? 115200 Baudrate ne anlama gelir?
- Saniyede aktarılan sembol (bit) sayısını ifade eder. 115200 Baudrate, saniyede 115.200 bit verinin hat üzerinden taşındığını gösterir.

*3.* UART çerçevesindeki (Frame) Parity (Eşlik) biti ne işe yarar?
- İletilen veride tek bitlik iletim hatası olup olmadığını basit bir şekilde kontrol etmek (hata tespiti) için kullanılır.

*4.* UART haberleşmesinde TX ve RX hatları nasıl bağlanmalıdır?
- Çapraz bağlanmalıdır; birinci cihazın TX (Verici) hattı, ikinci cihazın RX (Alıcı) hattına bağlanır.

*5.* Seri haberleşmede Buffer (Tampon Bellek) neden önemlidir?
- İşlemci diğer görevlerle meşgulken gelen verilerin kaybolmaması ve gönderilecek verilerin sırayla hatta akıtılması için geçici hafıza alanı sağlar.