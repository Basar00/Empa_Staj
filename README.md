# Empa_Staj
## 2026-07-21: Modüler Buton Okuma ve Event Yönetimi (Zor Görev)

Bu projede buton okuma işlemleri `main` dosyasından ayrılarak modüler hale getirilmiş (`button.c` ve `button.h`) ve aksiyonlar Event (Enum) tabanlı bir yapıya geçirilmiştir.

* **Debounce ve Eşik Değerleri:** Donanımsal parazitleri önlemek için sayaç tabanlı debounce uygulanmıştır. Kısa basış için anlık tepki sınırı, uzun basış için ise ~1000 ms eşik değeri kullanılmıştır.
* **Bellek Yönetimi (RAM/Flash):** Çalışma esnasında butonun anlık durumu ve basılı kalma sayacı gibi değişkenler (state) MCU'nun RAM'inde tutulurken, ana kod mantığı ve sabitler Flash bellekte çalışmaktadır.
