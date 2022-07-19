#include "ScavTrap.hpp"

int main()
{
	ScavTrap st = ScavTrap("A");
	for (int i = 0 ; i < 51; i++)
		st.attack("BBB");
}