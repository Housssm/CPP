#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl()
{

}

Harl::~Harl()
{
	
}
void Harl::_debug()
{
	std::cout << "[DEBUG]" << std::endl<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info()
{
	std::cout << "[INFO]" << std::endl<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning()
{
	std::cout << "[WARNING]" << std::endl<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::_error()
{
	std::cerr << "[ERROR]" << std::endl<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void (Harl::*fn)(void);
	fn funct[4] = {&Harl::_debug,&Harl::_info, &Harl::_warning, &Harl::_error};
	
	for(int i = 0; i <= 3; i++)
	{
		if (level== levels[i])
		{
			(this->*funct[i])();
			return;
		}
	}
}