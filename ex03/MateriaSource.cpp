#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    materias = new AMateria*[4];
    index = 0;
    isFull = false;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &copy) {
    materias = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
    *this = copy;
}

MateriaSource& MateriaSource::operator=(MateriaSource &other) {
    for (int i = 0; i < 4; i++)
        if (other.materias[i])
            *materias[i] = *other.materias[i];
    index = other.index;
    isFull = other.isFull;
    return *this;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete materias[i];
    delete[] materias;
}

void    MateriaSource::learnMateria(AMateria* materia) {
    materias[index++] = materia->clone();
    if (index == 4) {
        isFull = true;
        index = 0;
    }
    delete materia;
}

AMateria*   MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++)
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    return 0;
}
