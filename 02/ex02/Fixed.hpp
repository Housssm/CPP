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
		
		//operation
		Fixed operator+(const Fixed &n) const;
		Fixed operator-(const Fixed &n) const;
		Fixed operator*(const Fixed &n) const;
		Fixed operator/(const Fixed &n) const;

		//comparaison
		bool	operator>(const Fixed &n)const;
		bool	operator<(const Fixed &n)const;
		bool	operator>=(const Fixed &n)const;
		bool	operator<=(const Fixed &n)const;
		bool	operator==(const Fixed &n)const;
		bool	operator!=(const Fixed &n)const;
		
		//incre/decrementation
		Fixed& operator++();
		Fixed& Fixed::operator++(int);
		Fixed& operator--();
		Fixed& Fixed::operator--(int);

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
