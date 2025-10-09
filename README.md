# 42 Kocaeli C++ Module 03
## Inheritance (Kalıtım)

Bu proje, 42 Okulu C++ eğitiminin üçüncü modülüdür. C++ programlama dilinde kalıtım (inheritance), polimorfizm, sanal kalıtım (virtual inheritance) ve çoklu kalıtım (multiple inheritance) kavramlarını öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Aaaaand... OPEN!
**Dosyalar:** `ex00/ClapTrap.hpp`, `ex00/ClapTrap.cpp`, `ex00/main.cpp`, `ex00/Makefile`

Temel robot sınıfı ClapTrap'in tanımlanması.
- **Program:** `AaaaandOPEN`
- **Sınıf:** `ClapTrap`
- **Özellikler:**
  - İsim (name)
  - Can puanları (hit_points): 10
  - Enerji puanları (energy_points): 10  
  - Saldırı hasarı (attack_damage): 0
- **Fonksiyonlar:**
  - `attack(const std::string& target)` - Saldırı gerçekleştir
  - `takeDamage(unsigned int amount)` - Hasar al
  - `beRepaired(unsigned int amount)` - Kendini onar
- **Örnek:**
  ```bash
  ./AaaaandOPEN
  # Çıktı:
  # Name Constructor called
  # ClapTrap John Doe attacks Chuck Norris, causing 0 points of damage!
  # ClapTrap Chuck Norris takes 0 points of damage!
  # ClapTrap Chuck Norris takes 10 points of damage!
  # ClapTrap Chuck Norris can't attack Me because it runs out of energy points
  ```

### ex01 - Serena, my love!
**Dosyalar:** `ex01/ClapTrap.hpp`, `ex01/ClapTrap.cpp`, `ex01/ScavTrap.hpp`, `ex01/ScavTrap.cpp`, `ex01/main.cpp`, `ex01/Makefile`

ClapTrap'ten türetilen ScavTrap sınıfı - kalıtımın temel uygulaması.
- **Program:** `SerenaMyLove`
- **Sınıflar:** `ClapTrap` (base), `ScavTrap` (derived)
- **ScavTrap Özellikleri:**
  - Can puanları (hit_points): 100
  - Enerji puanları (energy_points): 50
  - Saldırı hasarı (attack_damage): 20
- **Yeni Fonksiyon:**
  - `guardGate()` - Kapı bekçisi modunu aktifleştir
- **Kalıtım Özellikleri:**
  - `public` kalıtım kullanılır
  - `protected` üye değişkenler alt sınıftan erişilebilir
  - Sanal yıkıcı (virtual destructor) kullanımı
- **Örnek:**
  ```bash
  ./SerenaMyLove
  # Çıktı:
  # ClapTrap Name Constructor called
  # ScavTrap Name Constructor called
  # ScavTrap John Doe attacks Chuck Norris, causing 20 points of damage!
  # ScavTrap Chuck Norris activate gate keeper mode
  ```

### ex02 - Repetitive work
**Dosyalar:** `ex02/ClapTrap.hpp`, `ex02/ClapTrap.cpp`, `ex02/ScavTrap.hpp`, `ex02/ScavTrap.cpp`, `ex02/FragTrap.hpp`, `ex02/FragTrap.cpp`, `ex02/main.cpp`, `ex02/Makefile`

ClapTrap'ten türetilen FragTrap sınıfı - farklı özelliklerle kalıtım.
- **Program:** `RepetitiveWork`
- **Sınıflar:** `ClapTrap` (base), `ScavTrap`, `FragTrap` (derived)
- **FragTrap Özellikleri:**
  - Can puanları (hit_points): 100
  - Enerji puanları (energy_points): 100
  - Saldırı hasarı (attack_damage): 30
- **Yeni Fonksiyon:**
  - `highFivesGuys()` - Pozitif bir çınlama isteği
- **Polimorfizm:** Her alt sınıf farklı değerlerle başlatılır
- **Örnek:**
  ```bash
  ./RepetitiveWork
  # Çıktı:
  # ClapTrap Name Constructor called
  # FragTrap Name Constructor called
  # FragTrap John Doe attacks Chuck Norris, causing 30 points of damage!
  # FragTrap Enes say high fives guys
  ```

### ex03 - Now it's weird!
**Dosyalar:** `ex03/ClapTrap.hpp`, `ex03/ClapTrap.cpp`, `ex03/ScavTrap.hpp`, `ex03/ScavTrap.cpp`, `ex03/FragTrap.hpp`, `ex03/FragTrap.cpp`, `ex03/DiamondTrap.hpp`, `ex03/DiamondTrap.cpp`, `ex03/main.cpp`, `ex03/Makefile`

Çoklu kalıtım ve sanal kalıtım - Diamond Problem çözümü.
- **Program:** `NowItSWeird`
- **Sınıflar:** `ClapTrap` (base), `ScavTrap`, `FragTrap` (virtual base), `DiamondTrap` (multiple inheritance)
- **DiamondTrap Özellikleri:**
  - `ScavTrap` ve `FragTrap`'ten çoklu kalıtım
  - `virtual` kalıtım ile Diamond Problem çözümü
  - Özel isim (private name) ve ClapTrap ismi ayrımı
  - Can puanları: FragTrap'ten (100)
  - Enerji puanları: ScavTrap'ten (50)
  - Saldırı hasarı: FragTrap'ten (30)
