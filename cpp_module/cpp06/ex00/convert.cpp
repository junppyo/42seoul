#include "iostream"
#include "cmath"

void print_char(char c, double d)
{
	if (std::isnan(d) || std::isinf(d) || d > 2147483647 || d < -2147483648)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(c))
	{
		std::cout << "char: Non displayable"<< std::endl;
		return ;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

void print_int(int n, double d)
{
	if (std::isnan(d) || std::isinf(d) || d > 2147483647 || d < -2147483648)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << n << std::endl;
}

void print_fd(float f, double d)
{
	if (std::isinf(d))
	{
		std::cout << std::showpos << "float: " << f << "f" << std::endl;
		std::cout << std::showpos << "double: " << d << std::endl;
		return ;
	}
	if (f == static_cast<int>(f))
		std::cout << "float: " << f << ".0f" << std::endl;
	else
	{
		std::cout << "float: " <<  f << "f" << std::endl;
	}
	if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	char *ptr = NULL;
	double _double = std::strtod(argv[1], &ptr);
	if (ptr[0] != '\0' && std::strcmp(ptr, "f"))
	{
		std::cout << "cannot cast argument" << std::endl;
		return (1);
	}
	char _char = static_cast<char>(_double);
	int _int = static_cast<int>(_double);
	float _float = static_cast<float>(_double);
	print_char(_char, _double);
	print_int(_int, _double);
	print_fd(_float, _double);

	return (0);
}