# Günlük Rapor — Gün 01

| Alan | Değer |
|------|-------|
| **Stajyer** | C — Başar Yıldırım |
| **Tarih** | 2026-07-20 |
| **Konu** | Tiremo Cortex tanıtımı · ABOV ortam kurulumu · GPIO |

## Bugün ne yaptım?

- Dün yaptığımız projenin üstüne koyarak daha farklı ve kapsamlı olmasını sağladım. 

- Programın modlarını yönetmek için enum ile SLOW, FAST ve PAUSE durumları oluşturdum, ana döngüyü de switch-case yapısına bağladım.

- Karışıklığı önlemek için LED ve buton kısımlarını ayrı dosyalara ayırdım (led.c, button.c).

- Kısa basışta yön ve hız değişimi, uzun basışta ise sistemin durup ışıkların sönmesini ayarladım.


**Kavramlar**
- enum
- switch - case
- mod

## Görev durumu

| Seviye | Yapıldı |
|--------|---------|
| Kolay | ☑ |
| Orta | ☑ |
| Zor | ☑ |


## Zor Görev
https://github.com/Basar00/Empa_Staj/tree/4055e9c5b63e4b1bfdaf9b59d720273f363648ae/Proje/2026-07-24


## Takıldığım yer

- Pek bir sıkıntı yoktu bazı ledlerde gürültü, delay sorunu vardı sadece. Basit debounce sistemiyle çözüldü.

## C özeti
`for` → `Led_Init`, `Led_SelfTest` ve `Led_ChaseStep` içinde LED pin dizisini taramak ve gecikme üretmek için.

`while` → Sonsuz döngüsü ve butonun basılı kalma süresini saymak için.

`if` → Buton basış durumlarını ve yön/hız kontrol bayraklarını denetlemek için.

`switch` → `app_mode` değişkenine bakarak modların arasında geçiş yapmak için.

`const` → `CHASE` gibi sabit gecikme/hız değerlerini tutmak için.

`volatile` → Döngü tabanlı gecikmelerin derleyici optimizasyonuna takılmasını engellemek için.


### Debug UART Tablosu

| Alan | Değer |
|------|-------|
| Debug UART | UART10 |
| TX pin | PC15 |
| RX pin | PC14 |
| Baud rate | 115200 |
| Data / parity / stop | 8N1 |
| COM port (PC) | COM3 |


## Checklist

| # | Madde | Yapıldı |
|---|-------|---------|
| 1 | Şemadan UARTn bulundu | ☑ |
| 2 | TX / RX pinleri yazıldı | ☑ |
| 3 | Baud + 8N1 net | ☑ |
| 4 | Peripheral yapılandırıldı, build OK | ☑ |
| 5 | `Debug_Init` + `Debug_Print` yazıldı | ☑ |
| 6 | Tera Term’de çıktı görüldü | ☑ |
| 7 | Rapora tablo dolduruldu | ☑ |


## Yarın

- 
