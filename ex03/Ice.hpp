#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &copy);
        Ice& operator=(Ice const &other);
        ~Ice(void);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
