#include "Bureaucrat.hpp"

int main()
{
	{
		Bureaucrat a("A", 10);
		std::cout << a << std::endl;
		a.setIncreaseGrade(50);
		std::cout << a << std::endl;
	}

	std::cout << "\n=================================\n" << std::endl;

	{
		Bureaucrat a("A", 10);
		std::cout << a << std::endl;
		a.setIncreaseGrade(9);
		std::cout << a << std::endl;
		a.setDecreaseGrade(50);
		std::cout << a << std::endl;
	}

	std::cout << "\n=================================\n" << std::endl;

	{
		try
		{
			Bureaucrat a("A", 1000);
			std::cout << a << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}