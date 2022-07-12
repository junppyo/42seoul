#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "New Dog !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Delete Dog" << std::endl;
}

std::string Dog::getType() const
{
	return "I'm Dog!";
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}