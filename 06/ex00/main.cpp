
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{

	if (ac < 2 || ac > 2)
	{
		std::cerr << " Try with one argument" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	
	return 0;
}