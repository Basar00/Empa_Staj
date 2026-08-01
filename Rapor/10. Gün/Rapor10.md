# Günlük Rapor — Gün 10

## Bugün ne yaptım?

- Mikrofon ADC sinyalinin UART üzerinden Stream moduyla PC tarafına aktarılması.
- Python kullanılarak zaman–genlik grafiğinin çizdirilmesi.
- 1 kHz sinüs test sinyali ile mikrofonun etrafındaki akustik salınımlarının  dalga formunda doğrulanması.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- örnekleme süresi uzun olduğunda Python grafiğinde veri kopmaları/ping hissi oluşması.

## Teorik sorular

*1.* Dün tek tek MIC = ... yazmak neden dalga şeklini göstermez?
- Tek bir sayısal değer sadece o milisaniyelik anlık genliği temsil eder. Ses zamanla değişen periyodik bir dalga olduğu için, zaman ekseninde art arda sıralanmış sürekli olmadan dalga formu çizilemez.

*2.* 1 kHz sinüs için teorik minimum örnekleme frekansı (Nyquist) nedir? Pratikte neden daha yüksek isteriz?
- Nyquist teoremi -  min fs > 2f => 2000 Hz
- Sinüs eğrisini pürüzsüz görebilmek ve peak/dip noktalarını kaçırmamak için en az 8-10 kHz örnekleme hızı tercih edilir.

*3.* Örnekleme çok yavaş olursa grafikte ne görürsün?
- Aliasing olur ve 1 kHz sinüs dalgası çok daha düşük frekanslı, kırık ve rastgele hatalı bir dalga gibi çizilir.

*4.* Mikrofon sessizken grafik neden sıfırda değil, orta bir seviyede (bias) durur?
- Ses sinyalleri pozitif ve negatif gerilimler arasında salınır.  Negatif voltaj okunmayacağı için mikrofon devresi sinyali referans voltajının tam ortasına offsetler.

*5.* UART baud rate düşük, örnek hızı yüksek olursa ne olur?
-  Hattın taşıyabileceğinden daha hızlı veri basacağı için Buffer Overflow olur ve grafikte donmalar/atlamalar yaşanır.

*6.* MIC=2048 ile sadece 2048 satırı arasında Python için fark var mı? Hangisini tercih edersin, neden?
- MIC=2048 yazımında Python'un parsing yapması gerekir. Sadece 2048 gönderilirse direkt tam sayıya çevrilir. 
- Hem UART bant genişliğini korumak hem de işlemci yükünü azaltmak için sadece sayı tercih edilir.

*7.* Peak-to-peak (tepe–tepe) ne demektir? Ses seviyesi ile ilişkisi nedir?
- Peak noktası ile en dip noktası arasındaki toplam genlik farkıdır. 
- Ses şiddeti arttıkça peak to peak genlik değeri büyür.

*8.* Aynı 1 kHz tonu daha uzaktan çalarsan grafikte ne değişir, ne değişmez?
- Peak to peak değeri azalır. Fakat sinyalin frekansı ve orta DC bias çizgisi sabit kalır.

*9.* Dijital mikrofon (PDM/I2S) kullansaydık bugünkü UART+ADC grafiği aynı şekilde kurulur muydu?
- Tam olarak kurulamazdı. dijital mikrofonlar analog voltaj yerine doğrudan sayısal veri dizisi üretir. 
- ADC çevrimine gerek kalmazdı ancak veriyi PC'ye aktarıp streami benzer olurdu.

*10.* Canlı grafikte gördüğün “sinüs” neden laboratuvar osiloskopundaki kadar temiz olmayabilir? (en az 2 sebep)
- Yazılımsal döngü gecikmeleri ve UART iletim darboğazı nedeniyle osiloskoplar gibi MHz seviyesinde tam sabit zamanlı örnekleme yapılamaması.
- Reverb, noise ve parazitlerin analog sinyale binmesi.