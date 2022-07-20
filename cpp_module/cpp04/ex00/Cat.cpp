#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "New Cat !" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Delete Cat" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "nya" << std::endl;
}