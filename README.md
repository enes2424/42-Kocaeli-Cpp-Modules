# 42 Kocaeli C++ Module 01
## Memory Management and Class Basics (Bellek Yönetimi ve Sınıf Temelleri)

Bu proje, 42 Okulu C++ eğitiminin birinci modülüdür. C++ programlama dilinde bellek yönetimi, sınıf tasarımı, referanslar ve işaretçiler, dosya işlemleri ve string manipülasyonu konularında temel bilgi ve becerileri geliştirmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - BraiiiiiiinnnzzzZ
**Dosyalar:** `ex00/Zombie.hpp`, `ex00/Zombie.cpp`, `ex00/newZombie.cpp`, `ex00/randomChump.cpp`, `ex00/main.cpp`, `ex00/Makefile`

Stack ve Heap bellek yönetimini öğreten temel Zombie sınıfı implementasyonu.
- **Program:** `BraiiiiiiinnnzzzZ`
- **Sınıf:** `Zombie`
- **Üye fonksiyonlar:** 
  - `Zombie(std::string name)` - Constructor
  - `~Zombie(void)` - Destructor
  - `void announce(void)` - Zombie'nin konuşma fonksiyonu
- **Yardımcı fonksiyonlar:**
  - `Zombie* newZombie(std::string name)` - Heap'te zombie oluşturur
  - `void randomChump(std::string name)` - Stack'te zombie oluşturur
- **Öğretilen kavramlar:** Stack vs Heap bellek yönetimi, constructor/destructor
- **Örnek:**
  ```bash
  ./BraiiiiiiinnnzzzZ
  # Çıktı:
  # ----->> Stack Memory <<-----
  # Necmettin: BraiiiiiiinnnzzzZ...
  # Husamettin: BraiiiiiiinnnzzzZ...
  # Husamettin died!
  # ----->> Heap Memory <<-----
  # Fahriye: BraiiiiiiinnnzzzZ...
  # Fahriye died!
  # Necmettin died!
  ```

### ex01 - Moar brainz!
**Dosyalar:** `ex01/Zombie.hpp`, `ex01/Zombie.cpp`, `ex01/zombieHorde.cpp`, `ex01/main.cpp`, `ex01/Makefile`

Zombie arraylerinin dinamik olarak oluşturulması ve yönetimi.
- **Program:** `Moarbrainz`
- **Sınıf:** `Zombie` (genişletilmiş versiyon)
- **Yeni özellikler:**
  - `Zombie(void)` - Default constructor
  - `void setName(std::string name)` - İsim setter
- **Ana fonksiyon:** `Zombie* zombieHorde(int N, std::string name)`
- **Açıklama:** N adet zombie'den oluşan bir array oluşturur ve hepsine aynı ismi verir
- **Öğretilen kavramlar:** Dinamik array allocation, default constructor, object initialization
- **Örnek:**
  ```bash
  ./Moarbrainz
  # Çıktı:
  # Loream Ipsum: BraiiiiiiinnnzzzZ...
  # Loream Ipsum: BraiiiiiiinnnzzzZ...
  # ... (10 kez)
  # Loream Ipsum died!
  # ... (10 kez)
  ```

### ex02 - HI THIS IS BRAIN
**Dosyalar:** `ex02/main.cpp`, `ex02/Makefile`

Referans ve işaretçi kavramlarının temel implementasyonu.
- **Program:** `HITHISISBRAIN`
- **Değişkenler:**
  - `std::string str` - Orijinal string
  - `std::string *stringPTR` - String pointer
  - `std::string &stringREF` - String reference
- **Çıktılar:**
  - Değişkenlerin bellek adresleri
  - Değişkenlerin değerleri
- **Öğretilen kavramlar:** Pointer vs Reference, memory addressing, dereferencing
- **Örnek:**
  ```bash
  ./HITHISISBRAIN
  # Çıktı:
  # 0x7fff5fbff5d0
  # 0x7fff5fbff5d0
  # 0x7fff5fbff5d0
  # HI THIS IS BRAIN
  # HI THIS IS BRAIN
  # HI THIS IS BRAIN
  ```

### ex03 - Unnecessary violence
**Dosyalar:** `ex03/Weapon.hpp`, `ex03/Weapon.cpp`, `ex03/HumanA.hpp`, `ex03/HumanA.cpp`, `ex03/HumanB.hpp`, `ex03/HumanB.cpp`, `ex03/main.cpp`, `ex03/Makefile`

