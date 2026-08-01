# Günlük Rapor — Gün 05

## Bugün ne yaptım?

- Dün yaptığımız projenin üstüne koyarak daha farklı ve kapsamlı olmasını sağladım. 

- Programın modlarını yönetmek için enum ile SLOW, FAST ve PAUSE durumları oluşturdum, ana döngüyü de switch-case yapısına bağladım.

- Karışıklığı önlemek için LED ve buton kısımlarını ayrı dosyalara ayırdım (led.c, button.c).

- Kısa basışta yön ve hız değişimi, uzun basışta ise sistemin durup ışıkların sönmesini ayarladım.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- Pek bir sıkıntı yaşamdım. Bazı ledlerde gürültü, delay sorunu vardı sadece. Basit debounce sistemiyle çözüldü.


## C özeti
`for` → `Led_Init`, `Led_SelfTest` ve `Led_ChaseStep` içinde LED pin dizisini taramak ve gecikme üretmek için.

`while` → Sonsuz döngüsü ve butonun basılı kalma süresini saymak için.

`if` → Buton basış durumlarını ve yön/hız kontrol bayraklarını denetlemek için.

`switch` → `app_mode` değişkenine bakarak modların arasında geçiş yapmak için.

`const` → `CHASE` gibi sabit gecikme/hız değerlerini tutmak için.

`volatile` → Döngü tabanlı gecikmelerin derleyici optimizasyonuna takılmasını engellemek için.