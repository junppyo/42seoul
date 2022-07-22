#include "ClapTrap.hpp"

int main()
{
	ClapTrap ft = ClapTrap("A");
	ft.attack("B");
	ft.takeDamage(3);
	std::cout << "hp: " << ft.get_hp() <<std::endl;
	ft.beRepaired(2);
	std::cout << "hp: " << ft.get_hp() <<std::endl;

	ft.attack("B");
	ft.attack("B");
	ft.attack("B");
	ft.attack("B");
	ft.attack("B");
	ft.attack("B");
	ft.attack("B");
	ft.attack("B");
	ft.beRepaired(1);
}