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
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::_error()
{
	std::cerr << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int	Harl::find_idx(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i <= 3; i++)
	{
		if (level== levels[i])
			return(i);
	}
	return (-1);
}


void Harl::ignore(const std::string& prompt)
{
	int	index = find_idx(prompt);
	switch (index)
	{
		case 0:
			this->_debug();
			// fallthrough
		case 1:
			this->_info();
			// fallthrough
		case 2:
			this->_warning();
			// fallthrough
		case 3:
		{
			this->_error();
			break;
		}
		default: 
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

