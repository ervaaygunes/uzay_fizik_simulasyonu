#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_PLANETS 8
#define MAX_NAME_LENGTH 100
#define PI 3.14159265358979323846

// Gezegen isimleri dizisi
const char* planet_names[NUM_PLANETS] = {
    "Merkur",
    "Venus",
    "Dunya",
    "Mars",
    "Jupiter",
    "Saturn",
    "Uranus",
    "Neptun"
};

// Gezegen yerçekimi ivmeleri dizisi (m/s²)
const double planet_gravities[NUM_PLANETS] = {
    3.7,    // Merkur
    8.87,   // Venus
    9.81,   // Dunya
    3.71,   // Mars
    24.79,  // Jupiter
    10.44,  // Saturn
    8.69,   // Uranus
    11.15   // Neptun
};

// Fonksiyon prototipleri
void print_menu(const char* scientist_name);
void serbest_dusme(const double* gravities, const char* scientist_name);
void yukari_atis(const double* gravities, const char* scientist_name);
void agirlik_deneyi(const double* gravities, const char* scientist_name);
void potansiyel_enerji(const double* gravities, const char* scientist_name);
void hidrostatik_basinç(const double* gravities, const char* scientist_name);
void arsimet_kaldirma(const double* gravities, const char* scientist_name);
void basit_sarkac(const double* gravities, const char* scientist_name);
void sabit_ip_gerilmesi(const double* gravities, const char* scientist_name);
void asansor_deneyi(const double* gravities, const char* scientist_name);
double get_gravity_at_index(const double* gravities, int index);
const char* get_planet_name(int index);

// Pointer ile diziden değer alma fonksiyonu
double get_gravity_at_index(const double* gravities, int index) {
    return *(gravities + index);
}

// Pointer ile gezegen ismi alma fonksiyonu
const char* get_planet_name(int index) {
    return *(planet_names + index);
}

// Menü yazdırma fonksiyonu
void print_menu(const char* scientist_name) {
    printf("\n");
    printf("========================================\n");
    printf("  UZAY FIZIK SIMULASYONU\n");
    printf("  Bilim Insani: %s\n", scientist_name);
    printf("========================================\n");
    printf("\nDeney Listesi:\n");
    printf("  1. Serbest Dusme Deneyi\n");
    printf("  2. Yukari Atis Deneyi\n");
    printf("  3. Agirlik Deneyi\n");
    printf("  4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("  5. Hidrostatik Basinç Deneyi\n");
    printf("  6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("  7. Basit Sarkac Periyodu Deneyi\n");
    printf("  8. Sabit Ip Gerilmesi Deneyi\n");
    printf("  9. Asansor Deneyi\n");
    printf("  -1. Programdan Cikis\n");
    printf("\nDeney seciminizi yapiniz: ");
}

// 1. Serbest Düşme Deneyi
// Formül: h = (1/2) * g * t²
void serbest_dusme(const double* gravities, const char* scientist_name) {
    double t;
    printf("\n=== SERBEST DUSME DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen dusme suresini giriniz (saniye): ");
    scanf("%lf", &t);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    t = t < 0 ? -t : t;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen sure: %.2f s\n\n", t);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double h = 0.5 * g * t * t;
        printf("%s: Alinan yol h = %.4f m\n", planet, h);
    }
    printf("\n");
}

// 2. Yukarı Atış Deneyi
// Formül: h_max = v₀² / (2g)
void yukari_atis(const double* gravities, const char* scientist_name) {
    double v0;
    printf("\n=== YUKARI ATIS DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen ilk hizi giriniz (m/s): ");
    scanf("%lf", &v0);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    v0 = v0 < 0 ? -v0 : v0;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen ilk hiz: %.2f m/s\n\n", v0);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double h_max = (v0 * v0) / (2.0 * g);
        printf("%s: Maksimum yukseklik h_max = %.4f m\n", planet, h_max);
    }
    printf("\n");
}

