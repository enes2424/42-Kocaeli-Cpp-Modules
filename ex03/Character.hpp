#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        AMateria    **materias;
        std::string name;

    public:
        Character(void);
        Character(std::string const &name);
        Character(Character &copy);
        Character& operator=(Character const &other);
        ~Character(void);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
