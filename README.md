# 42 Kocaeli C++ Module 05
## Exception Handling & Forms (İstisna İşleme ve Formlar)

Bu proje, 42 Okulu C++ eğitiminin beşinci modülüdür. C++ dilinde exception handling (istisna işleme), inheritance (kalıtım), polymorphism (çok biçimlilik), ve abstract sınıflar konularını öğrenmek için tasarlanmıştır.

## 📚 Egzersizler

### ex00 - Mommy, when I grow up, I want to be a bureaucrat!
**Dosyalar:** `ex00/Bureaucrat.cpp`, `ex00/Bureaucrat.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Temel bürokrat sınıfı ve exception handling.
- **Program:** `MommyWhenIGrowUpIWantToBeABureaucrat`
- **Sınıf:** `Bureaucrat`
- **Özellikler:**
  - Bürokrat adı (sabit, değiştirilemez)
  - Bürokrat seviyesi (1-150 arası)
  - Grade increment/decrement fonksiyonları
  - Custom exception sınıfları
- **İstisnalar:**
  - `GradeTooHighException` (seviye 1'den küçük)
  - `GradeTooLowException` (seviye 150'den büyük)
- **Örnek:**
  ```cpp
  try {
      Bureaucrat b("John", 0); // Exception fırlatır
  } catch (std::exception &e) {
      std::cout << e.what() << std::endl; // "Grade too high exception"
  }
  
  Bureaucrat b("Jane", 75);
  std::cout << b; // "Jane, bureaucrat grade 75."
  b.increment(); // Grade 74'e düşer
  ```

### ex01 - Form up, maggots!
**Dosyalar:** `ex01/Form.cpp`, `ex01/Form.hpp`, `ex01/Bureaucrat.cpp`, `ex01/Bureaucrat.hpp`, `ex01/main.cpp`, `ex01/Makefile`

Form sınıfı ve bürokrat-form etkileşimi.
- **Program:** `FormUpMaggots`
- **Sınıflar:** `Bureaucrat`, `Form`
- **Form Özellikleri:**
  - Form adı (sabit)
  - İmzalanma durumu (bool)
  - İmzalamak için gereken minimum seviye
  - Çalıştırmak için gereken minimum seviye
- **Form Fonksiyonları:**
  - `beSigned()` - Bürokrat tarafından imzalanma
  - Getter fonksiyonları
- **Bürokrat Eklentileri:**
  - `signForm()` - Form imzalama fonksiyonu
- **Örnek:**
  ```cpp
  Form form("Tax Form", 50, 25);
  Bureaucrat b("Agent", 40);
  
  form.beSigned(b); // Başarılı imzalama
  std::cout << form; // Form bilgilerini yazdırır
  ```

### ex02 - No, you need form 28B, not 28C...
**Dosyalar:** `ex02/AForm.cpp`, `ex02/AForm.hpp`, `ex02/Bureaucrat.cpp`, `ex02/Bureaucrat.hpp`, `ex02/ShrubberyCreationForm.cpp`, `ex02/ShrubberyCreationForm.hpp`, `ex02/RobotomyRequestForm.cpp`, `ex02/RobotomyRequestForm.hpp`, `ex02/PresidentialPardonForm.cpp`, `ex02/PresidentialPardonForm.hpp`, `ex02/main.cpp`, `ex02/Makefile`

Abstract form sınıfı ve concrete form implementasyonları.
- **Program:** `NoYouNeedForm28BNot28C`
- **Sınıflar:** `AForm` (abstract), `Bureaucrat`, concrete form sınıfları
- **AForm Özellikleri:**
  - Pure virtual `execute()` fonksiyonu
  - `FormNotSignedException` istisnası
  - Base form functionality
- **Concrete Form Sınıfları:**
  
  **1. ShrubberyCreationForm:**
  - İmzalama seviyesi: 145
  - Çalıştırma seviyesi: 137
  - ASCII ağaç çizerek dosya oluşturur
  
  **2. RobotomyRequestForm:**
  - İmzalama seviyesi: 72
  - Çalıştırma seviyesi: 45
  - %50 şansla robotomy başarı/başarısızlık
  
  **3. PresidentialPardonForm:**
  - İmzalama seviyesi: 25
  - Çalıştırma seviyesi: 5
  - Başkanlık affı mesajı yazdırır

- **Bürokrat Eklentileri:**
  - `executeForm()` - Form çalıştırma fonksiyonu
- **Örnek:**
  ```cpp
  AForm *form = new ShrubberyCreationForm("garden");
  Bureaucrat b("Gardener", 100);
  
  form->beSigned(b);
  form->execute(b); // ASCII ağaç dosyası oluşturur
  b.executeForm(*form); // Alternative execution
  ```

### ex03 - At least this beats coffee-making
**Dosyalar:** `ex03/Intern.cpp`, `ex03/Intern.hpp`, `ex03/AForm.cpp`, `ex03/AForm.hpp`, `ex03/Bureaucrat.cpp`, `ex03/Bureaucrat.hpp`, `ex03/ShrubberyCreationForm.cpp`, `ex03/ShrubberyCreationForm.hpp`, `ex03/RobotomyRequestForm.cpp`, `ex03/RobotomyRequestForm.hpp`, `ex03/PresidentialPardonForm.cpp`, `ex03/PresidentialPardonForm.hpp`, `ex03/main.cpp`, `ex03/Makefile`

Intern sınıfı ve form factory pattern.
- **Program:** `AtLeastThisBeatsCoffeeMaking`
- **Sınıflar:** `Intern` + önceki tüm sınıflar
- **Intern Özellikleri:**
  - `makeForm()` fonksiyonu
  - String ile form tipini belirleyerek form oluşturma
  - Factory pattern implementasyonu
- **Desteklenen Form Tipleri:**
  - "presidential pardon"
  - "robotomy request" 
  - "shrubbery creation"
- **Örnek:**
  ```cpp
  Intern intern;
  AForm *form;
  
  form = intern.makeForm("robotomy request", "Bender");
  // "Intern creates robotomy request" yazdırır
  
  form = intern.makeForm("invalid form", "target");
  // "Intern could not create a form!!" yazdırır
  // NULL döner
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
# ex00 - Bureaucrat
cd ex00
make
./MommyWhenIGrowUpIWantToBeABureaucrat

