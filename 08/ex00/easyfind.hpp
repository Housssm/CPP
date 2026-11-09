#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>


class NotPresentIndex : public std::exception
{
	public : 
		virtual const char* what() const throw()
		{
			return "Not present in the array";
		}
};

template <typename T>
typename T::const_iterator	easyfind(const T &array,const int toFind)
{

	typename T::const_iterator it = std::find(array.begin(), array.end(), toFind);
	if (it != array.end())
		return it;
	else
		throw NotPresentIndex();

}

#endif