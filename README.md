# 42 Kocaeli C++ Module 06
## C++ Casts (C++ Tip Dönüşümleri)

Bu proje, 42 Okulu C++ eğitiminin altıncı modülüdür. C++ programlama dilinde tip dönüşümleri (casting), reinterpret_cast, dynamic_cast kullanımı ve polimorfizm kavramlarını öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Conversion of Scalar Types
**Dosyalar:** `ex00/ScalarConverter.cpp`, `ex00/ScalarConverter.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Skaler tip dönüştürücü sınıfı - C++ static cast ve tip dönüşümleri.
- **Program:** `convert`
- **Sınıf:** `ScalarConverter`
- **Açıklama:** String olarak verilen değeri char, int, float ve double tiplerinde gösterir
- **Özellikler:**
  - Statik sınıf (instantiate edilemez)
  - Pseudo literals desteklenir (nan, +inf, -inf, inf)
  - Görüntülenemeyen karakterler için "Non displayable"
  - Geçersiz dönüşümler için "impossible"
- **Örnek:**
  ```bash
  ./convert 0
  # Çıktı:
  # char: Non displayable
  # int: 0
  # float: 0.0f
  # double: 0.0

  ./convert nan
  # Çıktı:
  # char: impossible
  # int: impossible
  # float: nanf
  # double: nan

  ./convert 42.0f
  # Çıktı:
  # char: '*'
  # int: 42
  # float: 42.0f
  # double: 42.0
  ```

### ex01 - Serialization
**Dosyalar:** `ex01/Serializer.cpp`, `ex01/Serializer.hpp`, `ex01/main.cpp`, `ex01/Makefile`

Serialization (serileştirme) işlemleri - reinterpret_cast kullanımı.
- **Program:** `Serialization`
- **Sınıf:** `Serializer`
- **Struct:** `Data` (string, char, int, float, double içerir)
- **Özellikler:**
  - Statik sınıf (instantiate edilemez)
  - Data pointer'ını uintptr_t tipine dönüştürür
  - uintptr_t tipini tekrar Data pointer'a dönüştürür
  - reinterpret_cast kullanarak pointer serialization
- **Fonksiyonlar:**
  - `serialize(Data* ptr)` - Data pointer'ını uintptr_t'ye çevirir
  - `deserialize(uintptr_t raw)` - uintptr_t'yi Data pointer'a çevirir
- **Örnek:**
  ```bash
  ./Serialization
  # Çıktı:
  # 0x7fff5fbff6b0
  # 42Kocaeli
  # c
  # 42
  # 42.42
  # 42.42
  # ---------------------------
  # Conversion = 140734799714992
  # ---------------------------
  # 0x7fff5fbff6b0
  # 42Kocaeli
  # c
  # 42
  # 42.42
  # 42.42
  ```

### ex02 - Identify Real Type
**Dosyalar:** `ex02/Base.cpp`, `ex02/Base.hpp`, `ex02/main.cpp`, `ex02/Makefile`

Gerçek tip belirleme - dynamic_cast ve polimorfizm.
- **Program:** `Identify`
- **Sınıflar:** `Base` (sanal sınıf), `A`, `B`, `C` (Base'den türeyen)
- **Özellikler:**
  - Virtual destructor ile polimorfizm
  - Random tip oluşturma
  - Pointer ve referans ile tip belirleme
  - dynamic_cast kullanarak runtime tip kontrolü
- **Fonksiyonlar:**
  - `generate()` - Rastgele A, B veya C tipinde nesne oluşturur
  - `identify(Base* p)` - Pointer ile tip belirler
  - `identify(Base& p)` - Referans ile tip belirler (exception handling)
- **Örnek:**
  ```bash
  ./Identify
  # Çıktı:
  # A
  # A
  # BASE
  # BASE
  ```

## 🔧 Kullanım

### C++ Derleyici Kurulumu
```bash
# Ubuntu/Debian
sudo apt-get install g++