# ex01 - Form
cd ex01
make
./FormUpMaggots

# ex02 - Abstract Forms
cd ex02
make
./NoYouNeedForm28BNot28C

# ex03 - Intern
cd ex03
make
./AtLeastThisBeatsCoffeeMaking
```

### Makefile Komutları
```bash
make        # Programı derle
make clean  # Object dosyalarını sil
make fclean # Programı ve object dosyalarını sil
make re     # Temizle ve yeniden derle
```

## 🎯 Öğrenilen Kavramlar

1. **Exception Handling**: try/catch blokları, custom exception sınıfları
2. **Inheritance**: Temel ve türetilmiş sınıflar
3. **Polymorphism**: Virtual fonksiyonlar, pure virtual fonksiyonlar
4. **Abstract Classes**: Soyut sınıflar ve interface tasarımı
5. **RAII**: Resource Acquisition Is Initialization prensibi
6. **Factory Pattern**: Nesne oluşturma tasarım deseni
7. **Const Correctness**: Const üye değişkenler ve fonksiyonlar
8. **Operator Overloading**: Stream insertion operator
9. **Memory Management**: Dynamic allocation ve deallocation
10. **File I/O**: ofstream ile dosya yazma işlemleri

## 📋 C++ Standartları ve Kurallar

- **C++98 Standardı**: Projede kullanılan C++ versiyonu
- **Derleme Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Orthodox Canonical Form**: Tüm sınıflarda uygulandı
- **Exception Safety**: Exception handling best practices
- **RAII Prensibi**: Resource yönetimi
- **Virtual Destructors**: Inheritance hierarchy'de gerekli
- **Pure Virtual Functions**: Abstract sınıf implementasyonu

## 🔍 Test Senaryoları

### ex00 Test
```bash
# Geçersiz grade değerleri
Bureaucrat("Test", 0);     # GradeTooHighException
Bureaucrat("Test", 151);   # GradeTooLowException

