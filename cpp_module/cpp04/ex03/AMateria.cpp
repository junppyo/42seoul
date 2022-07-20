#include "AMateria.hpp"

AMateria::AMateria(std::string const& input)
{
	type = input;
}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "use " << type << " to " << target.getName() << std::endl;
}

AMateria& AMateria::operator=(const AMateria& input)
{
	if (this == &input)
		return *this;
	return *(input.clone());
}