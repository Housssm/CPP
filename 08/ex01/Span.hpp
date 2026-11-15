#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <iterator>

class Span
{
	public:
		Span();
		Span(const unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		template <typename inputIterator>
		void				addNumber(inputIterator begin, inputIterator end)
		{
			if (_vec.size() + std::distance(begin, end) > _N)
				throw noMoreSpace();
			_vec.insert(_vec.end(), begin, end);
		}

		void				addNumber(const int N);
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
		
		private:
			unsigned int		_N;
			std::vector<int>	_vec;
};