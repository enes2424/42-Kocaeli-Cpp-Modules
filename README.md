# 42 Kocaeli C++ Module 09
## STL Containers and Algorithms (STL Konteynerler ve Algoritmalar)

Bu proje, 42 Okulu C++ eğitiminin dokuzuncu modülüdür. STL (Standard Template Library) konteynerlerinin kullanımı, algoritmalar, veri yapıları ve performans karşılaştırması konularında derinlemesine bilgi edinmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Bitcoin Exchange
**Dosyalar:** `ex00/BitcoinExchange.cpp`, `ex00/BitcoinExchange.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Bitcoin fiyat dönüştürücü program - std::map kullanımı.
- **Program:** `btc`
- **Sınıf:** `BitcoinExchange`
- **Özellikler:**
  - CSV dosyasından Bitcoin tarihsel verilerini okur
  - Kullanıcı girişini doğrular ve hesaplar
  - Tarihe göre en yakın fiyatı bulur
  - Hata yönetimi ve format kontrolü
- **Veri Formatı:** `YYYY-MM-DD | miktar`
- **Örnek:**
  ```bash
  ./btc input.txt
  # input.txt içeriği:
  # date | value
  # 2011-01-03 | 3
  # 2011-01-03 | 2
  # 2011-01-03 | 1
  # 2011-01-05 | 2.3
  # 2011-01-09 | 1
  
  # Çıktı:
  # 2011-01-03 => 3 = 0.9
  # 2011-01-03 => 2 = 0.6
  # 2011-01-03 => 1 = 0.3
  # 2011-01-05 => 2.3 = 0.69
  # 2011-01-09 => 1 = 0.32
  ```

### ex01 - Reverse Polish Notation (RPN)
**Dosyalar:** `ex01/RPN.cpp`, `ex01/RPN.hpp`, `ex01/main.cpp`, `ex01/Makefile`

Ters Polonyalı notasyon hesaplayıcısı - std::stack kullanımı.
- **Program:** `RPN`
- **Sınıf:** `Rpn`
- **Özellikler:**
  - Stack tabanlı matematiksel işlem
  - Dört temel matematiksel operatör (+, -, *, /)
  - Hata yönetimi ve format kontrolü
  - Sadece tek haneli sayılarla çalışır
- **Algoritma:** Postfix (RPN) notation
- **Örnek:**
  ```bash
  ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
  # Çıktı: 42
  
  ./RPN "7 7 * 7 -"
  # Çıktı: 42
  
  ./RPN "1 2 * 2 / 2 * 2 4 - +"
  # Çıktı: 0
  
  ./RPN "(1 + 1)"
  # Çıktı: Error
  ```

### ex02 - PmergeMe
**Dosyalar:** `ex02/PmergeMe.cpp`, `ex02/PmergeMe.hpp`, `ex02/main.cpp`, `ex02/Makefile`

Ford-Johnson merge-insertion sort algoritması - konteyner performans karşılaştırması.
- **Program:** `PmergeMe`
- **Sınıf:** `PmergeMe`
- **Özellikler:**
  - Ford-Johnson algoritması implementasyonu
  - std::vector ve std::deque performans karşılaştırması
  - Jacobsthal sayı dizisi kullanımı
  - Binary search ile optimal yerleştirme
  - Zaman ölçümü ve performans analizi
- **Algoritmalar:** Merge-insertion sort, Binary search
- **Örnek:**
  ```bash
  ./PmergeMe 3 5 9 7 4
  # Çıktı:
  # Before: 3 5 9 7 4
  # After:  3 4 5 7 9
  # Time to process a range of 5 elements with std::vector : 0.00031 us
  # Time to process a range of 5 elements with std::deque : 0.00014 us
  
  ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
  # Büyük veri setleri için performans testi
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
# ex00 - Bitcoin Exchange
cd ex00
make
./btc input.txt

# ex01 - RPN Calculator
cd ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

