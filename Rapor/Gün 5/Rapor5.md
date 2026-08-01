# Günlük Rapor — Gün 05

## Bugün ne yaptım?

- SysTick Timer ve donanımsal zamanlayıcı (Timer) birimlerinin yapılandırılması.
- PWM (Pulse Width Modulation) sinyali üretilerek LED parlaklığının kontrol edilmesi.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- PWM sinyalinin frekansı ile görev döngüsünün (Duty Cycle) zamanlayıcı bölücü (Prescaler) hesaplamaları.

## Teorik sorular

*1.* PWM (Pulse Width Modulation) nedir?
- Dijital bir sinyalin belirli bir frekansta lojik 1 ve lojik 0 kalma sürelerinin oranlanması ile ortalama bir analog gerilim seviyesi elde etme yöntemidir.

*2.* Duty Cycle (Görev Döngüsü) neyi ifade eder?
- Bir periyodik sinyalin aktif (lojik 1) kaldığı sürenin, toplam sinyal periyoduna yüzdesel oranıdır.

*3.* Prescaler (Ön Bölücü) nedir?
- Mikrodenetleyicinin ana saat sinyalini bölen ve zamanlayıcının daha düşük frekanslarda veya daha uzun periyotlarda saymasını sağlayan donanımsal bölücüdür.

*4.* SysTick Timer mikrodenetleyicilerde ne amaçla kullanılır?
- Genellikle gerçek zamanlı işletim sistemlerinde (RTOS) zaman dilimleme (time-slicing) için veya sistem genelinde hassas milisaniyelik gecikmeler üretmek için kullanılan standart ARM Cortex çekirdek zamanlayıcısıdır.

*5.* PWM frekansı neden LED sürme uygulamalarında önemlidir?
- Frekans insan gözünün algılama sınırının (yaklaşık 50-60 Hz) altında olursa LED'de titreme (flicker) görülür; bu yüzden genellikle 100 Hz ve üzerinde seçilir.