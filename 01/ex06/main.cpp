#include <iostream>
#include "Harl.hpp"

int main (int ac ,char **av)
{
	if (ac != 2)
		return (std::cout << "please enter a command" << std::endl, 1);
	Harl	harl;

	harl.ignore(av[1]);
	return (0);
}