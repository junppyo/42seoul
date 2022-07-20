#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "New Dog !" << std::endl;
	brain = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog& input)
{
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*input.get_brain());
	type = input.getType();
	std::cout << "Copy Dog !" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Delete Dog" << std::endl;
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
	type = input.getType();
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*input.get_brain());
	return *this;
}