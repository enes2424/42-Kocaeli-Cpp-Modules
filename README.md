# 42 Kocaeli C++ Module 03
## Inheritance (Kalıtım)

Bu proje, 42 Okulu C++ eğitiminin üçüncü modülüdür. C++ programlama dilinde kalıtım (inheritance), polimorfizm, çoklu kalıtım ve diamond problem kavramlarını öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Aaaaand... OPEN!
**Dosyalar:** `ex00/ClapTrap.cpp`, `ex00/ClapTrap.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Temel ClapTrap sınıfının implementasyonu.
- **Program:** `AaaaandOPEN`
- **Sınıf:** `ClapTrap`
- **Özellikler:**
  - Name (isim)
  - Hit points (10) - can puanı
  - Energy points (10) - enerji puanı  
  - Attack damage (0) - saldırı hasarı
- **Fonksiyonlar:**
  - `attack(const std::string& target)` - saldırı yapar
  - `takeDamage(unsigned int amount)` - hasar alır
  - `beRepaired(unsigned int amount)` - kendini tamir eder
- **Örnek:**
  ```cpp
  ClapTrap john("John Doe");
  ClapTrap chuck("Chuck Norris");
  
  john.attack("Chuck Norris");        // John saldırır
  chuck.takeDamage(0);               // Chuck 0 hasar alır
  chuck.beRepaired(2);               // Chuck kendini tamir eder
  ```

### ex01 - Serena, my love!
**Dosyalar:** `ex01/ClapTrap.cpp`, `ex01/ClapTrap.hpp`, `ex01/ScavTrap.cpp`, `ex01/ScavTrap.hpp`, `ex01/main.cpp`, `ex01/Makefile`

ScavTrap sınıfı - ClapTrap'den kalıtım alan gelişmiş robot.
- **Program:** `SerenaMyLove`
- **Sınıflar:** `ClapTrap` (base), `ScavTrap` (derived)
- **ScavTrap Özellikleri:**
  - Hit points (100) - can puanı
  - Energy points (50) - enerji puanı
  - Attack damage (20) - saldırı hasarı
- **Yeni Fonksiyonlar:**
  - `guardGate()` - kapı bekçisi modunu aktive eder
  - `attack()` - override edilmiş saldırı fonksiyonu
- **Kalıtım Özellikleri:**
  - Public inheritance kullanımı
  - Constructor ve destructor zincirleme
  - Virtual olmayan fonksiyon override
- **Örnek:**
  ```cpp
  ScavTrap scav("Guardian");
  scav.attack("Enemy");              // ScavTrap saldırısı
  scav.guardGate();                  // Kapı bekçisi modu
  scav.takeDamage(30);               // Inherited fonksiyon
  ```

### ex02 - Repetitive work
**Dosyalar:** `ex02/ClapTrap.cpp`, `ex02/ClapTrap.hpp`, `ex02/ScavTrap.cpp`, `ex02/ScavTrap.hpp`, `ex02/FragTrap.cpp`, `ex02/FragTrap.hpp`, `ex02/main.cpp`, `ex02/Makefile`

FragTrap sınıfı - ClapTrap'den kalıtım alan başka bir robot türü.
- **Program:** `RepetitiveWork`
- **Sınıflar:** `ClapTrap` (base), `ScavTrap`, `FragTrap` (derived)
- **FragTrap Özellikleri:**
  - Hit points (100) - can puanı
  - Energy points (100) - enerji puanı
  - Attack damage (30) - saldırı hasarı
- **Yeni Fonksiyonlar:**
  - `highFivesGuys()` - yüksek beşleşme talebi
- **Kalıtım Hiyerarşisi:**
  - İki farklı türetilmiş sınıf
  - Aynı base class'tan farklı özellikler
  - Farklı başlangıç değerleri
- **Örnek:**
  ```cpp
  FragTrap frag("Friendly");
  ScavTrap scav("Guardian");
  
  frag.highFivesGuys();             // FragTrap özel fonksiyonu
  scav.guardGate();                 // ScavTrap özel fonksiyonu
  frag.attack("target");            // Inherited attack
  ```

### ex03 - Now it's weird!
**Dosyalar:** `ex03/ClapTrap.cpp`, `ex03/ClapTrap.hpp`, `ex03/ScavTrap.cpp`, `ex03/ScavTrap.hpp`, `ex03/FragTrap.cpp`, `ex03/FragTrap.hpp`, `ex03/DiamondTrap.cpp`, `ex03/DiamondTrap.hpp`, `ex03/main.cpp`, `ex03/Makefile`

DiamondTrap sınıfı - Çoklu kalıtım ve Diamond Problem çözümü.
- **Program:** `NowItSWeird`
- **Sınıflar:** `ClapTrap` (base), `ScavTrap`, `FragTrap`, `DiamondTrap` (multiple inheritance)
- **DiamondTrap Özellikleri:**
  - Hit points: FragTrap'den (100)
  - Energy points: ScavTrap'den (50)
  - Attack damage: FragTrap'den (30)
  - Private name + ClapTrap name (_clap_name suffix)
- **Çoklu Kalıtım:**
  - `public ScavTrap, public FragTrap`
  - Diamond inheritance pattern
  - Virtual inheritance kullanımı
- **Yeni Fonksiyonlar:**
  - `whoAmI()` - kimlik bilgilerini gösterir
  - `attack()` - ScavTrap'in attack fonksiyonunu kullanır
- **Diamond Problem Çözümü:**
  - Virtual inheritance ile ambiguity çözümü
  - Constructor initialization list
  - Attribute inheritance seçimi
- **Örnek:**
  ```cpp
  DiamondTrap diamond("Hybrid");
  diamond.whoAmI();                 // İsim ve ClapTrap ismini gösterir
  diamond.attack("enemy");          // ScavTrap attack
  diamond.guardGate();              // ScavTrap fonksiyonu
  diamond.highFivesGuys();          // FragTrap fonksiyonu
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

