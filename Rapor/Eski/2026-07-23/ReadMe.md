# 2026-07-23 - Modüler LED ve Buton Projesi

- **`while(1)`**: `prv_user_code.c` içinde çalışmaktadır.
- **`for`**: Açılışta `Led_SelfTest()` fonksiyonunda LED'leri sırayla yakmak için kullanıldı.
- **`if / else`**: Buton basışları ve kısa/uzun basış modları bu bloklarla kontrol edildi.
- **`volatile`**: Gecikme döngülerinde derleyici optimizasyonunu önlemek için kullanıldı.
- **`Debounce`**: Salı gününden