#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& input)
{
	// if (input == N)
	// 	std::cout << "Try a printable character" << std::endl;

	double	dbl_result;
	char *ptr;

	dbl_result = strtod(input.c_str(), &ptr);
	std::cout << "double :" << dbl_result << std::endl; 
	std::cout << "stroing :" << ptr << std::endl; 
	//char

	// //int
	// 	stoi()
	// //float 
	// 	Atof()
	// //double
	// 	atof()


}
