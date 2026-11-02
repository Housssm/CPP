#ifndef SCALCONVERTER_HPP
#define SCALCONVERTER_HPP

#include <string>
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public :
		static void convert(const std::string& input);
};

#endif