# Günlük Rapor — Gün 06

| Alan | Değer |
|------|-------|
| **Stajyer** | C — Başar Yıldırım |
| **Tarih** | 2026-07-27 |
| **Konu** | UART, Debug |

## Bugün ne yaptım?

- Debug UART (UART10) modülünü ve ilgili TX (PC15) ile RX (PC14) pinlerini tespit etme.
- UART peripheral yapılandırmasını 115200 baud rate ve 8N1 (8 data bit, no parity, 1 stop bit) formatına uygun olarak tanımlama
- debugging

## Görev durumu

| Seviye | Yapıldı |
|--------|---------|
| Kolay | ☑ |
| Orta | ☑ |
| Zor | ☑ |

## Takıldığım yer

- Herhangi bir sorunla karşılaşmadım.


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
