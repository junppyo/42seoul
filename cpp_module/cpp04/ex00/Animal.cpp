#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "New Animal !" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Delete Animal" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << ". . . ." << std::endl;
}
