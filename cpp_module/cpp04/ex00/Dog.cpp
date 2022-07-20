#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "New Dog !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Delete Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}