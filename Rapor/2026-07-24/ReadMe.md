### C ile mini proje

### 1. Hafta tablosu

| Gün | Yapılan İş |
|-----|-------------------|
| Pazartesi | `Led_Init`, GPIO output |
| Salı | `DEBOUNCE_MS`, butona basış süreleri |
| Çarşamba | `button_flag`, ISR |
| Perşembe | `for` self-test, `Chase_Step` |
| Cuma | `AppMode_t`, `switch - case`, enum yapısı  |


## C özeti
`for` → `Led_Init`, `Led_SelfTest` ve `Led_ChaseStep` içinde LED pin dizisini taramak ve gecikme üretmek için.

`while` → Sonsuz döngüsü ve butonun basılı kalma süresini saymak için.

`if` → Buton basış durumlarını ve yön/hız kontrol bayraklarını denetlemek için.

`switch` → `app_mode` değişkenine bakarak modların arasında geçiş yapmak için.

`const` → `CHASE` gibi sabit gecikme/hız değerlerini tutmak için.

`volatile` → Döngü tabanlı gecikmelerin derleyici optimizasyonuna takılmasını engellemek için.
