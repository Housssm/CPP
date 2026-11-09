#include "easyfind.hpp"
#include <iostream>
#include <vector>


int main ()
{
	static const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 888, 98, 99};
	std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

	std::cout << "Indice value is: " << easyfind(vec, 7) - vec.begin() << std::endl;
	try
	{
		easyfind(vec, 0);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	easyfind(arrow, 7);
	return 0;
}