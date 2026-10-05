#pragma once
#include <iostream>

class   Fixed
{
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float point_number);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int                 _fixedPoint;
		static const int    _nbFractBits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );
