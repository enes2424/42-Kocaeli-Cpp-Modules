# 42 Kocaeli C++ Module 02
## Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Form

Bu proje, 42 Okulu C++ eğitiminin ikinci modülüdür. Fixed-point sayılar, operator overloading, orthodox canonical form ve ad-hoc polymorphism kavramlarını öğretmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - My First Class in Orthodox Canonical Form
**Dosyalar:** `ex00/Fixed.hpp`, `ex00/Fixed.cpp`, `ex00/main.cpp`

Temel Fixed-point sayı sınıfının orthodox canonical form'da implementasyonu.
- **Sınıf:** `Fixed`
- **Özellikler:**
  - Private integer member (fixed-point değer)
  - Static const integer (fractional bits sayısı = 8)
  - Default constructor
  - Copy constructor  
  - Copy assignment operator
  - Destructor
- **Fonksiyonlar:**
  - `getRawBits()` - raw bit değerini döndürür
  - `setRawBits()` - raw bit değerini ayarlar
- **Örnek Çıktı:**
  ```
  Default constructor called
  Copy constructor called
  Copy assignment operator called
  getRawBits member function called
  0
  getRawBits member function called
  0
  getRawBits member function called
  0
  Destructor called
  Destructor called
  Destructor called
  ```

### ex01 - Towards a More Useful Fixed-point Number Class
**Dosyalar:** `ex01/Fixed.hpp`, `ex01/Fixed.cpp`, `ex01/main.cpp`

Fixed-point sınıfına dönüşüm fonksiyonları ve constructor'ların eklenmesi.
- **Yeni Constructor'lar:**
  - `Fixed(const int integer)` - integer'dan fixed-point'e dönüşüm
  - `Fixed(const float f)` - float'tan fixed-point'e dönüşüm
- **Dönüşüm Fonksiyonları:**
  - `toFloat()` - fixed-point'i float'a dönüştürür
  - `toInt()` - fixed-point'i integer'a dönüştürür
- **Operator Overloading:**
  - `operator<<` - çıktı stream operatörü
- **Örnek:**
  ```cpp
  Fixed const b(10);     // int constructor
  Fixed const c(42.42f); // float constructor
  cout << "b is " << b << endl; // çıktı: 10
  cout << "c is " << c << endl; // çıktı: 42.4219
  ```

### ex02 - Now We're Talking
**Dosyalar:** `ex02/Fixed.hpp`, `ex02/Fixed.cpp`, `ex02/main.cpp`

Fixed-point sınıfına karşılaştırma, aritmetik ve increment/decrement operatörlerinin eklenmesi.
- **Karşılaştırma Operatörleri:**
  - `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Aritmetik Operatörler:**
  - `+`, `-`, `*`, `/`
- **Increment/Decrement:**
  - `++a` (pre-increment), `a++` (post-increment)
  - `--a` (pre-decrement), `a--` (post-decrement)
- **Static Fonksiyonlar:**
  - `min()` - iki değerden küçük olanı döndürür
  - `max()` - iki değerden büyük olanı döndürür
- **Örnek:**
  ```cpp
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  cout << ++a << endl;  // pre-increment
  cout << a++ << endl;  // post-increment
  cout << Fixed::max(a, b) << endl; // maksimum değer
  ```

### ex03 - BSP (Binary Space Partitioning)
**Dosyalar:** `ex03/Fixed.hpp`, `ex03/Fixed.cpp`, `ex03/Point.hpp`, `ex03/Point.cpp`, `ex03/bsp.cpp`, `ex03/main.cpp`

Bir noktanın üçgen içinde olup olmadığını kontrol eden BSP algoritması.
- **Point Sınıfı:**
  - Private const Fixed x, y koordinatları
  - Constructor'lar ve getter fonksiyonları
- **BSP Fonksiyonu:**
  - `bsp(Point a, Point b, Point c, Point p)` - p noktasının abc üçgeni içinde olup olmadığını kontrol eder
- **Algoritma:**
  - Determinant hesaplaması ile alan bulma
  - Üçgen alanının alt üçgenlerin alanları toplamına eşit olup olmadığını kontrol etme
- **Örnek:**
  ```cpp
  Point a(1, 1);
  Point b(2, 5);
  Point c(5, 4);
  Point p(2, 3);
  bool inside = bsp(a, b, c, p); // p noktası üçgen içinde mi?
  ```

## 🔧 Kullanım

### Derleme Gereksinimleri
```bash
# C++98 standardı ile derleme
c++ -Wall -Wextra -Werror -std=c++98
```

### Derleme ve Çalıştırma
```bash
# ex00 - Orthodox Canonical Form
cd ex00
make
./a.out

# ex01 - Fixed-point Numbers
cd ex01
make  
./a.out

# ex02 - Operator Overloading
cd ex02
make
./a.out

# ex03 - BSP Algorithm
cd ex03
make
./a.out
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Object dosyalarını temizle
make re     # Temizle ve yeniden derle
```

### C++ Derleyici Kurulumu
```bash
# Ubuntu/Debian
sudo apt-get install g++

# macOS (Xcode Command Line Tools)
xcode-select --install

# CentOS/RHEL
sudo yum install gcc-c++
```

## 🎯 Öğrenilen Kavramlar

1. **Orthodox Canonical Form**: C++ sınıflarının standart form kuralları
   - Default constructor
   - Copy constructor
   - Copy assignment operator
   - Destructor

2. **Fixed-Point Aritmetiği**: Floating-point olmadan ondalık sayı işlemleri
   - Bit shifting ile integer/float dönüşümü
   - Sabit nokta aritmetiği

3. **Operator Overloading**: Operatörlerin sınıf için yeniden tanımlanması
   - Aritmetik operatörler (+, -, *, /)
   - Karşılaştırma operatörleri (>, <, ==, vb.)
   - Increment/decrement operatörleri (++, --)
   - Stream operatörü (<<)

4. **Ad-hoc Polymorphism**: Aynı operatörün farklı tiplerle çalışması

5. **Static Member Functions**: Sınıf seviyesinde fonksiyonlar

6. **Const Correctness**: Const member'lar ve fonksiyonlar

7. **Binary Space Partitioning**: Geometrik algoritma implementasyonu

## 🧮 Fixed-Point Aritmetiği

Fixed-point sayı sistemi, ondalık sayıları integer'lar kullanarak temsil etme yöntemidir:

```cpp
// 8 bit fractional part ile
float value = 42.42f;
int fixed = roundf(value * (1 << 8)); // 256 ile çarp
float back = (float)fixed / (1 << 8); // 256'ya böl
```

**Avantajları:**
- Deterministik sonuçlar
- Floating-point hatalarından kaçınma
- Embedded sistemlerde performans

## 📐 BSP Algoritması

Bir noktanın üçgen içinde olup olmadığını kontrol etmek için:

1. Ana üçgenin alanını hesapla
2. Nokta ile üçgenin her kenarı arasında oluşan 3 alt üçgenin alanlarını hesapla
3. Alt üçgenlerin alanları toplamı ana üçgenin alanına eşitse nokta içerdedir

```cpp
// Determinant ile alan hesaplama
area = |det([x1 y1; x2 y2])| / 2
```

## 📝 Notlar

- Tüm kodlar C++98 standardına uygun yazılmıştır
- Orthodox Canonical Form kurallarına sıkı sıkıya uyulmuştur
- Fixed-point aritmetiği IEEE 754 floating-point'e alternatif olarak gösterilmiştir
- Operator overloading'in doğru kullanımı örneklenmiştir
- Memory leak'ler ve undefined behavior'dan kaçınılmıştır
- Exception handling henüz kapsamda değildir
- STL container'ları bu modülde kullanılmamaktadır
- Template'ler bir sonraki modülde ele alınacaktır

## 📋 C++ Standartları ve Kurallar

- **C++98 Standardı**: Projede kullanılan C++ versiyonu
- **Derleme Flags**: `-Wall -Wextra -Werror -std=c++98` (tüm uyarılar hata olarak işlenir)
- **Orthodox Canonical Form**: Copy constructor, assignment operator, destructor
- **RAII Prensibi**: Resource Acquisition Is Initialization
- **Header Guards**: `#pragma once` veya `#ifndef` kullanımı
- **Coding Style**: 42 School norminette kuralları

## 🔍 Test Senaryoları

### ex00 Test
```bash
# Orthodox canonical form testleri
./a.out
# Default constructor called
# Copy constructor called
# Copy assignment operator called
# 0, 0, 0 çıktısı
# 3 destructor çağrısı
```

### ex01 Test
```bash
# Constructor ve dönüşüm testleri
./a.out
# a is 1234.43 (float dönüşümü)
# b is 10 (int constructor)
# c is 42.4219 (float constructor)
# d is 10 (copy constructor)
# Integer dönüşüm testleri
```

### ex02 Test
```bash
# Operator overloading testleri
./a.out
# 0 (başlangıç değeri)
# 0.00390625 (pre-increment)
# 0.00390625 (increment sonrası)
# 0.00390625 (post-increment)
# 0.00781250 (post-increment sonrası)
# 10.1016 (multiplication result)
# 10.1016 (max fonksiyonu)
```

### ex03 Test
```bash
# BSP algoritması testleri
./a.out
# Point in triangle: 1 (true)
# Üçgen kenarında veya dışında: 0 (false)
# Farklı üçgen koordinatları ile test
```
