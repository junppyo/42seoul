#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "New Animal !" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Delete Animal" << std::endl;
}

std::string Animal::getType() const
{
	return "It's just animal";
}

void Animal::makeSound() const
{
	std::cout << ". . . ." << std::endl;
}
