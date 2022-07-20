#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	AMateria *ret = new Cure();
	return ret;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}