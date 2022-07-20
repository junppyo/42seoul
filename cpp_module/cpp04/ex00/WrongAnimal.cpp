#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "New WrongAnimal !" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Delete WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << ". . . ." << std::endl;
}
