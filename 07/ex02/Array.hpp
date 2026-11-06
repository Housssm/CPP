#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	public :
		Array() : _elements(NULL), _size(0)
		{
		}

		Array(unsigned int n) : _elements(new T[n]()), _size(n)
		{
		}

		Array(const Array &other) : _elements(NULL), _size(0)
		{
			if (other._size == 0)
			{
				_size = 0;
				_elements = NULL;
			}
			else
			{		
				_elements = new T[other._size]();
				_size = other._size;
				for (unsigned int i = 0; i < _size; i++)
					this->_elements[i] = other._elements[i];
			}
		}

		Array& operator=(const Array &other)
		{
			if ( this != &other)
			{
				delete [] _elements;
				if (other._size == 0)
				{
					_size = 0;
					_elements = NULL;
				}
				else
				{		
					_elements = new T[other._size]();
					_size = other._size;
					for (unsigned int i = 0; i < _size; i++)
						this->_elements[i] = other._elements[i];
				}
			}
			return *this;
		}

		~Array()
		{
			delete [] _elements;
		}

		unsigned int	size() const
		{
			return _size;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundIndex();
			return _elements[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundIndex();
			return _elements[index];
		}

		class OutOfBoundIndex : public std::exception
		{
			public :
				virtual const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};

	private :
		T*				_elements;
		unsigned int	_size;

};

#endif