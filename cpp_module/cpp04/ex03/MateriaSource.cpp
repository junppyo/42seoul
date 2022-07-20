#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	idx = 0;
}

void MateriaSource::learnMateria(AMateria *input)
{
	if (idx >= 4)
	{
		std::cout << "MateriaSource is full" << std::endl;
		return ;
	}
	materia[idx] = input;
	idx++;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < idx; i++) 
	{
		if (materia[i]->getType() == type)
		{
			return materia[i]->clone();
		}
	}
	return 0;
}