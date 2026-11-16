#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0)
{
	// std::cout << "Span constructor called" << std::endl;
}

Span::Span(const unsigned int N) : _N(N)
{
	// std::cout << "Span constructor called" << std::endl;
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
	// std::cout << "Span destructor called" << std::endl;
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
	std::vector<int> sorted(_vec);
	std::sort(sorted.begin(), sorted.end());

	unsigned int diff = static_cast<unsigned int>(static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]));

	for (size_t i = 2; i < sorted.size(); i++)
	{
		unsigned int curr_diff = static_cast<unsigned int>(static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]));

		if (curr_diff < diff)
			diff = curr_diff;
	}
	return diff;
}

unsigned int		Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw noSpan();
	
	int minVal = *std::min_element(_vec.begin(), _vec.end());
	int maxVal = *std::max_element(_vec.begin(), _vec.end());
	return static_cast<unsigned int>(static_cast<long>(maxVal) - static_cast<long>(minVal));
}

const char *Span::noSpan::what() const throw()
{
	return "No span can be found";
}

const char *Span::noMoreSpace::what() const throw()
{
	return "No more space";
}