1. **Inheritance (Kalıtım)**: Base ve derived class ilişkileri
2. **Public Inheritance**: Is-a ilişkisi ve interface inheritance
3. **Protected Members**: Kalıtım için özel erişim seviyesi
4. **Constructor/Destructor Chaining**: Kalıtım zincirinde nesne yaşam döngüsü
5. **Function Overriding**: Türetilmiş sınıflarda fonksiyon yeniden tanımlama
6. **Multiple Inheritance**: Birden fazla base class'tan kalıtım
7. **Diamond Problem**: Çoklu kalıtımda ambiguity sorunu
8. **Virtual Inheritance**: Diamond problem çözümü
9. **Member Initialization List**: Constructor'da üye başlatma
10. **Scope Resolution Operator**: `::` ile ambiguity çözümü

## 📋 C++ Kalıtım Kuralları ve Prensipler

- **C++98 Standardı**: Projede kullanılan C++ versiyonu
- **Derleme Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Orthodox Canonical Form**: Her sınıf için tam constructor set
- **RAII Prensibi**: Resource Acquisition Is Initialization
- **Protected Access**: Kalıtım için uygun erişim seviyesi
- **Constructor Order**: Base class constructor'ı önce çağrılır
- **Destructor Order**: Derived class destructor'ı önce çağrılır
- **Virtual Inheritance**: Diamond problem için çözüm

## 🔍 Test Senaryoları

### ex00 Test
```bash
./AaaaandOPEN
# ClapTrap nesnelerinin oluşturulması
# Saldırı, hasar alma ve tamir fonksiyonları
# Energy points tükenmesi durumu
# Copy constructor ve assignment operator
```

### ex01 Test  
```bash
./SerenaMyLove
# ScavTrap nesnelerinin oluşturulması
# Kalıtım zincirine göre constructor/destructor çağrıları
# guardGate() özel fonksiyonunun çalışması
# Override edilmiş attack() fonksiyonunun kullanımı
```

### ex02 Test
```bash
./RepetitiveWork
# FragTrap ve ScavTrap nesnelerinin oluşturulması
# İki farklı derived class'ın aynı anda kullanımı
# highFivesGuys() özel fonksiyonunun çalışması
# Farklı başlangıç değerlerinin kontrolü
```

### ex03 Test
```bash
./NowItSWeird
# DiamondTrap çoklu kalıtım yapısının çalışması
# whoAmI() fonksiyonuyla kimlik kontrolü
# Her iki parent class fonksiyonlarına erişim
# Diamond inheritance'ın doğru çalışması
# Constructor/destructor çağırma sırası
```

## 📊 Sınıf Hiyerarşisi

```
ClapTrap (Base Class)
├── ScavTrap (Public Inheritance)
├── FragTrap (Public Inheritance)
└── DiamondTrap (Multiple Inheritance)
    ├── ScavTrap (Virtual Inheritance)
    └── FragTrap (Virtual Inheritance)
```

## 📝 Sınıf Özellikleri Tablosu

| Sınıf | Hit Points | Energy Points | Attack Damage | Özel Fonksiyonlar |
|-------|------------|---------------|---------------|-------------------|
| ClapTrap | 10 | 10 | 0 | attack, takeDamage, beRepaired |
| ScavTrap | 100 | 50 | 20 | guardGate, attack (override) |
| FragTrap | 100 | 100 | 30 | highFivesGuys |
| DiamondTrap | 100 (FragTrap) | 50 (ScavTrap) | 30 (FragTrap) | whoAmI, attack (ScavTrap) |

## 🎓 Diamond Problem Çözümü

DiamondTrap sınıfında karşılaşılan Diamond Problem:

```cpp
    ClapTrap
   /        \
ScavTrap   FragTrap
   \        /
   DiamondTrap
```

**Sorun:** DiamondTrap, ClapTrap'e iki farklı yoldan erişiyor.
**Çözüm:** Virtual inheritance kullanarak tek bir ClapTrap instance'ı sağlamak.

```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
class DiamondTrap : public ScavTrap, public FragTrap { ... };
```

## 🔧 Constructor/Destructor Sırası

### Oluşturma Sırası (Construction):
1. ClapTrap constructor
2. ScavTrap constructor  
3. FragTrap constructor
4. DiamondTrap constructor

### Yok Etme Sırası (Destruction):
1. DiamondTrap destructor
2. FragTrap destructor
3. ScavTrap destructor
4. ClapTrap destructor

## 📝 Notlar

- Tüm kod C++98 standardına uygun yazılmıştır
- Virtual inheritance diamond problem için kullanılmıştır
- Protected members kalıtım için uygun erişim sağlar
- Multiple inheritance dikkatli bir şekilde implement edilmiştir
- Function overriding ile polymorphic behavior sağlanmıştır
- Orthodox Canonical Form her sınıf için uygulanmıştır
- Memory management RAII prensiplerine göre yapılmıştır
- Constructor initialization list doğru sırayla kullanılmıştır
