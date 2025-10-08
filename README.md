# 42 Kocaeli C++ Module 01
## Memory Management and Class Basics (Bellek Yönetimi ve Sınıf Temelleri)

Bu proje, 42 Okulu C++ eğitiminin birinci modülüdür. C++ programlama dilinde bellek yönetimi, sınıf tasarımı, referanslar ve işaretçiler, dosya işlemleri ve string manipülasyonu konularında temel bilgi ve becerileri geliştirmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - BraiiiiiiinnnzzzZ
**Dosyalar:** `ex00/Zombie.hpp`, `ex00/Zombie.cpp`, `ex00/newZombie.cpp`, `ex00/randomChump.cpp`, `ex00/main.cpp`

Stack ve Heap bellek yönetimini öğreten temel Zombie sınıfı implementasyonu.
- **Sınıf:** `Zombie`
- **Üye fonksiyonlar:** 
  - `Zombie(std::string name)` - Constructor
  - `~Zombie(void)` - Destructor
  - `void announce(void)` - Zombie'nin konuşma fonksiyonu
- **Yardımcı fonksiyonlar:**
  - `Zombie* newZombie(std::string name)` - Heap'te zombie oluşturur
  - `void randomChump(std::string name)` - Stack'te zombie oluşturur
- **Öğretilen kavramlar:** Stack vs Heap bellek yönetimi, constructor/destructor
- **Çıktı örneği:**
  ```
  ----->> Stack Memory <<-----
  Necmettin: BraiiiiiiinnnzzzZ...
  Husamettin: BraiiiiiiinnnzzzZ...
  Husamettin died!
  ----->> Heap Memory <<-----
  Fahriye: BraiiiiiiinnnzzzZ...
  Fahriye died!
  Necmettin died!
  ```

### ex01 - Moar brainz!
**Dosyalar:** `ex01/Zombie.hpp`, `ex01/Zombie.cpp`, `ex01/zombieHorde.cpp`, `ex01/main.cpp`

Zombie arraylerinin dinamik olarak oluşturulması ve yönetimi.
- **Sınıf:** `Zombie` (genişletilmiş versiyon)
- **Yeni özellikler:**
  - `Zombie(void)` - Default constructor
  - `void setName(std::string name)` - İsim setter
- **Ana fonksiyon:** `Zombie* zombieHorde(int N, std::string name)`
- **Açıklama:** N adet zombie'den oluşan bir array oluşturur ve hepsine aynı ismi verir
- **Öğretilen kavramlar:** Dinamik array allocation, default constructor, object initialization
- **Örnek kullanım:**
  ```cpp
  Zombie* zombies = zombieHorde(10, "Loream Ipsum");
  for (int i = 0; i < 10; i++)
      zombies[i].announce();
  delete[] zombies;
  ```

### ex02 - HI THIS IS BRAIN
**Dosyalar:** `ex02/main.cpp`

Referans ve işaretçi kavramlarının temel implementasyonu.
- **Değişkenler:**
  - `std::string str` - Orijinal string
  - `std::string *stringPTR` - String pointer
  - `std::string &stringREF` - String reference
- **Çıktılar:**
  - Değişkenlerin bellek adresleri
  - Değişkenlerin değerleri
- **Öğretilen kavramlar:** Pointer vs Reference, memory addressing, dereferencing
- **Çıktı örneği:**
  ```
  0x7fff5fbff5d0
  0x7fff5fbff5d0
  0x7fff5fbff5d0
  HI THIS IS BRAIN
  HI THIS IS BRAIN
  HI THIS IS BRAIN
  ```

### ex03 - Unnecessary violence
**Dosyalar:** `ex03/Weapon.hpp`, `ex03/Weapon.cpp`, `ex03/HumanA.hpp`, `ex03/HumanA.cpp`, `ex03/HumanB.hpp`, `ex03/HumanB.cpp`, `ex03/main.cpp`

