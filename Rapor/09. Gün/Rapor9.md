# Günlük Rapor — Gün 09

## Bugün ne yaptım?

- ABOV mikrodentleyicisinde 12-bit ADC biriminin Single/Sequence modda yapılandırılması.
- AN0 pinine bağlı mikrofon modülünün çıkış voltajının okunması ve Vadc dönüştürülerek UART üzerinden basılması.
- Ortam ses seviyesine göre bit manipülasyonu ile STATUS register yönetimi ve Peak alarmı tetiklenmesi.

## Görev durumu

- Bonus görevler harici tam yapıldı.

## Takıldığım yer

- İlk başta sinyali sabit aldım ve sonrasında da çok dağınık aldım. Bunu sinyal aralığının hassasiyetiyle oynarak çözdüm.

## Teorik sorular

*1.* ADC'nin görevi nedir? Analog sinyal neden doğrudan mikrodenetleyici tarafından işlenemez?
- Sürekli değişen analog voltaj sinyallerini işlemcinin anlayacağı dijital sayılara çevirir. 
- Sadece 0 ve 1 mantığıyla çalıştığı için doğrudan işleyemez.

*2.* Analog mikrofon çıkışı neden ADC girişine bağlanır?
- Mikrofon havada oluşan ses dalgalarını analog bir voltaj sinyaline dönüştürür. Bu voltajı işlemcide sayısal veri olarak okuyabilmek için ADC pini kullanılır.

*3.* 12 bit ADC kaç farklı dijital değer üretebilir?
- 2^12 = 4096 farklı değer üretebilir.

*4.* Vref = 3.3V ve ADC çözünürlüğü 12 bit ise 1 ADC adımı kaç mV değerindedir?
- Vref/2^n => 3.300mV/4096 = 0,81mv

*5.* ADC değeri 2048 olan bir sinyalin yaklaşık gerilimi kaç volttur?
- 2048.Vref/2^n = 1,65V

*6.* Mikrofon sessizken ve ses varken ADC değerleri neden farklı olur?
- Sessizken sadece devrenin orta bias voltajı 1.65V. 
- Ses oluştuğunda ses dalgası bu bias çizgisinin üstüne ve altına salınım yaptığı için ADC değerleri sürekli değişir.

*7.* Sampling (örnekleme) nedir? ADC için neden önemlidir?
- Sürekli olan analog sinyalden belirli zaman aralıklarında anlık numune (değer) alma işlemidir. Sinyaldeki değişimi ve dalga şeklini doğru yakalayabilmek için önemlidir.

*8.* Sampling frekansı düşük olursa ses sinyalinde ne gibi problemler oluşabilir?
- Aliasing oluşur. Sesin ani piki kaçabilir, yüksek frekanslı sesler grafikte yanlış ve bozuk şekilde görünür.

*9.* Analog mikrofon yerine dijital mikrofon kullanılırsa ADC'ye ihtiyaç olur mu? Açıklayınız.
- Hayır olmaz. Dijital mikrofonların içinde kendi dönüştürücüsü bulunur ve veriyi dijital protokollerle doğrudan işlemciye aktarır.

*10.* ADC kanalını yanlış seçerseniz sistemde nasıl bir problem oluşur?
- İşlemci mikrofonun bağlı olan pin yerine başka bir pindeki rastgele voltajı okur, sistemde sürekli yanlış veriler görünür.