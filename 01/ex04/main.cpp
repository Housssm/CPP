#include "replace.hpp"

int main (int ac, char **av)
{

	if (ac != 4)
		return(std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl,1);

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	// std::ifstream src(filename.c_str());
	// if (!src.is_open())
	// 	return (std::cerr << "Error cannot open the file" << std::endl, 1);

	// std::string content;
	// char c;
	// while(src.get(c))
	// 	content += c;
	if (!Copy_Replace(filename, s1, s2))
		return 1;
	return 0;
}
