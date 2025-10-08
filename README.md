# 42 Kocaeli C++ Module 00
## Introduction to C++ (C++ ile Tanışma)

Bu proje, 42 Okulu C++ eğitiminin ilk modülüdür. C++ programlama dilinin temel sözdizimi, sınıf yapıları, nesne yönelimli programlama kavramları ve modern C++ özelliklerini öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Megaphone
**Dosyalar:** `ex00/megaphone.cpp`, `ex00/Makefile`

Büyük harfle çıktı veren megafon programı.
- **Program:** `megaphone`
- **Açıklama:** Komut satırı argümanlarını büyük harfe çevirerek yazdırır
- **Özellik:** Argüman verilmezse varsayılan mesaj yazdırır
- **Örnek:**
  ```bash
  ./megaphone "shhhhh... I think the students are asleep..."
  # Çıktı: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
  
  ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
  # Çıktı: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
  
  ./megaphone
  # Çıktı: * LOUD AND UNBEARABLE FEEDBACK NOISE *
  ```

### ex01 - My Awesome PhoneBook
**Dosyalar:** `ex01/my_awesome_phonebook.cpp`, `ex01/phonebook.cpp`, `ex01/contact.cpp`, `ex01/my_awesome_phonebook.hpp`, `ex01/Makefile`

Telefon rehberi uygulaması - C++ sınıflarına giriş.
- **Program:** `my_awesome_phonebook`
- **Sınıflar:** `PhoneBook`, `Contact`
- **Komutlar:** `ADD`, `SEARCH`, `EXIT`
- **Özellikler:**
  - Maksimum 8 kişi saklayabilir
  - Eski kayıtlar yenileriyle değiştirilir
  - Tablolu arama arayüzü
  - 10 karakterlik alan formatlaması
- **Örnek:**
  ```bash
  ./my_awesome_phonebook
  > ADD
  Name : John
  Surname : Doe
  Nickname : JD
  Phone Number : 1234567890
  Darkest Secret : Loves pineapple pizza
  
  > SEARCH
  |     index|      name|   surname|  nickname|
  |         1|      John|       Doe|        JD|
  search : 1
  Name : John
  Surname : Doe
  Nickname : JD
  Phone Number : 1234567890
  Darkest Secret : Loves pineapple pizza
  ```

### ex02 - The Job Of Your Dreams
**Dosyalar:** `ex02/Account.cpp`, `ex02/Account.hpp`, `ex02/tests.cpp`, `ex02/19920104_091532.log`, `ex02/Makefile`

Banka hesabı simülasyonu - statik üyeler ve log sistemi.
- **Program:** `Account`
- **Sınıf:** `Account`
- **Özellikler:**
  - Statik üye değişkenler ve fonksiyonlar
  - Zaman damgası sistemi
  - Para yatırma ve çekme işlemleri
  - Hesap bilgileri takibi
- **Log Formatı:**
  ```
  [YYYYMMDD_HHMMSS] index:X;amount:X;created
  [YYYYMMDD_HHMMSS] index:X;p_amount:X;deposit:X;amount:X;nb_deposits:X
  [YYYYMMDD_HHMMSS] index:X;p_amount:X;withdrawal:X;amount:X;nb_withdrawals:X
  [YYYYMMDD_HHMMSS] accounts:X;total:X;deposits:X;withdrawals:X
  ```
- **Statik Fonksiyonlar:**
  - `getNbAccounts()` - Hesap sayısı
  - `getTotalAmount()` - Toplam bakiye
  - `getNbDeposits()` - Toplam yatırma sayısı
  - `getNbWithdrawals()` - Toplam çekme sayısı
  - `displayAccountsInfos()` - Genel bilgi

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
# ex00 - Megaphone
cd ex00
make
./megaphone "test message"

# ex01 - PhoneBook
cd ex01
make
./my_awesome_phonebook

# ex02 - Account
cd ex02
make
./Account
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Çalıştırılabilir dosyayı sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **C++ Temelleri**: Sözdizimi, veri türleri, operatörler
2. **Sınıf Yapıları**: Class tanımlama, constructor/destructor
3. **Encapsulation**: Private/public üye erişimi
4. **Static Üyeler**: Sınıf düzeyinde değişken ve fonksiyonlar
5. **Header Files**: .hpp dosyaları ve include guard'lar
6. **Namespace**: std namespace kullanımı
7. **String İşlemleri**: C++ string sınıfı kullanımı
8. **Input/Output**: iostream ile giriş/çıkış işlemleri
9. **Memory Management**: Stack üzerinde nesne yönetimi
10. **Makefile**: C++ projelerinde derleme süreçleri

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
./megaphone "hello world"           # HELLO WORLD
./megaphone                         # * LOUD AND UNBEARABLE FEEDBACK NOISE *
./megaphone "test" "multiple" "args" # TESTMULTIPLEARGS
```

### ex01 Test
- 8'den fazla kişi ekleme (eski kayıtların silinmesi)
- Boş alanlarla kayıt ekleme
- Geçersiz indeks ile arama
- Uzun string'lerin kesilip '.' eklenmesi

### ex02 Test
- Test dosyası log çıktısının referans log ile karşılaştırılması
- Yetersiz bakiye ile para çekme
- Statik fonksiyonların doğru çalışması
- Zaman damgası formatının kontrolü

## 📝 Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- Memory leak'leri önlemek için dikkatli pointer yönetimi
- Exception handling henüz kapsamda değildir
- STL container'ları bu modülde kullanılmamaktadır
- Nesne yönelimli programlamanın temel prensipleri uygulanmıştır
