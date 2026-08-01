# Günlük Rapor — Gün 01

## Bugün ne yaptım?

- Empa Electronics Ar-Ge Gömülü Sistemler departmanı oryantasyonu ve laboratuvar iş güvenliği süreçlerinin tamamlanması.
- Gömülü sistemler geliştirme ortamının incelenmesi ve mikrodenetleyici ailesine genel bakış.

## Görev durumu

Her şey tam yapıldı.

## Takıldığım yer

- Departman sunucularına ve teknik döküman ağlarına ilk erişim yetkilerinin yapılandırılması.

## Teorik sorular

*1.* Gömülü sistem (Embedded System) nedir? Genel amaçlı bilgisayarlardan farkı nedir?
- Gömülü sistemler, belirli bir işlevi yerine getirmek üzere donanım ve yazılımın bütünleştiği özel amaçlı sistemlerdir.
- Genel amaçlı bilgisayarlar her türlü yazılımı çalıştırabilirken, gömülü sistemler gerçek zamanlı (real-time) kısıtlara, düşük güç tüketimine ve yüksek kararlılığa odaklanır.

*2.* Mikroişlemci (MPU) ile Mikrodenetleyici (MCU) arasındaki temel fark nedir?
- MPU sadece merkezi işlem birimini (CPU) içerir; RAM, ROM ve çevre birimleri harici olarak bağlanır.
- MCU ise CPU, RAM, Flash bellek ve çevresel arabirimlerin (GPIO, ADC, UART vb.) tek bir yonga üzerinde toplandığı entegredir.

*3.* RISC mimarisinin temel avantajı nedir?
- Komut setinin sade ve azaltılmış olması sayesinde komutlar genellikle tek saat çevriminde (single clock cycle) çalışır, bu da enerji verimliliği ve performans sağlar.

*4.* Derleyici (Compiler) ile Derleme Zinciri (Toolchain) ne anlama gelir?
- Derleyici, yazılan yüksek seviyeli C/C++ kodunu makine diline çeviren yazılımdır.
- Toolchain ise derleyici, bağlayıcı (linker), kütüphaneler ve hata ayıklayıcı (debugger) gibi araçların tamamını kapsayan pakettir.

*5.* Firmware nedir?
- Donanımı doğrudan kontrol eden, genellikle kalıcı belleğe (Flash/ROM) yazılan alt seviye gömülü yazılımdır.