// 3. Ağırlık Deneyi
// Formül: G = m * g
void agirlik_deneyi(const double* gravities, const char* scientist_name) {
    double m;
    printf("\n=== AGIRLIK DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen kutleyi giriniz (kg): ");
    scanf("%lf", &m);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    m = m < 0 ? -m : m;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen kutle: %.2f kg\n\n", m);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double G = m * g;
        printf("%s: Agirlik G = %.4f N\n", planet, G);
    }
    printf("\n");
}

// 4. Kütleçekimsel Potansiyel Enerji Deneyi
// Formül: Eₚ = m * g * h
void potansiyel_enerji(const double* gravities, const char* scientist_name) {
    double m, h;
    printf("\n=== KUTLECEKIMSEL POTANSIYEL ENERJI DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen kutleyi giriniz (kg): ");
    scanf("%lf", &m);
    printf("Lutfen yuksekligi giriniz (m): ");
    scanf("%lf", &h);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    m = m < 0 ? -m : m;
    h = h < 0 ? -h : h;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen kutle: %.2f kg\n", m);
    printf("Girilen yukseklik: %.2f m\n\n", h);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double Ep = m * g * h;
        printf("%s: Potansiyel enerji Ep = %.4f J\n", planet, Ep);
    }
    printf("\n");
}

// 5. Hidrostatik Basınç Deneyi
// Formül: P = ρ * g * h
void hidrostatik_basinç(const double* gravities, const char* scientist_name) {
    double rho, h;
    printf("\n=== HIDROSTATIK BASINÇ DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen yogunlugu giriniz (kg/m³): ");
    scanf("%lf", &rho);
    printf("Lutfen derinligi giriniz (m): ");
    scanf("%lf", &h);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    rho = rho < 0 ? -rho : rho;
    h = h < 0 ? -h : h;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen yogunluk: %.2f kg/m³\n", rho);
    printf("Girilen derinlik: %.2f m\n\n", h);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double P = rho * g * h;
        printf("%s: Basinç P = %.4f Pa\n", planet, P);
    }
    printf("\n");
}

// 6. Arşimet Kaldırma Kuvveti Deneyi
// Formül: Fₖ = ρ * g * V
void arsimet_kaldirma(const double* gravities, const char* scientist_name) {
    double rho, V;
    printf("\n=== ARSIMET KALDIRMA KUVVETI DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen yogunlugu giriniz (kg/m³): ");
    scanf("%lf", &rho);
    printf("Lutfen batan hacmi giriniz (m³): ");
    scanf("%lf", &V);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    rho = rho < 0 ? -rho : rho;
    V = V < 0 ? -V : V;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen yogunluk: %.2f kg/m³\n", rho);
    printf("Girilen batan hacim: %.2f m³\n\n", V);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double Fk = rho * g * V;
        printf("%s: Kaldirma kuvveti Fk = %.4f N\n", planet, Fk);
    }
    printf("\n");
}

// 7. Basit Sarkaç Periyodu Deneyi
// Formül: T = 2π √(L / g)
void basit_sarkac(const double* gravities, const char* scientist_name) {
    double L;
    printf("\n=== BASIT SARKAC PERIYODU DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen ip uzunlugunu giriniz (m): ");
    scanf("%lf", &L);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    L = L < 0 ? -L : L;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen ip uzunlugu: %.2f m\n\n", L);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double T = 2.0 * PI * sqrt(L / g);
        printf("%s: Periyot T = %.4f s\n", planet, T);
    }
    printf("\n");
}

// 8. Sabit İp Gerilmesi Deneyi
// Formül: T = m * g
void sabit_ip_gerilmesi(const double* gravities, const char* scientist_name) {
    double m;
    printf("\n=== SABIT IP GERILMESI DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen kutleyi giriniz (kg): ");
    scanf("%lf", &m);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    m = m < 0 ? -m : m;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen kutle: %.2f kg\n\n", m);
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double T = m * g;
        printf("%s: Ip gerilmesi T = %.4f N\n", planet, T);
    }
    printf("\n");
}

// 9. Asansör Deneyi
// Formül: N = m(g + a) veya N = m(g - a)
void asansor_deneyi(const double* gravities, const char* scientist_name) {
    double m, a;
    int direction;
    printf("\n=== ASANSOR DENEYI ===\n");
    printf("Bilim Insani: %s\n", scientist_name);
    printf("\nLutfen kutleyi giriniz (kg): ");
    scanf("%lf", &m);
    printf("Lutfen ivmeyi giriniz (m/s²): ");
    scanf("%lf", &a);
    printf("\nAsansor hareket yonu:\n");
    printf("  1. Yukari yonde ivmelenerek hizlaniyor veya asagi yonde ivmelenerek yavasliyor\n");
    printf("  2. Asagi yonde ivmelenerek hizlaniyor veya yukari yonde ivmelenerek yavasliyor\n");
    printf("Seciminiz (1 veya 2): ");
    scanf("%d", &direction);
    
    // Negatif değer kontrolü - ternary operator kullanımı
    m = m < 0 ? -m : m;
    a = a < 0 ? -a : a;
    
    printf("\n--- Sonuclar (Tum Gezegenler) ---\n");
    printf("Girilen kutle: %.2f kg\n", m);
    printf("Girilen ivme: %.2f m/s²\n", a);
    printf("Hareket yonu: %s\n\n", direction == 1 ? "Yukari/Asagi yavaslama" : "Asagi/Yukari yavaslama");
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        double g = get_gravity_at_index(gravities, i);
        const char* planet = get_planet_name(i);
        double N;
        
        // Ternary operator ile formül seçimi
        N = (direction == 1) ? (m * (g + a)) : (m * (g - a));
        
        // Negatif hissedilen ağırlık kontrolü (fiziksel olarak mantıklı değil ama hesaplıyoruz)
        printf("%s: Hissedilen agirlik N = %.4f N\n", planet, N);
    }
    printf("\n");
}

int main() {
    char scientist_name[MAX_NAME_LENGTH];
    int choice;
    
    // Program başlangıcı - bilim insanı adı alma
    printf("========================================\n");
    printf("  UZAY FIZIK SIMULASYONU\n");
    printf("========================================\n");
    printf("\nLutfen bilim insani adinizi giriniz: ");
    fgets(scientist_name, MAX_NAME_LENGTH, stdin);
    
    // fgets ile alınan string'in sonundaki newline karakterini kaldır
    size_t len = strlen(scientist_name);
    if (len > 0 && scientist_name[len - 1] == '\n') {
        scientist_name[len - 1] = '\0';
    }
    
    // Eğer boş string ise varsayılan isim kullan
    if (strlen(scientist_name) == 0) {
        strcpy(scientist_name, "Bilinmeyen Bilim Insani");
    }
    
    // Ana döngü - menü ve deney seçimi
    while (1) {
        print_menu(scientist_name);
        scanf("%d", &choice);
        
        // Pointer olarak gezegen yerçekimi dizisini gönder
        switch (choice) {
            case 1:
                serbest_dusme(planet_gravities, scientist_name);
                break;
            case 2:
                yukari_atis(planet_gravities, scientist_name);
                break;
            case 3:
                agirlik_deneyi(planet_gravities, scientist_name);
                break;
            case 4:
                potansiyel_enerji(planet_gravities, scientist_name);
                break;
            case 5:
                hidrostatik_basinç(planet_gravities, scientist_name);
                break;
            case 6:
                arsimet_kaldirma(planet_gravities, scientist_name);
                break;
            case 7:
                basit_sarkac(planet_gravities, scientist_name);
                break;
            case 8:
                sabit_ip_gerilmesi(planet_gravities, scientist_name);
                break;
            case 9:
                asansor_deneyi(planet_gravities, scientist_name);
                break;
            case -1:
                printf("\nProgramdan cikiliyor...\n");
                printf("Tesekkurler, %s!\n", scientist_name);
                return 0;
            default:
                printf("\nHata: Gecersiz secim! Lutfen 1-9 arasi bir sayi veya -1 giriniz.\n");
                break;
        }
    }
    
    return 0;
}

