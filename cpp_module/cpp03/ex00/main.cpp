#include "ClapTrap.hpp"

int main()
{
	ClapTrap ft = ClapTrap("A");
	ft.Attack("B");
	ft.takeDamage(3);
	std::cout << "hp: " << ft.get_hp() <<std::endl;
	ft.beRepaired(2);
	std::cout << "hp: " << ft.get_hp() <<std::endl;

	ft.Attack("B");
	ft.Attack("B");
	ft.Attack("B");
	ft.Attack("B");
	ft.Attack("B");
	ft.Attack("B");
	ft.Attack("B");
	ft.Attack("B");
	ft.beRepaired(1);
}