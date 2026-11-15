#include "Span.hpp"

Span()
{
	std::cout << "Span constructor called" << std::endl;
}

Span(const unsigned int N)
{
		new
	std::cout << "Span constructor called" << std::endl;
}
Span(const Span& other);
Span& operator=(const Span& other);
~Span()
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