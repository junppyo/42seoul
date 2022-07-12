#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0 ; i < 100; i++)
		idea[i] = "Nothing";
	std::cout << "Brain Default Constructor" << std::endl;
}

Brain::Brain(const Brain& input)
{
	for (int i = 0 ; i < 100; i++)
	{
		idea[i] = input.get_idea(i);
	}
	std::cout << "Brain Copy constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& input)
{
	if (this == &input)
		return *this;
	for (int i = 0 ; i < 100; i++)
		idea[i] = input.get_idea(i);
	std::cout << "Brain Deep copied" << std::endl;
	return *this;
}

std::string Brain::get_idea(int i) const
{
	return idea[i];
}

void Brain::set_idea(int i, std::string input)
{
	idea[i] = input;
}

std::ostream& operator<<(std::ostream &o, const Brain& b)
{
	for (int i = 0; i < 100; i++)
		std::cout << i + 1 << "\t" << b.get_idea(i) << std::endl;
	return o;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}