# macOS (Xcode Command Line Tools)
xcode-select --install

# CentOS/RHEL
sudo yum install gcc-c++
```

### Derleme ve Çalıştırma
```bash
# ex00 - Scalar Converter
cd ex00
make
./convert "42.0f"
./convert "nan"
./convert "a"

# ex01 - Serializer
cd ex01
make
./Serialization

# ex02 - Base Identification
cd ex02
make
./Identify
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Object dosyalarını sil
make fclean # Object dosyalarını ve çalıştırılabilir dosyayı sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **C++ Casts**: static_cast, dynamic_cast, reinterpret_cast
2. **Type Conversion**: Implicit ve explicit tip dönüşümleri
3. **Serialization**: Pointer'ları integer'a dönüştürme
4. **Polymorphism**: Sanal fonksiyonlar ve dynamic binding
5. **RTTI (Runtime Type Information)**: dynamic_cast ile tip kontrolü
6. **Exception Handling**: try-catch blokları
7. **Static Classes**: Instance oluşturulmayan utility sınıfları
8. **Pseudo Literals**: nan, inf gibi özel değerler
9. **Memory Management**: Dynamic allocation ve deallocation
10. **Header Guards**: #ifndef kullanımı

## 📋 C++ Standartları ve Casting Kuralları

- **C++98 Standardı**: Projede kullanılan C++ versiyonu
- **Derleme Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Static Cast**: Güvenli tip dönüşümleri için
- **Dynamic Cast**: Polimorfik sınıflarda runtime tip kontrolü
- **Reinterpret Cast**: Pointer'ları farklı tiplere dönüştürme
- **Const Cast**: Const qualifier'ları kaldırma (bu modülde kullanılmıyor)

## 🔍 Cast Türleri ve Kullanımları

### Static Cast
```cpp
int i = 42;
float f = static_cast<float>(i);  // Güvenli dönüşüm
```

### Dynamic Cast
```cpp
Base* base = new A();
A* a = dynamic_cast<A*>(base);    // Runtime'da tip kontrolü
if (a) { /* başarılı */ }         // NULL ise başarısız
```

### Reinterpret Cast
```cpp
Data* ptr = &data;
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);  // Bit düzeyinde dönüşüm
Data* newPtr = reinterpret_cast<Data*>(raw);       // Geri dönüşüm
```

## 🔍 Test Senaryoları

### ex00 Test
```bash
./convert "0"                     # Kontrol karakteri
./convert "42"                    # Normal sayı
./convert "42.0f"                 # Float literal
./convert "42.42"                 # Double
./convert "nan"                   # Not a Number
./convert "+inf"                  # Pozitif sonsuz
./convert "-inf"                  # Negatif sonsuz
./convert "a"                     # Tek karakter
./convert "invalid"               # Geçersiz string
```

### ex01 Test
- Original pointer ile deserialized pointer'ın aynı olması
- Data içeriğinin korunması
- uintptr_t dönüşümünün doğruluğu
- Memory address'lerin eşleşmesi

### ex02 Test
- Rastgele tip oluşturma fonksiyonalitesi
- Pointer ile tip belirleme
- Referans ile tip belirleme (exception handling)
- Base sınıfı ile tip belirleme
- Memory leak kontrolü

## 📝 Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- Casting işlemleri güvenli şekilde yapılmıştır
- Memory management dikkatli şekilde uygulanmıştır
- Exception safety sağlanmıştır
- RTTI (Runtime Type Information) etkin kullanılmıştır
- Static sınıflar Orthodox Canonical Form'a uygun şekilde tasarlanmıştır

## ⚠️ Önemli Uyarılar

- `reinterpret_cast` dikkatli kullanılmalıdır, undefined behavior'a yol açabilir
- `dynamic_cast` sadece polimorfik sınıflarda çalışır
- Serialization işlemlerinde platform bağımlılığı olabilir
- Exception handling'de performans overhead'i vardır
- Virtual destructor kullanımı memory leak'leri önler
