#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria* ) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    **materias;
        int         index;
        bool        isFull;

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource &copy);
        MateriaSource& operator=(MateriaSource &other);
        ~MateriaSource(void);
        void        learnMateria(AMateria* );
        AMateria*   createMateria(std::string const & type);
};

#endif
