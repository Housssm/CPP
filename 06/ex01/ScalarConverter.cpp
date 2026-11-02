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
	
	//Char literals verification
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		if (!std::isprint(input[0]))
		{
			std::cerr << "Invalid argument" << std::endl;
			return ;
		}
		dbl_result = static_cast<double>(input[0]);
		ptr = const_cast<char*>("");
	}
	else
	{
		dbl_result = strtod(input.c_str(), &ptr);
		if (ptr == input.c_str() || (*ptr != '\0' &&  !(ptr[0] == 'f' && ptr[1] == '\0')))
		{
			std::cerr << "Invalid argument" << std::endl;
			return ;
		}
	}

	bool is_special = std::isnan(dbl_result) || std::isinf(dbl_result);

	// CHAR
	std::cout << "char : ";
	if (is_special||  dbl_result < 0 || dbl_result > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(dbl_result)))
		std::cout << "Non displayable" << std::endl; 
	else
		std::cout << "'" << static_cast<char>(dbl_result) << "'" << std::endl;
	
	// INT
	std::cout << "int : ";
	if (is_special|| dbl_result < std::numeric_limits<int>::min() || dbl_result > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(dbl_result) << std::endl;

	//FLOAT
	std::cout << "float : ";
	if (!is_special && (dbl_result < -std::numeric_limits<float>::max() || dbl_result > std::numeric_limits<float>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(dbl_result) << "f" << std::endl; 

	//DOUBLE
	std::cout << "double : ";
	std::cout << std::fixed << std::setprecision(1) << dbl_result << std::endl; 
}
