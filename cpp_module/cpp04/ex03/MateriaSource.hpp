#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materia[4];
		int idx;
	public:
		MateriaSource();
		virtual ~MateriaSource() {}
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif