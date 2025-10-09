# 42 Kocaeli C++ Module 04
## Subtype Polymorphism, Abstract Classes, Interfaces (Alt Tür Polimorfizm, Soyut Sınıflar, Arayüzler)

Bu proje, 42 Okulu C++ eğitiminin dördüncü modülüdür. Polimorfizm, sanal fonksiyonlar, soyut sınıflar, arayüzler ve derin kopyalama kavramlarını öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Polymorphism
**Dosyalar:** `ex00/Animal.hpp`, `ex00/Animal.cpp`, `ex00/Dog.hpp`, `ex00/Dog.cpp`, `ex00/Cat.hpp`, `ex00/Cat.cpp`, `ex00/WrongAnimal.hpp`, `ex00/WrongAnimal.cpp`, `ex00/WrongCat.hpp`, `ex00/WrongCat.cpp`, `ex00/main.cpp`, `ex00/Makefile`

Temel polimorfizm ve sanal fonksiyonlar.
- **Program:** `Polymorphism`
- **Sınıflar:** `Animal`, `Dog`, `Cat`, `WrongAnimal`, `WrongCat`
- **Özellikler:**
  - `Animal` sınıfı sanal `makeSound()` fonksiyonu içerir
  - `Dog` ve `Cat` sınıfları `Animal`'dan kalıtım alır
  - `WrongAnimal` ve `WrongCat` sanal fonksiyon kullanmaz (yanlış örnek)
  - Polimorfizmin doğru ve yanlış kullanımını gösterir
- **Çıktı Örneği:**
  ```bash
  ./Polymorphism
  # Çıktı:
  Dog
  Cat
  Cat meows
  Dog barks
  Animal makes a sound
  
  ~~~~WRONG~~~~
  
  WrongCat
  WrongAnimal makes a sound
  ```

### ex01 - I don't want to set the world on fire
**Dosyalar:** `ex01/Animal.hpp`, `ex01/Animal.cpp`, `ex01/Dog.hpp`, `ex01/Dog.cpp`, `ex01/Cat.hpp`, `ex01/Cat.cpp`, `ex01/Brain.hpp`, `ex01/Brain.cpp`, `ex01/WrongAnimal.hpp`, `ex01/WrongAnimal.cpp`, `ex01/WrongCat.hpp`, `ex01/WrongCat.cpp`, `ex01/main.cpp`, `ex01/Makefile`

Derin kopyalama ve bellek yönetimi.
- **Program:** `IDontWantToSetTheWorldOnFire`
- **Sınıflar:** `Animal`, `Dog`, `Cat`, `Brain`, `WrongAnimal`, `WrongCat`
- **Özellikler:**
  - `Brain` sınıfı 100 adet `std::string` içerir
  - `Dog` ve `Cat` sınıfları `Brain` pointer'ı içerir
  - Derin kopyalama (deep copy) implementasyonu
  - Dinamik bellek yönetimi
  - Hayvan dizisi oluşturma ve silme testi
- **Bellek Yönetimi:**
  - Constructor'da `new Brain()` ile bellek ayırma
  - Destructor'da `delete brain` ile bellek temizleme
  - Copy constructor ve assignment operator'da derin kopyalama
- **Test Senaryosu:**
  ```cpp
  Animal *animals[8];
  for (int i = 0; i < 4; i++)
      animals[i] = new Dog();
  for (int i = 4; i < 8; i++)
      animals[i] = new Cat();
  for (int i = 0; i < 8; i++)
      delete animals[i];
  ```

### ex02 - Abstract class
**Dosyalar:** `ex02/Animal.hpp`, `ex02/Animal.cpp`, `ex02/Dog.hpp`, `ex02/Dog.cpp`, `ex02/Cat.hpp`, `ex02/Cat.cpp`, `ex02/Brain.hpp`, `ex02/Brain.cpp`, `ex02/WrongAnimal.hpp`, `ex02/WrongAnimal.cpp`, `ex02/WrongCat.hpp`, `ex02/WrongCat.cpp`, `ex02/main.cpp`, `ex02/Makefile`

