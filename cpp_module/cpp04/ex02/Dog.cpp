#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "New Dog !" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& input)
{
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*input.get_brain());
	std::cout << "Copy Dog !" << std::endl;
}

Dog::~Dog()
{
	delete brain;
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


const Brain *Dog::get_brain() const
{
	return brain;
}

Dog& Dog::operator=(const Dog& input)
{
	if (this == &input)
		return *this;
	std::cout << "Copy Dog !" << std::endl;
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*input.get_brain());
	return *this;
}