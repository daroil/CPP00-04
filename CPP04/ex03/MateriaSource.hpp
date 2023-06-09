

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource & operator=(const MateriaSource &assign);
        void learnMateria(AMateria* materia);
        AMateria * createMateria(const std::string &type);
        AMateria** cloneMaterias(void) const;
    private:
        AMateria **_materias;
};