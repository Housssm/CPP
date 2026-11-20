#include "BitcoinExchange.hpp"

int main (int ac , char **av)
{
	if( ac != 2)
	{
		std::cerr << "Error : need 2 arguments." << std::endl;
		return 1;
	}
	
	BitcoinExchange btc;
	
	try
	{
		btc.processInputFile(av[1]);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}