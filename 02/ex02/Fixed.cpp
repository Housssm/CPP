#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed(): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = value << _nbFractBits;
}

Fixed::Fixed(const float point_number)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(point_number * (1 << _nbFractBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / (1 << _nbFractBits));
}

int		Fixed::toInt(void) const
{
	 return _fixedPoint >> _nbFractBits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPoint  = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_fixedPoint = 0;
		_fixedPoint = other.getRawBits();
	}
	return *this;
}

//Arithmetic function

Fixed Fixed::operator+(const Fixed &n) const
{
	return (this->toFloat() + n.toFloat());
}

Fixed Fixed::operator-(const Fixed &n) const
{
	return (this->toFloat() + n.toFloat());
}


Fixed Fixed::operator*(const Fixed &n) const
{
	return (this->toFloat() * n.toFloat());
}
Fixed Fixed::operator/(const Fixed &n) const
{
	if (n.getRawBits() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return (Fixed(0));
	}
	return (this->toFloat() / n.toFloat());
}


//Comparaison functions
bool	Fixed::operator>(const Fixed &n)const
{
	if (_fixedPoint > n._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &n)const
{
	if (_fixedPoint < n._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &n)const
{
	if (_fixedPoint >= n._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &n)const
{
		if (_fixedPoint <= n._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &n)const
{
	if (_fixedPoint == n._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &n)const
{
	if (_fixedPoint != n._fixedPoint)
		return (true);
	return (false);
}







std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
    o << rhs.toFloat();
    return o;
}