Soyut sınıflar ve saf sanal fonksiyonlar.
- **Program:** `IDontWantToSetTheWorldOnFire`
- **Sınıflar:** `Animal` (abstract), `Dog`, `Cat`, `Brain`, `WrongAnimal`, `WrongCat`
- **Özellikler:**
  - `Animal` sınıfı soyut (abstract) sınıf haline gelir
  - `makeSound()` fonksiyonu saf sanal (pure virtual) fonksiyon: `= 0`
  - `Animal` sınıfından doğrudan nesne oluşturulamaz
  - Sadece türetilmiş sınıflardan nesne oluşturulabilir
- **Soyut Sınıf Tanımı:**
  ```cpp
  class Animal {
      // ...
      virtual void makeSound(void) const = 0; // Pure virtual function
  };
  ```
- **Kullanım:**
  ```cpp
  // Animal meta = new Animal(); // Derleme hatası!
  const Animal* j = new Dog();    // Geçerli
  const Animal* i = new Cat();    // Geçerli
  ```

### ex03 - Interface & recap
**Dosyalar:** `ex03/AMateria.hpp`, `ex03/AMateria.cpp`, `ex03/Character.hpp`, `ex03/Character.cpp`, `ex03/Ice.hpp`, `ex03/Ice.cpp`, `ex03/Cure.hpp`, `ex03/Cure.cpp`, `ex03/MateriaSource.hpp`, `ex03/MateriaSource.cpp`, `ex03/main.cpp`, `ex03/Makefile`

Arayüzler (interfaces) ve materia sistemi implementasyonu.
- **Program:** `InterfaceAndrace`
- **Sınıflar:** `AMateria` (abstract), `Ice`, `Cure`, `Character`, `MateriaSource`
- **Arayüzler:** `ICharacter`, `IMateriaSource`
- **Özellikler:**
  - Materia tabanlı sihir sistemi
  - `AMateria` soyut sınıfı ve türetilmiş `Ice`, `Cure` sınıfları
  - `ICharacter` arayüzü ve `Character` implementasyonu
  - `IMateriaSource` arayüzü ve `MateriaSource` implementasyonu
  - 4 slotlı materia envanteri sistemi
  - Clone pattern implementasyonu
- **Materia Türleri:**
  - **Ice:** `* shoots an ice bolt at [target] *`
  - **Cure:** `* heals [target]'s wounds *`
- **Arayüz Örnekleri:**
  ```cpp
  class ICharacter {
      virtual ~ICharacter() {}
      virtual std::string const & getName() const = 0;
      virtual void equip(AMateria* m) = 0;
      virtual void unequip(int idx) = 0;
      virtual void use(int idx, ICharacter& target) = 0;
  };
  ```
- **Kullanım Örneği:**
  ```cpp
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  
  ICharacter* me = new Character("me");
  AMateria* tmp = src->createMateria("ice");
  me->equip(tmp);
  me->use(0, *bob); // Ice saldırısı
  ```

## 🔧 Kullanım

