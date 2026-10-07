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
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		// min/max
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);

		static const Fixed&	min(Fixed const & a, Fixed const & b);
		static const Fixed&	max(Fixed const & a, Fixed const & b);


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
