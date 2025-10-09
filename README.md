# 42 Kocaeli C++ Module 07
## C++ Templates (C++ Şablonları)

Bu proje, 42 Okulu C++ eğitiminin yedinci modülüdür. C++ template'leri (şablonları), generic programming kavramları ve template'lerin güçlü özelliklerini öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Start with a few functions
**Dosyalar:** `ex00/whatever.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Template fonksiyonlarına giriş.
- **Program:** `StartWithAFewFunctions`
- **Template Fonksiyonlar:** `swap`, `min`, `max`
- **Açıklama:** Generic tiplerle çalışan temel fonksiyonlar
- **Özellikler:**
  - Herhangi bir veri tipi ile çalışabilir
  - Tip güvenliği sağlar
  - Compile-time'da tip belirlenir
- **Örnek Çıktı:**
  ```bash
  ./StartWithAFewFunctions
  # a = 3, b = 2
  # min( a, b ) = 2
  # max( a, b ) = 3
  # c = chaine2, d = chaine1
  # min( c, d ) = chaine1
  # max( c, d ) = chaine2
  ```

### ex01 - Iter
**Dosyalar:** `ex01/iter.hpp`, `ex01/main.cpp`, `ex01/Makefile`

Template ile dizi işlemleri.
- **Program:** `Iter`
- **Template Fonksiyonlar:** `iter`, `add_with_self`
- **Açıklama:** Dizi elemanlarına fonksiyon uygulama
- **Özellikler:**
  - Generic dizi işlemleri
  - Fonksiyon pointer'ları ile çalışma
  - Farklı veri tiplerinde aynı operasyon
- **Örnek Çıktı:**
  ```bash
  ./Iter
  # 1, 2, 3, 4, 5
  # 2, 4, 6, 8, 10
  # 
  # 42, Kocaeli, Enes, Eboş, Azra
  # 4242, KocaeliKocaeli, EnesEnes, EboşEboş, AzraAzra
  # 
  # 34.32, 65.76, 980.21, 324.676, 21.333
  # 68.64, 131.52, 1960.42, 649.352, 42.666
  ```

### ex02 - Array
**Dosyalar:** `ex02/Array.hpp`, `ex02/main.cpp`, `ex02/Makefile`

Template sınıf implementasyonu.
- **Program:** `Array`
- **Template Sınıf:** `Array<T>`
- **Özellikler:**
  - Dynamic array implementation
  - Exception handling ile bounds checking
  - Copy constructor ve assignment operator
  - RAII prensibi
- **Üye Fonksiyonlar:**
  - `Array()` - Boş constructor
  - `Array(unsigned int n)` - Parametreli constructor
  - `operator[]` - İndeks erişimi
  - `size()` - Dizi boyutu
  - `OutOfBounds` exception sınıfı
- **Örnek Çıktı:**
  ```bash
  ./Array
  # size : 20
  # 
  # 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400
  # 
  # index is out of bounds
  # 
  # index is out of bounds
  # 
  # 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400
  # 
  # size : 3
  # 
  # 42Kocaeli
  # Enes
  # Turkiye
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
# ex00 - Start with a few functions
cd ex00
make
./StartWithAFewFunctions

# ex01 - Iter
cd ex01
make
./Iter

# ex02 - Array
cd ex02
make
./Array
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Object dosyalarını sil
make fclean # Tüm dosyaları sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **Template Temelleri**: Function template'leri ve syntax
2. **Generic Programming**: Tip-bağımsız programlama
3. **Template Fonksiyonlar**: `swap`, `min`, `max` implementasyonları
4. **Function Template Instantiation**: Compile-time tip belirleme
5. **Template Sınıflar**: Class template implementasyonu
6. **Template Specialization**: Özel tip implementasyonları
7. **Template Parameters**: typename ve template parametreleri
8. **Memory Management**: Template'lerle dynamic memory
9. **Exception Handling**: Template sınıflarda hata yönetimi
10. **SFINAE**: Substitution Failure Is Not An Error prensibi

## 📋 C++ Template Kuralları ve İlkeler

- **C++98 Template Syntax**: Klasik template sözdizimi
- **Template Declaration**: Header dosyalarında implementasyon
- **Template Instantiation**: Compile-time'da kod üretimi
- **Template Argument Deduction**: Otomatik tip çıkarımı
- **Template Specialization**: Özel durumlar için implementasyon
- **Template Metaprogramming**: Compile-time hesaplamalar
- **RAII with Templates**: Resource management prensibi
- **Template Error Messages**: Debug ve hata mesajları
- **Template Compilation**: Two-phase lookup kuralları

## 🔍 Test Senaryoları

### ex00 Test
```cpp
// Integer test
int a = 2, b = 3;
swap(a, b);  // a=3, b=2
min(a, b);   // returns 2
max(a, b);   // returns 3

// String test
std::string c = "chaine1", d = "chaine2";
swap(c, d);  // c="chaine2", d="chaine1"
min(c, d);   // returns "chaine1"
max(c, d);   // returns "chaine2"
```

### ex01 Test
```cpp
// Integer array
int arr[] = {1, 2, 3, 4, 5};
iter(arr, 5, &add_with_self);  // {2, 4, 6, 8, 10}

// String array
std::string arr2[] = {"42", "Kocaeli", "Enes"};
iter(arr2, 3, &add_with_self);  // {"4242", "KocaeliKocaeli", "EnesEnes"}

// Double array
double arr3[] = {1.1, 2.2, 3.3};
iter(arr3, 3, &add_with_self);  // {2.2, 4.4, 6.6}
```

### ex02 Test
```cpp
// Array creation and access
Array<int> arr(5);
arr[0] = 10;  // Normal access

// Exception testing
try {
    arr[10] = 5;  // Throws OutOfBounds
} catch (std::exception &e) {
    // Handle exception
}

// Copy operations
Array<int> arr2 = arr;  // Copy constructor
Array<int> arr3;
arr3 = arr;  // Assignment operator
```

## 📝 Template Özellikleri ve Avantajlar

### Template Avantajları
- **Type Safety**: Compile-time tip kontrolü
- **Performance**: Runtime overhead yok
- **Code Reuse**: Aynı kod farklı tipler için
- **Generic Programming**: Tip-bağımsız algoritma geliştirme
- **STL Foundation**: Standard Template Library temeli

### Template Dezavantajları
- **Compilation Time**: Uzun derleme süreleri
- **Code Bloat**: Her tip için ayrı kod üretimi
- **Error Messages**: Karmaşık hata mesajları
- **Debug Complexity**: Template kod debug zorluğu
- **Header Dependencies**: Header-only implementation

### Best Practices
- Template implementasyonlarını header dosyalarında tutun
- Meaningful template parameter isimleri kullanın
- SFINAE tekniklerini öğrenin
- Template specialization'ı gerektiğinde kullanın
- Template metaprogramming'i dikkatli kullanın

## 📝 Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- Template implementasyonları header dosyalarında yapılmıştır
- Memory management template'lerle dikkatli yapılmıştır
- Exception handling template sınıflarda uygulanmıştır
- Generic programming prensipleri takip edilmiştir
- RAII prensibi template sınıflarda uygulanmıştır
- Template specialization gerektiğinde kullanılmıştır
- STL container'larına alternatif implementasyonlar geliştirilmiştir
