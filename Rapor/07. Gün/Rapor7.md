# Günlük Rapor — Gün 07

## Bugün ne yaptım?

- UART üzerinden gelen verilerin kesme (Interrupt) yöntemiyle alınması (RX Interrupt).
- Gelen komutlara göre mikrodenetleyicinin GPIO durumlarının seri porttan yönetilmesi.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- Kesme alt programı (ISR) içerisinde uzun işlemler yapıldığında veri kaçırma problemleri yaşanması.

## Teorik sorular

*1.* ISR (Interrupt Service Routine - Kesme Servis Rutini) nedir?
- Donanımsal veya yazılımsal bir kesme gerçekleştiğinde işlemcinin normal akışını durdurup öncelikli olarak çalıştırdığı özel alt fonksiyondur.

*2.* ISR yazılırken nelere dikkat edilmelidir?
- ISR mümkün olduğunca kısa ve hızlı olmalı, içerisinde gecikme (delay) veya ağır matematiksel hesaplamalar/print işlemleri kullanılmamalıdır.

*3.* NVIC (Nested Vectored Interrupt Controller) nedir?
- ARM Cortex-M serisinde kesmelerin öncelik sıralamasını (priority) ve iç içe geçebilmesini (nesting) yöneten donanımsal kesme denetleyicisidir.

*4.* UART RX Overrun hatası (OVR) nedir?
- Alıcı tamponuna yeni bir veri geldiği halde önceki verinin işlemci tarafından okunmadan üzerine yazılması sonucu oluşan veri kaybı hatasıdır.

*5.* FIFO (First-In-First-Out) tampon mantığı ne sağlar?
- İlk giren verinin ilk çıkmasını sağlayarak seri verilerin geliş sırası bozulmadan kuyruklanmasını ve işlenmesini sağlar.