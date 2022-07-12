#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "New Cat !" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Delete Cat" << std::endl;
}

std::string Cat::getType() const
{
	return "I'm Cat!";
}

void Cat::makeSound() const
{
	std::cout << "nya" << std::endl;
}