# Grade değiştirme
Bureaucrat b("Test", 1);
b.increment();             # GradeTooHighException

Bureaucrat b2("Test", 150);
b2.decrement();            # GradeTooLowException
```

### ex01 Test
```bash
# Form imzalama
Form form("Test", 50, 25);
Bureaucrat low("Low", 100);
form.beSigned(low);        # GradeTooLowException

Bureaucrat high("High", 25);
form.beSigned(high);       # Başarılı imzalama
```

### ex02 Test
```bash
# Form execution
ShrubberyCreationForm form("test");
Bureaucrat b("Test", 100);

form.execute(b);           # FormNotSignedException
form.beSigned(b);
form.execute(b);           # test_shrubbery dosyası oluşur

# Robotomy random test
RobotomyRequestForm robot("target");
robot.beSigned(b);
robot.execute(b);          # %50 şans ile başarı/başarısızlık
```

### ex03 Test
```bash
# Form creation
Intern intern;
AForm *form1 = intern.makeForm("robotomy request", "target");  // Başarılı
AForm *form2 = intern.makeForm("invalid form", "target");     // NULL döner

# Memory management
if (form1) {
    // Form kullanımı
    delete form1;
}
```

## 📝 Dosya Yapıları

### Bureaucrat Class Structure
```cpp
class Bureaucrat {
private:
    const std::string name;
    int grade;  // 1-150 arası
public:
    // Orthodox Canonical Form
    // Getter/Setter fonksiyonlar
    // increment/decrement
    // signForm, executeForm
    // Exception sınıfları
};
```

### AForm Abstract Class Structure
```cpp
class AForm {
private:
    const std::string name;
    const int grade_required_to_sign;
    const int grade_required_to_execute;
    bool is_signed;
public:
    // Orthodox Canonical Form
    virtual ~AForm();
    virtual void execute(Bureaucrat const & executor) const = 0;
    // Exception sınıfları
};
```

### Concrete Forms
- **ShrubberyCreationForm**: ASCII art ağaç çizer ve dosyaya kaydeder
- **RobotomyRequestForm**: Rastgele robotomy işlemi simüle eder
- **PresidentialPardonForm**: Başkanlık affı mesajı yazdırır

### Intern Factory
```cpp
class Intern {
public:
    AForm *makeForm(std::string name, std::string target);
    // Switch statement ile form tipini belirler
    // Uygun concrete form nesnesi oluşturur
};
```

## 📊 Grade Requirements

| Form Type | Sign Grade | Execute Grade |
|-----------|------------|---------------|
| ShrubberyCreationForm | 145 | 137 |
| RobotomyRequestForm | 72 | 45 |
| PresidentialPardonForm | 25 | 5 |

## 🚀 Exception Hierarchy

```
std::exception
    ├── Bureaucrat::GradeTooHighException
    ├── Bureaucrat::GradeTooLowException
    ├── AForm::GradeTooHighException
    ├── AForm::GradeTooLowException
    └── AForm::FormNotSignedException
```

## 📝 Notlar

- Exception safety garantileri sağlanmıştır
- Memory leak'leri önlemek için dikkatli pointer yönetimi
- Virtual destructor kullanımı inheritance için gereklidir
- Pure virtual functions abstract sınıf oluşturmak için kullanılır
- Factory pattern esnek nesne oluşturma sağlar
- RAII prensibi resource yönetimi için uygulanır
- Const correctness tüm projede korunmuştur
