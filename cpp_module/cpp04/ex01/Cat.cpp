#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "New Cat !" << std::endl;
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat& input)
{
	brain = new Brain(*input.get_brain());
	type = input.getType();
	std::cout << "Copy Cat !" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Delete Cat" << std::endl;
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
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*input.get_brain());
	std::cout << "Copy Cat !" << std::endl;
	return *this;
}