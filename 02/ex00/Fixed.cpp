#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits()
{
	std::cout << "getRawBits member function called" << std::endl;
	return _nbFractBits;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPoint  = (other._fixedPoint);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy asignement operator called" << std::endl;
	if (this != &other)
	{
		_fixedPoint = 0;
		_fixedPoint = other.getRawBits();
	}
	return *this;
}