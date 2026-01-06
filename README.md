# Uzay Fizik Simülasyonu

Bu proje, C programlama dili kullanılarak geliştirilmiş konsol tabanlı bir uzay fizik simülasyonu uygulamasıdır. Program, bir bilim insanının Güneş Sistemi'ndeki farklı gezegenlerde fizik deneyleri yapmasını simüle eder.

## Proje Özellikleri

- **9 Farklı Fizik Deneyi**: Serbest düşme, yukarı atış, ağırlık, potansiyel enerji, hidrostatik basınç, Arşimet kaldırma kuvveti, basit sarkaç periyodu, sabit ip gerilmesi ve asansör deneyleri
- **8 Gezegen Simülasyonu**: Tüm deneyler Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs ve Neptün için ayrı ayrı simüle edilir
- **Metrik Birimler**: Tüm hesaplamalar SI birim sisteminde yapılır (kg, m, s, m³, J, N, Pa)
- **Pointer Tabanlı Tasarım**: Dizi erişimleri pointer mantığıyla yapılır
- **Girdi Doğrulama**: Negatif değerler otomatik olarak mutlak değere dönüştürülür

## Derleme ve Çalıştırma

### Gereksinimler
- GCC derleyici
- C99 standardı desteği
- Matematik kütüphanesi (libm)

### Derleme

Makefile kullanarak:
```bash
make
```

Veya manuel olarak:
```bash
gcc -Wall -Wextra -std=c99 -o uzay_fizik_simulasyonu main.c -lm
```

### Çalıştırma

```bash
./uzay_fizik_simulasyonu
```

veya Makefile ile:
```bash
make run
```

## Kullanım

1. Program başladığında bilim insanı adınızı giriniz
2. Menüden yapmak istediğiniz deneyi seçiniz (1-9)
3. Deney için gerekli parametreleri giriniz
4. Tüm gezegenler için sonuçlar otomatik olarak hesaplanıp gösterilir
5. Programdan çıkmak için `-1` giriniz

## Deneyler ve Formüller

### 1. Serbest Düşme Deneyi
- **Girdi**: Süre (t) - saniye
- **Çıktı**: Alınan yol (h) - metre
- **Formül**: h = (1/2) · g · t²

### 2. Yukarı Atış Deneyi
- **Girdi**: İlk hız (v₀) - m/s
- **Çıktı**: Maksimum yükseklik (h_max) - metre
- **Formül**: h_max = v₀² / (2g)

### 3. Ağırlık Deneyi
- **Girdi**: Kütle (m) - kg
- **Çıktı**: Ağırlık (G) - Newton
- **Formül**: G = m · g

### 4. Kütleçekimsel Potansiyel Enerji Deneyi
- **Girdi**: Kütle (m) - kg, Yükseklik (h) - m
- **Çıktı**: Potansiyel enerji (Eₚ) - Joule
- **Formül**: Eₚ = m · g · h

### 5. Hidrostatik Basınç Deneyi
- **Girdi**: Yoğunluk (ρ) - kg/m³, Derinlik (h) - m
- **Çıktı**: Basınç (P) - Pascal
- **Formül**: P = ρ · g · h

### 6. Arşimet Kaldırma Kuvveti Deneyi
- **Girdi**: Yoğunluk (ρ) - kg/m³, Batan hacim (V) - m³
- **Çıktı**: Kaldırma kuvveti (Fₖ) - Newton
- **Formül**: Fₖ = ρ · g · V

### 7. Basit Sarkaç Periyodu Deneyi
- **Girdi**: İp uzunluğu (L) - metre
- **Çıktı**: Periyot (T) - saniye
- **Formül**: T = 2π √(L / g)

### 8. Sabit İp Gerilmesi Deneyi
- **Girdi**: Kütle (m) - kg
- **Çıktı**: İp gerilmesi (T) - Newton
- **Formül**: T = m · g

### 9. Asansör Deneyi
- **Girdi**: Kütle (m) - kg, İvme (a) - m/s², Hareket yönü
- **Çıktı**: Hissedilen ağırlık (N) - Newton
- **Formül**: 
  - Yukarı ivmelenme / Aşağı yavaşlama: N = m(g + a)
  - Aşağı ivmelenme / Yukarı yavaşlama: N = m(g - a)

## Gezegen Yerçekimi İvmeleri

| Gezegen | Yerçekimi İvmesi (m/s²) |
|---------|------------------------|
| Merkür  | 3.7                    |
| Venüs   | 8.87                   |
| Dünya   | 9.81                   |
| Mars    | 3.71                   |
| Jüpiter | 24.79                  |
| Satürn  | 10.44                  |
| Uranüs  | 8.69                   |
| Neptün  | 11.15                  |

## Teknik Detaylar

- **Programlama Dili**: C (C99 standardı)
- **Derleyici**: GCC
- **Kütüphaneler**: stdio.h, stdlib.h, string.h, math.h
- **Pointer Kullanımı**: Tüm dizi erişimleri pointer notasyonu ile yapılır
- **Girdi Doğrulama**: Negatif değerler ternary operator ile mutlak değere dönüştürülür

## Dosya Yapısı

```
avp_proje_2026/
├── main.c          # Ana program kaynak kodu
├── Makefile        # Derleme dosyası
└── README.md       # Proje dokümantasyonu
```

## Lisans

Bu proje eğitim amaçlı geliştirilmiştir.

## Geliştirici Notları

- Tüm deney fonksiyonları pointer parametreleri alır
- Dizi elemanlarına erişim `get_gravity_at_index()` fonksiyonu ile yapılır
- Negatif değer kontrolü ternary operator (`?:`) ile gerçekleştirilir
- Program menü döngüsü içinde çalışır ve `-1` ile sonlandırılır

