# Günlük Rapor — Gün 02

## Bugün ne yaptım?

- Dünden kalan kısımları tamamladım.

- MCU/MPU farkları, saat frekansları ve RAM/Flash yapısı gibi  teorik kısmını halledip uygulamaya geçtik. Butondaki "debounce"ları yazılımla nasıl filtreleyeceğimi öğrendim. 

- Her şeyi `main` içine yığmak yerine, kodları `.c` ve `.h` dosyalarına ayırarak daha temiz bir yapı kurduk.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- İlk aşamalarda uzun basış kontrolünü yaparken (`for`) döngüleri kullandığım için işlemci tıkandı ve buton tepkileri ile LED flaşları ağır çekim gibi yavaş çalıştı. 