- **Yeni Fonksiyonlar:**
  - `whoAmI()` - İsim bilgilerini göster
  - `attack()` - ScavTrap'in attack fonksiyonunu kullan
- **Sanal Kalıtım:**
  - `virtual public ClapTrap` ScavTrap ve FragTrap'te
  - Diamond Problem'in önlenmesi
- **Örnek:**
  ```bash
  ./NowItSWeird
  # Çıktı:
  # ClapTrap Name Constructor called
  # ScavTrap Name Constructor called
  # FragTrap Name Constructor called
  # DiamondTrap Name Constructor called
  # Name : John Doe, ClapTrap Name : John Doe_clap_name
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
# ex00 - ClapTrap
cd ex00
make
./AaaaandOPEN

# ex01 - ScavTrap
cd ex01
make
./SerenaMyLove

# ex02 - FragTrap
cd ex02
make
./RepetitiveWork

# ex03 - DiamondTrap
cd ex03
make
./NowItSWeird
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Çalıştırılabilir dosyayı sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **Kalıtım (Inheritance)**: Sınıflar arası parent-child ilişkisi
2. **Public Inheritance**: `public` erişim belirleyicisi ile kalıtım
3. **Protected Members**: Alt sınıflardan erişilebilen üye değişkenler
4. **Constructor/Destructor Chain**: Kalıtımda constructor/destructor sırası
5. **Function Overriding**: Alt sınıflarda fonksiyonları yeniden tanımlama
6. **Virtual Inheritance**: `virtual` kalıtım ile Diamond Problem çözümü
7. **Multiple Inheritance**: Birden fazla sınıftan kalıtım
8. **Diamond Problem**: Çoklu kalıtımda oluşan sorun ve çözümü
9. **Scope Resolution**: `::` operatörü ile kapsam belirtme
10. **Orthodox Canonical Form**: Kalıtımlı sınıflarda canonical form

## 📋 C++ Standartları ve Kurallar

- **C++98 Standardı**: Projede kullanılan C++ versiyonu
- **Derleme Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Inheritance Best Practices**: Sanal yıkıcı kullanımı
- **Virtual Inheritance**: Diamond Problem çözümü
- **Constructor Initialization List**: Doğru initialization sırası
- **RAII Prensibi**: Resource management in inheritance
- **Polymorphism**: Sanal fonksiyonlar ve çok biçimlilik

## 🔍 Test Senaryoları

### ex00 Test
```bash
./AaaaandOPEN
# ClapTrap temel fonksiyonları:
# - attack() enerji harcaması
# - takeDamage() hasar alma
# - beRepaired() onarım yapma
# - Enerji bitince eylem yapamama
```

### ex01 Test
```bash
./SerenaMyLove
# ScavTrap kalıtım testi:
# - Constructor chain (ClapTrap -> ScavTrap)
# - Destructor chain (ScavTrap -> ClapTrap)
# - guardGate() özel fonksiyon
# - Farklı başlangıç değerleri
```

### ex02 Test
```bash
./RepetitiveWork
# FragTrap kalıtım testi:
# - Constructor/destructor chain
# - highFivesGuys() özel fonksiyon
# - ScavTrap ve FragTrap birlikte kullanım
# - Farklı stat değerleri
```

### ex03 Test
```bash
./NowItSWeird
# DiamondTrap çoklu kalıtım testi:
# - Virtual inheritance doğruluğu
# - whoAmI() isim ayrımı
# - ScavTrap::attack() kullanımı
# - Diamond Problem çözümü
# - Constructor/destructor chain karmaşıklığı
```

## 📝 Önemli Notlar

### Kalıtım Hiyerarşisi
```
ClapTrap (base class)
├── ScavTrap (derived)
├── FragTrap (derived)
└── DiamondTrap (multiple inheritance)
    ├── ScavTrap (virtual base)
    └── FragTrap (virtual base)
```

### Stat Değerleri Karşılaştırması
| Sınıf | Hit Points | Energy Points | Attack Damage |
|-------|------------|---------------|---------------|
| ClapTrap (ex00) | 10 | 10 | 0 |
| ScavTrap | 100 | 50 | 20 |
| FragTrap | 100 | 100 | 30 |
| DiamondTrap | 100 (Frag) | 50 (Scav) | 30 (Frag) |

### Constructor/Destructor Sırası
- **Construction**: Base -> Derived (ClapTrap -> ScavTrap/FragTrap -> DiamondTrap)
- **Destruction**: Derived -> Base (DiamondTrap -> ScavTrap/FragTrap -> ClapTrap)

### Diamond Problem Çözümü
```cpp
// ex03'te virtual inheritance kullanımı
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
class DiamondTrap : public ScavTrap, public FragTrap { ... };
```

## 🚀 İleri Düzey Konular

1. **Virtual Functions**: Sanal fonksiyonlar ve late binding
2. **Abstract Classes**: Saf sanal fonksiyonlar
3. **Interface Design**: Arayüz tasarım prensipleri
4. **SOLID Principles**: Kalıtım ve tasarım prensipleri
5. **Template Inheritance**: Şablon kalıtımı
6. **Multiple Virtual Inheritance**: Karmaşık kalıtım yapıları

Bu proje, C++ kalıtım sisteminin temellerini ve karmaşık inheritance senaryolarını anlamak için kapsamlı bir deneyim sağlar.
