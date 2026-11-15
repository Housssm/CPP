#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const unsigned int N) : _N(N)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span& other)
{
	_N = other._N;
	_vec = other._vec;
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_vec = other._vec;
	}
	std::cout << "Span operator called" << std::endl;
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(const int N)
{
	if (_vec.size() + 1 > _N)
		throw noMoreSpace();
	_vec.insert(_vec.end(), N);
}

unsigned int		Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw noSpan();
	std::sort(_vec.begin(), _vec.end());
	unsigned int diff = _vec[1] - _vec[0];
	for (size_t i = 1; i < _vec.size(); i++)
	{
		if (static_cast<long>(_vec[i]) - _vec[i - 1] < static_cast<int>(diff))
			diff =_vec[i] - _vec[i - 1];
	}
	return diff;
}

unsigned int		Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw noSpan();
	std::sort(_vec.begin(), _vec.end());
	return _vec.max() - _vec.min();
}



class noSpan : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class	noMoreSpace : public std::exception
{
	public :
		virtual const char* what() const throw();
};