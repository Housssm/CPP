#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Memory  adress of str      : " << &str << std::endl;
	std::cout << "Memory  adress of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory  adress of stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
 	std::cout << "Value pointed to by str      : " << str <<  std::endl;
 	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
 	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}