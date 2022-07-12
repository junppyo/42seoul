#include "ScavTrap.hpp"

int main()
{
	ScavTrap st = ScavTrap();
	for (int i = 0 ; i < 50; i++)
		st.Attack("BBB");
}