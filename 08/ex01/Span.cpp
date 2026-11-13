#pragma once
#include <iostream>
#include <exception>
#include <vector>

class Span
{
	public:
		Span();
		Span(const unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void				addNumber(const int N);
		unsigned int		shortestSpan() const;
		unsigned int		 longestSpan() const;

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
};