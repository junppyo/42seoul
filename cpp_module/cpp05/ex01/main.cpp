#include "Bureaucrat.hpp"
#include "Form.hpp"

void formTest()
{
	Form form1("A", 0, 10);
	Form form2("B", 1, 160);
	Form form3("C", 10, 10);
	std::cout << form3  << std::endl;
}

void signTest()
{
	Form form1("form1", 10, 10);
	Form form2("form2", 10, 10);
	Bureaucrat bureaucrat1("1", 5);
	Bureaucrat bureaucrat2("2", 20);

	bureaucrat1.signForm(form1);
	bureaucrat2.signForm(form2);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
}


int main()
{
	formTest();
	std::cout << "\n=================================\n" << std::endl;
	signTest();
}