Referans ve işaretçi kullanımının pratik uygulaması - savaşçı ve silah sistemi.
- **Program:** `GereksizSiddet`
- **Weapon Sınıfı:**
  - `Weapon(std::string type)` - Constructor
  - `const std::string &getType()` - Getter (reference döndürür)
  - `void setType(std::string type)` - Setter
- **HumanA Sınıfı:**
  - Constructor'da weapon reference alır (her zaman silahlı)
  - `void attack(void)` - Saldırı fonksiyonu
- **HumanB Sınıfı:**
  - Constructor'da weapon almaz (başlangıçta silahsız olabilir)
  - `void setWeapon(Weapon &weapon)` - Sonradan silah set etme
  - `void attack(void)` - Saldırı fonksiyonu
- **Öğretilen kavramlar:** Reference vs Pointer kullanım senaryoları, object composition
- **Örnek:**
  ```bash
  ./GereksizSiddet
  # Çıktı:
  # Bob attacks with their crude spiked club
  # Bob attacks with their some other type of club
  # Jim attacks with their crude spiked club
  # Jim attacks with their some other type of club
  ```

### ex04 - Sed is for losers
**Dosyalar:** `ex04/main.cpp`, `ex04/Makefile`

Dosya işlemleri ve string replacement uygulaması.
- **Program:** `UzulmekKaybedenlerIcindir`
- **Parametreler:** 
  - `filename` - İşlenecek dosya
  - `s1` - Aranacak string
  - `s2` - Yerine konacak string
- **İşlev:** Dosyadaki tüm s1 stringlerini s2 ile değiştirir
- **Çıktı:** `filename.replace` dosyası oluşturur
- **Kullanılan fonksiyonlar:**
  - `std::ifstream/std::ofstream` - Dosya stream'leri
  - `std::string::find()` - String arama
  - `std::string::substr()` - String kesme
- **Öğretilen kavramlar:** File I/O, string manipulation, command line arguments
- **Örnek:**
  ```bash
  echo "Hello world, hello C++" > test.txt
  ./UzulmekKaybedenlerIcindir test.txt "hello" "hi"
  cat test.txt.replace
  # Çıktı: Hello world, hi C++
  ```

### ex05 - Harl 2.0
**Dosyalar:** `ex05/Harl.hpp`, `ex05/Harl.cpp`, `ex05/main.cpp`, `ex05/Makefile`

Member function pointer'ları kullanarak log level sistemi.
- **Program:** `Harl2.0`
- **Harl Sınıfı:**
  - `void (Harl::*functions[4])(void)` - Function pointer array
  - `std::string arr[4]` - Level isimleri
  - Private metodlar: `debug()`, `info()`, `warning()`, `error()`
  - `void complain(std::string level)` - Ana complaint fonksiyonu
- **Log Levels:**
  - **DEBUG:** "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum..."
  - **INFO:** "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum..."
  - **WARNING:** "Bence bedavaya fazladan pastırma yemeyi hak ediyorum..."
  - **ERROR:** "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum."
- **Öğretilen kavramlar:** Member function pointers, array of function pointers
- **Örnek:**
  ```bash
  ./Harl2.0
  # Çıktı: Tüm log level'ları sırasıyla
  ```

### ex06 - Harl filter
**Dosyalar:** `ex06/Harl.hpp`, `ex06/Harl.cpp`, `ex06/main.cpp`, `ex06/Makefile`