# ex02 - PmergeMe
cd ex02
make
./PmergeMe 3 5 9 7 4
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Object dosyalarını sil
make fclean # Tüm çıktı dosyalarını sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **STL Containers**: std::map, std::stack, std::vector, std::deque
2. **Algorithms**: Ford-Johnson sort, Binary search, Merge-insertion
3. **Performance Analysis**: Zaman karşılaştırması, konteyner verimliliği
4. **Template Programming**: Generic fonksiyonlar ve sınıflar
5. **Exception Handling**: std::runtime_error, try-catch blokları
6. **File I/O**: std::ifstream, CSV dosya işleme
7. **String Processing**: Parsing, validation, format kontrolü
8. **Mathematical Operations**: RPN hesaplama, tarih aritmetiği
9. **Memory Management**: Dynamic arrays, container yönetimi
10. **Static Class Design**: Utility classes, static methods

## 📋 C++ Standartları ve Kurallar

- **C++98 Standardı**: Projede kullanılan C++ versiyonu
- **STL Usage**: Standard Template Library konteynerler
- **Derleme Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Orthodox Canonical Form**: Copy constructor, assignment operator, destructor
- **Performance Optimization**: Algoritma karmaşıklığı ve verimliliği
- **Error Handling**: Robust hata yönetimi ve validation
- **Template Metaprogramming**: Generic algoritma implementasyonu

## 🔍 Test Senaryoları

### ex00 Test - Bitcoin Exchange
```bash
# Geçerli giriş
./btc input.txt
# input: 2011-01-03 | 3
# output: 2011-01-03 => 3 = 0.9

# Hatalı format
# input: 2011-1-03 | 3
# output: Error: bad input => 2011-1-03 | 3

# Negatif değer
# input: 2011-01-03 | -1
# output: Error: not a positive number.

# Çok büyük değer
# input: 2011-01-03 | 2147483648
# output: Error: too large a number.
```

### ex01 Test - RPN Calculator
```bash
# Geçerli RPN ifadesi
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  # 42
./RPN "7 7 * 7 -"                    # 42
./RPN "1 2 * 2 / 2 * 2 4 - +"       # 0

# Hatalı format
./RPN "1 2 * 2 / 2 * 2 4 - + 1"     # Error
./RPN "(1 + 1)"                      # Error
./RPN "1 0 /"                        # Division by zero!!
```

### ex02 Test - PmergeMe
```bash
# Küçük veri seti
./PmergeMe 3 5 9 7 4
# Before: 3 5 9 7 4
# After:  3 4 5 7 9

# Büyük veri seti
./PmergeMe `seq 1 10000 | sort -R | tr '\n' ' '`
# Performans karşılaştırması

# Hatalı giriş
./PmergeMe 3 -5 9    # Error (negatif sayı)
./PmergeMe 3 a 9     # Error (geçersiz karakter)
```

## 📊 Algoritma Analizi

### Ford-Johnson Algorithm (ex02)
- **Zaman Karmaşıklığı**: O(n log n)
- **Alan Karmaşıklığı**: O(n)
- **Özellik**: Minimum karşılaştırma sayısı
- **Jacobsthal Sequence**: Optimal insertion order
- **Binary Search**: O(log n) insertion position

### Bitcoin Price Lookup (ex00)
- **Zaman Karmaşıklığı**: O(log n) per query
- **Alan Karmaşıklığı**: O(n)
- **Veri Yapısı**: std::map (Red-Black Tree)
- **Arama Stratejı**: Lower bound search

### RPN Calculation (ex01)
- **Zaman Karmaşıklığı**: O(n)
- **Alan Karmaşıklığı**: O(n)
- **Veri Yapısı**: std::stack
- **Parsing**: Single-pass algorithm

## 📝 Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- STL konteynerlerinin verimli kullanımı gösterilmiştir
- Template programming ve generic algoritma örnekleri
- Performance analysis ve benchmarking teknikleri
- Exception handling ve error management best practices
- File I/O operations ve data parsing strategies
- Mathematical algorithms ve computational complexity
- Memory management ve resource optimization
