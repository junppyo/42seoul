#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "New WrongCat !" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Delete WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "nya" << std::endl;
}