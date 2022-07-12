#include "Karen.hpp"

Karen::Karen()
{

}

Karen::~Karen()
{

}

void Karen::debug()
{
	std::cout <<  "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	std::string func_name[4] = {"debug", "info", "warning", "error"};
	void (Karen::*f[4])(void);
	f[0] = &Karen::debug;
	f[1] = &Karen::info;
	f[2] = &Karen::warning;
	f[3] = &Karen::error;
	int loc = std::find(func_name, func_name + 4, level) - func_name;
	if (loc == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	while (loc < 4)
	{
		(this->*f[loc])();
		loc++;
	}
}