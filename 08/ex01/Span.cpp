#include "Span.hpp"

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

		template <typename inputOperator>
		void				addNumber(inputOperator begin, inputOperator end);

		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;
		
		

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