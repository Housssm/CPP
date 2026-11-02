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
	double	dbl_result;
	char *ptr;

	dbl_result = strtod(input.c_str(), &ptr);
	std::cout << "ptr : " << ptr << "."<< std::endl; 
	
	if (ptr == input.c_str())
	{
		std::cerr << "Invalid argument" << std::endl;
		return ;
	}

	if (*ptr != '\0' &&  !(ptr[0] == 'f' && ptr[1] == '\0'))
	{
		std::cerr << "Invalid argument" << std::endl;
		return ;
	}
	
	if ( dbl_result != dbl_result || dbl_result < std::numeric_limits<int>::min() || dbl_result > std::numeric_limits<int>::max())
	{
		std::cout << "char : impossible" << std::endl; 
		std::cout << "int : impossible" << std::endl; 
	}
	else
	{	
		char char_result = static_cast<char>(dbl_result);
		if (char_result <= 32 || char_result == 127)
			std::cout << "char : Non displayable" << std::endl; 
		else
			std::cout << "char : '" << char_result << "'" << std::endl; 
		int int_result = static_cast<int>(dbl_result);
		std::cout << "int : " << int_result << std::endl; 
	}

	float flt_result = static_cast<float>(dbl_result);
	std::cout << "float : " << std::fixed << std::setprecision(1) << flt_result << "f" << std::endl; 

	std::cout << "double : " << std::fixed << std::setprecision(1) << dbl_result << std::endl; 
}
