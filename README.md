# 42 Kocaeli C++ Module 08
## Templated Containers, Iterators and Algorithms (Şablonlu Konteynerler, İteratörler ve Algoritmalar)

Bu proje, 42 Okulu C++ eğitiminin sekizinci modülüdür. C++ Template programlama, STL konteynerları, iteratörler, algoritmalar ve özel exception sınıfları oluşturmayı öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Easy find
**Dosyalar:** `ex00/easyfind.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Template ile yazılmış arama algoritması.
- **Program:** `ex00`
- **Template Fonksiyon:** `easyfind<T>`
- **Özellikler:**
  - STL konteynerlarında integer arama
  - Iterator kullanımı
  - Özel exception fırlatma
  - Hem vector hem list ile çalışma
- **Exception:** `NotFoundException` - aranan değer bulunamadığında
- **Örnek:**
  ```cpp
  std::vector<int> vector;
  vector.push_back(3); vector.push_back(2); vector.push_back(5);
  
  try {
      std::vector<int>::iterator it = easyfind(vector, 5);
      std::cout << "Found: " << *it << std::endl;
  } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
  }
  ```

### ex01 - Span
**Dosyalar:** `ex01/Span.hpp`, `ex01/Span.cpp`, `ex01/main.cpp`, `ex01/Makefile`

Sayı dizilerinde en kısa ve en uzun mesafeyi bulan sınıf.
- **Program:** `ex01`
- **Sınıf:** `Span`
- **Fonksiyonlar:**
  - `addNumber(int)` - Tek sayı ekleme
  - `improveAddNumber(int len, int *nums)` - Çoklu sayı ekleme
  - `shortestSpan()` - En kısa mesafe
  - `longestSpan()` - En uzun mesafe
- **Exceptions:**
  - `MaximumExceedance` - Maksimum kapasite aşımı
  - `Impossible` - Yetersiz eleman (0 veya 1 eleman)
- **Örnek:**
  ```cpp
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  
  std::cout << sp.shortestSpan() << std::endl; // 2 (6-3=3, 9-11=2)
  std::cout << sp.longestSpan() << std::endl;  // 14 (17-3=14)
  ```

### ex02 - Mutated abomination
**Dosyalar:** `ex02/MutantStack.hpp`, `ex02/main.cpp`, `ex02/Makefile`

Iterator özelliği eklenmiş Stack sınıfı.
- **Program:** `ex02`
- **Sınıf:** `MutantStack<T>` (std::stack'ten türemiş)
- **Özellikler:**
  - std::stack'in tüm işlevleri
  - İteratör desteği (begin(), end())
  - Custom iterator sınıfı
  - Copy constructor ve assignment operator
- **Iterator Operatörleri:**
  - `operator*()` - Değer erişimi
  - `operator++()` / `operator--()` - İleri/geri hareket
  - `operator==()` / `operator!=()` - Karşılaştırma
- **Örnek:**
  ```cpp
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  
  while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
  }
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
# ex00 - Easy find
cd ex00
make
./ex00

# ex01 - Span
cd ex01
make
./ex01

# ex02 - MutantStack
cd ex02
make
./ex02
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Object dosyalarını sil
make fclean # Object ve çalıştırılabilir dosyaları sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **Template Programming**: Function ve class template'leri
2. **STL Containers**: std::vector, std::list, std::stack kullanımı
3. **Iterators**: Iterator pattern'i ve custom iterator yazımı
4. **Algorithms**: STL algoritmaları (std::sort) kullanımı
5. **Exception Handling**: Custom exception sınıfları oluşturma
6. **Container Inheritance**: STL konteynerlerinden türeme
7. **Generic Programming**: Type-independent kod yazımı
8. **Iterator Categories**: Forward, bidirectional iterator türleri
9. **Container Adapters**: Stack adapter'ı özelleştirme
10. **RAII Principles**: Resource management template'lerde

## 📋 C++ Standartları ve Kurallar

- **C++98 Standardı**: Projede kullanılan C++ versiyonu
- **Derleme Flags**: `-Wall -Wextra -Werror -std=c++98` (tüm uyarılar hata olarak işlenir)
- **Template Specialization**: Generic template yazımı
- **STL Compliance**: Standard Template Library kurallarına uygunluk
- **Iterator Requirements**: Iterator interface gereksinimleri
- **Exception Safety**: Strong exception guarantee
- **Header Guards**: `#pragma once` veya `#ifndef` kullanımı
- **Coding Style**: 42 School norminette kuralları

## 🔍 Test Senaryoları

### ex00 Test
```bash
./ex00
# Test: vector ve list'te sayı arama
# Test: Bulunmayan sayı için exception
# Test: Iterator dönüş değeri kontrolü
```

### ex01 Test
```bash
./ex01
# Test: Tek sayı ekleme
# Test: Çoklu sayı ekleme (improveAddNumber)
# Test: Maksimum kapasite aşımı exception'ı
# Test: Yetersiz eleman exception'ı
# Test: En kısa ve en uzun mesafe hesaplama
# Test: 10000 elemanlı büyük veri seti
```

### ex02 Test
```bash
./ex02
# Test: Stack operasyonları (push, pop, top, size)
# Test: Iterator ile gezinme
# Test: Copy constructor ve assignment operator
# Test: std::stack ile uyumluluk
# Test: Iterator operatörleri (++, --, *, ==, !=)
```

## 📝 Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- Template metaprogramming teknikleri kullanılmıştır
- STL container'ları ve algoritmaları etkin şekilde kullanılmıştır
- Custom exception handling implemented
- Iterator pattern doğru şekilde uygulanmıştır
- Generic programming prensipleri takip edilmiştir
- Container inheritance ve adapter pattern'leri kullanılmıştır
