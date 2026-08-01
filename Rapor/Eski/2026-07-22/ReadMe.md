3 adet LED ile non-blocking kayan ışık (chase) animasyonu oluşturdum. Butona her basıldığında animasyonun hızını 3 farklı kademe (Medium ➔ Fast ➔ Slow) arasında değiştiren modüler bir yapı (led.c/h, button.c/h) kurdum.

Kenar Seçimi: Pull-up buton basıldığında lojik 0'a düştüğü için Falling Edge kullanıldı.

Debounce: Mekanik yay titreşimlerini (bounce) engellemek için ISR içerisinde bayrak temizlendikten sonra kısa bir software delay ve ek kontrol mekanizması kullanıldı.