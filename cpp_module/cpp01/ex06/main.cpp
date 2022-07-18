#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	std::string str(argv[1]);
	int i = 0;
	while (str[i])
	{
		str[i] = tolower(str[i]);
		i++;
	}
	Harl harl = Harl();
	harl.complain(str);
}