### Derleme ve Çalıştırma
```bash
# ex00 - Polymorphism
cd ex00
make
./Polymorphism

# ex01 - I don't want to set the world on fire
cd ex01
make
./IDontWantToSetTheWorldOnFire

# ex02 - Abstract class
cd ex02
make
./IDontWantToSetTheWorldOnFire

# ex03 - Interface & recap
cd ex03
make
./InterfaceAndrace
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Çalıştırılabilir dosyayı sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **Polimorfizm (Polymorphism)**: Aynı arayüzle farklı davranışlar
2. **Sanal Fonksiyonlar (Virtual Functions)**: Runtime'da çözümlenen fonksiyonlar
3. **Saf Sanal Fonksiyonlar (Pure Virtual Functions)**: `= 0` ile tanımlanan fonksiyonlar
4. **Soyut Sınıflar (Abstract Classes)**: En az bir saf sanal fonksiyonu olan sınıflar
5. **Arayüzler (Interfaces)**: Sadece saf sanal fonksiyonları olan sınıflar
6. **Derin Kopyalama (Deep Copy)**: Pointer'ların gösterdiği nesnelerin kopyalanması
7. **Sanal Destructor**: Polimorfik sınıflarda bellek sızıntısını önleme
8. **Clone Pattern**: Nesne kopyalama tasarım deseni
9. **Composition**: Sınıfların başka sınıfları içermesi
10. **Dynamic Binding**: Runtime'da fonksiyon bağlama

## 📋 C++ Polimorfizm Kuralları

### Virtual Functions
```cpp
class Base {
public:
    virtual void func() = 0;        // Pure virtual (saf sanal)
    virtual void func2() { ... }    // Virtual function
    virtual ~Base() { ... }         // Virtual destructor (önemli!)
};
```

### Abstract Classes
```cpp
class AbstractClass {
public:
    virtual void pureVirtualFunc() = 0;  // En az bir saf sanal fonksiyon
    void concreteFunc() { ... }          // Somut fonksiyon da olabilir
};
```

### Interface Design
```cpp
class IInterface {
public:
    virtual ~IInterface() {}           // Virtual destructor
    virtual void method1() = 0;        // Sadece saf sanal fonksiyonlar
    virtual int method2() = 0;
};
```

### Deep Copy Implementation
```cpp
class MyClass {
private:
    SomeClass* ptr;
public:
    MyClass(const MyClass& other) {
        ptr = new SomeClass(*other.ptr);  // Deep copy
    }
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete ptr;
            ptr = new SomeClass(*other.ptr);
        }
        return *this;
    }
};
```

## 🔍 Test Senaryoları

### ex00 Test
```bash
# Virtual function çalışması
# Doğru polimorfik davranış
# WrongAnimal ile karşılaştırma
```

### ex01 Test
```bash
# Brain nesnelerinin doğru oluşturulması
# Deep copy'nin çalışması
# Memory leak kontrolü
# Array of animals test
```

### ex02 Test
```bash
# Abstract class'tan nesne oluşturma denemesi (hata vermeli)
# Sadece derived class'lardan nesne oluşturma
# Polimorfik davranış kontrolü
```

### ex03 Test
```bash
# Materia yaratma ve öğrenme
# Character'e materia takma/çıkarma
# Materia kullanma (ice/cure)
# Interface implementasyonu kontrolü
```

## 📝 Notlar

- **Virtual Destructor**: Polimorfik sınıflarda mutlaka sanal destructor kullanın
- **Memory Management**: Dynamic allocation kullanıldığında dikkatli bellek yönetimi
- **Pure Virtual Functions**: Sınıfı abstract yapar, doğrudan instantiation'a izin vermez
- **Interface Segregation**: Küçük ve spesifik arayüzler tercih edilir
- **RAII**: Resource Acquisition Is Initialization prensibi
- **Exception Safety**: Copy constructor ve assignment operator'da güvenlik
- **Virtual Function Table**: V-table'ın nasıl çalıştığını anlayın
- **Slicing Problem**: Base class'a derived class atarken dikkat edin

## ⚠️ Yaygın Hatalar

1. **Virtual Destructor Unutma**: Memory leak'lere neden olur
2. **Shallow Copy**: Pointer'ların sadece adreslerinin kopyalanması
3. **Self Assignment**: `operator=`'da kendine atama kontrolü
4. **Pure Virtual**: Abstract class'tan nesne oluşturma denemesi
5. **Resource Leak**: Constructor'da exception durumunda bellek sızıntısı
6. **Dangling Pointer**: Silinmiş nesneye işaret eden pointer'lar
