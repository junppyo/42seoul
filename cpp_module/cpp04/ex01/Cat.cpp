#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "New Cat !" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& input)
{
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*input.get_brain());
	std::cout << "Copy Cat !" << std::endl;
}

Cat::~Cat()
{
	delete brain;
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

const Brain *Cat::get_brain() const
{
	return brain;
}

Cat& Cat::operator=(const Cat& input)
{
	if (this == &input)
		return *this;
	std::cout << "Copy Cat !" << std::endl;
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*input.get_brain());
	return *this;
}