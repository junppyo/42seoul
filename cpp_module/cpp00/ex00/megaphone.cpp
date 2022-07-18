#include <iostream>

void	upper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = toupper(s[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (i < argc)
		{
			upper(argv[i]);
			std::cout << argv[i];
			i++;
		}
	}
	std::cout << "\n";
	return (0);
}