Switch-case yapısı kullanarak log level filtreleme sistemi.
- **Program:** `harlFilter`
- **Harl Sınıfı:** ex05'teki sınıfın genişletilmiş versiyonu
- **Yeni özellik:** `std::string getStr(int index)` - Array elemanlarına erişim
- **Ana özellik:** Verilen level'dan başlayarak tüm üst level'ları gösterir
- **Switch-case fallthrough:** Break statement'lar olmadan cascading behavior
- **Öğretilen kavramlar:** Switch-case fallthrough, command line argument validation
- **Örnek:**
  ```bash
  ./harlFilter DEBUG
  # Çıktı:
  # [DEBUG]
  # 7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime...
  # [INFO]
  # Ekstra domuz pastırması eklemenin daha fazla paraya...
  # [WARNING]
  # Bence bedavaya fazladan pastırma yemeyi hak ediyorum...
  # [ERROR]
  # Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum.
  
  ./harlFilter WARNING
  # Çıktı: WARNING ve ERROR level'ları
  
  ./harlFilter INVALID
  # Çıktı: [ Probably complaining about insignificant problems ]
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
# ex00 - BraiiiiiiinnnzzzZ
cd ex00
make
./BraiiiiiiinnnzzzZ

# ex01 - Moar brainz!
cd ex01
make
./Moarbrainz

# ex02 - HI THIS IS BRAIN
cd ex02
make
./HITHISISBRAIN

# ex03 - Unnecessary violence
cd ex03
make
./GereksizSiddet

# ex04 - Sed is for losers
cd ex04
make
./UzulmekKaybedenlerIcindir filename "old" "new"

# ex05 - Harl 2.0
cd ex05
make
./Harl2.0

# ex06 - Harl filter
cd ex06
make
./harlFilter DEBUG
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Çalıştırılabilir dosyayı sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **Bellek Yönetimi**: Stack vs Heap allocation, new/delete operatörleri
2. **Class Design**: Constructor/Destructor, member functions, encapsulation
3. **Referanslar ve İşaretçiler**: Pointer vs Reference kullanım senaryoları
4. **Dinamik Bellek**: Array allocation/deallocation, memory leaks prevention
5. **Dosya İşlemleri**: ifstream/ofstream, file error handling
6. **String Manipülasyonu**: find, substr, replace operations
7. **Function Pointers**: Member function pointers, function pointer arrays
8. **Switch-Case**: Fallthrough behavior, control flow
9. **Object Composition**: Class'ların birbirleriyle etkileşimi
10. **RAII Prensibi**: Resource Acquisition Is Initialization

## 📋 C++ Standartları ve Kurallar

Tüm projeler aşağıdaki bayraklarla derlenir:
```bash
-Wall -Wextra -Werror -std=c++98
```

- **-Wall**: Tüm uyarıları etkinleştirir
- **-Wextra**: Ekstra uyarıları etkinleştirir  
- **-Werror**: Uyarıları hata olarak ele alır
- **-std=c++98**: C++98 standardını kullanır
- **Orthodox Canonical Form**: Copy constructor, assignment operator, destructor
- **RAII Prensibi**: Resource Acquisition Is Initialization
- **Header Guards**: `#ifndef` kullanımı ile multiple inclusion engellenmiş
- **Coding Style**: 42 School norminette kuralları

## � Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- Memory leak'ler önlenmiş, her `new` için karşılık bir `delete` bulunmaktadır
- Orthodox Canonical Form kuralları takip edilmiştir
- Const correctness prensipleri uygulanmıştır
- Header guard'lar kullanılarak multiple inclusion engellenmiştir
- Exception handling henüz kapsamda değildir
- STL container'ları bu modülde kullanılmamaktadır

## 🔍 Test Senaryoları

### ex00 Test
```bash
./BraiiiiiiinnnzzzZ
# Stack ve Heap bellek yönetiminin doğru çalışması
# Destructor'ların doğru sırada çağrılması
```

### ex01 Test
```bash
./Moarbrainz
# 10 zombie'nin oluşturulması ve isimlenmesi
# Array'in doğru şekilde silinmesi (delete[])
```

### ex02 Test
```bash
./HITHISISBRAIN
# Pointer ve reference'ın aynı adresi göstermesi
# Değerlerin aynı olması
```

### ex03 Test
```bash
./GereksizSiddet
# HumanA'nın her zaman silahlı olması
# HumanB'nin silahsız başlayıp sonradan silahlanması
# Weapon değişikliklerinin yansıması
```

### ex04 Test
```bash
echo "Hello world hello" > test.txt
./UzulmekKaybedenlerIcindir test.txt "hello" "hi"
cat test.txt.replace
# Çıktı: "Hello world hi"
```

### ex05 Test
```bash
./Harl2.0
# Tüm log level'larının çalışması
# Function pointer array'inin doğru çalışması
```

### ex06 Test
```bash
./harlFilter DEBUG      # Tüm level'lar
./harlFilter WARNING    # WARNING ve ERROR
./harlFilter INVALID    # Default mesaj
```