Referans ve işaretçi kullanımının pratik uygulaması - savaşçı ve silah sistemi.
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
- **Çıktı örneği:**
  ```
  Bob attacks with their crude spiked club
  Bob attacks with their some other type of club
  Jim attacks with their crude spiked club
  Jim attacks with their some other type of club
  ```

### ex04 - Sed is for losers
**Dosyalar:** `ex04/main.cpp`

Dosya işlemleri ve string replacement uygulaması.
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
- **Kullanım:**
  ```bash
  ./UzulmekKaybedenlerIcindir filename "old_text" "new_text"
  ```

### ex05 - Harl 2.0
**Dosyalar:** `ex05/Harl.hpp`, `ex05/Harl.cpp`, `ex05/main.cpp`

Member function pointer'ları kullanarak log level sistemi.
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

### ex06 - Harl filter
**Dosyalar:** `ex06/Harl.hpp`, `ex06/Harl.cpp`, `ex06/main.cpp`

Switch-case yapısı kullanarak log level filtreleme sistemi.
- **Harl Sınıfı:** ex05'teki sınıfın genişletilmiş versiyonu
- **Yeni özellik:** `std::string getStr(int index)` - Array elemanlarına erişim
- **Ana özellik:** Verilen level'dan başlayarak tüm üst level'ları gösterir
- **Switch-case fallthrough:** Break statement'lar olmadan cascading behavior
- **Öğretilen kavramlar:** Switch-case fallthrough, command line argument validation
- **Kullanım:**
  ```bash
  ./harlFilter DEBUG    # Tüm level'ları gösterir
  ./harlFilter WARNING  # WARNING ve ERROR'ı gösterir
  ./harlFilter INVALID  # "Probably complaining about insignificant problems"
  ```
- **Çıktı formatı:**
  ```
  [DEBUG]
  7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime...
  [INFO]
  Ekstra domuz pastırması eklemenin daha fazla paraya...
  [WARNING]
  Bence bedavaya fazladan pastırma yemeyi hak ediyorum...
  [ERROR]
  Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum.
  ```

## 🔧 Kullanım

### C++ Derleyici Gereksinimleri
```bash
# GNU Compiler Collection
sudo apt-get install g++

# Clang (alternatif)
sudo apt-get install clang++

# macOS (Xcode Command Line Tools)
xcode-select --install
```

### Derleme ve Çalıştırma
```bash
# Her egzersiz için
cd ex00/
make
./BraiiiiiiinnnzzzZ

cd ../ex01/
make
./Moarbrainz

cd ../ex02/
make
./HITHISISBRAIN

cd ../ex03/
make
./GereksizSiddet

cd ../ex04/
make
./UzulmekKaybedenlerIcindir filename "old" "new"

cd ../ex05/
make
./Harl2.0

cd ../ex06/
make
./harlFilter DEBUG
```

### Makefile Komutları
```bash
make        # Derleme
make clean  # Executable'ı temizle
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

## 📋 Compilation Flags

Tüm projeler aşağıdaki bayraklarla derlenir:
```bash
-Wall -Wextra -Werror -std=c++98
```

- **-Wall**: Tüm uyarıları etkinleştirir
- **-Wextra**: Ekstra uyarıları etkinleştirir  
- **-Werror**: Uyarıları hata olarak ele alır
- **-std=c++98**: C++98 standardını kullanır

## 📋 Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- Memory leak'ler önlenmiş, her `new` için karşılık bir `delete` bulunmaktadır
- Orthodox Canonical Form kuralları takip edilmiştir
- Const correctness prensipleri uygulanmıştır
- Header guard'lar kullanılarak multiple inclusion engellenmiştir

## 🔍 Test Önerileri

```bash
# Valgrind ile memory leak testi
valgrind --leak-check=full ./program_name

# CPP Check ile static analysis
cppcheck --enable=all *.cpp

# Address Sanitizer ile runtime checks
g++ -fsanitize=address -g *.cpp -o program
```
