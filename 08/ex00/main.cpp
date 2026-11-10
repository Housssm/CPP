#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>


int main ()
{
	static const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 7, 98, 99};
	std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

	// static const int array[] = {};
	// std::vector<int> vect (array, array + sizeof(array) / sizeof(array[0]) );
	std::vector<int> vect;

	std::cout << "Indice value is of 7 (arr) is: " << easyfind(vec, 7) - vec.begin() << std::endl;
	std::cout << "Indice value is of 1 (arr) is: " << easyfind(vec, 1) - vec.begin() << std::endl;
	std::cout << "Indice value is of 99 (arr) is: " << easyfind(vec, 99) - vec.begin() << std::endl;
	try
	{
		std::cout << "Indice value is of 0 (arr) is: " << easyfind(vec, 0) - vec.begin() << std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	try
	{
		std::cout << "Indice value is of 5 (array)is: " << easyfind(vect, 5) - vect.begin() << std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "-------TEST WITH DEQUE-----------"<< std::endl;
	static const int deq[] = {7, 5, 16, 8};
	std::deque<int> dequ (deq, deq + sizeof(deq) / sizeof(deq[0]) );
	std::cout << "Indice value is of 16 (deque) is: " << easyfind(dequ, 16) - dequ.begin() << std::endl;

	try
	{
		std::cout << "Indice value is of 0 is: " << easyfind(dequ, 0) - dequ.begin() << std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}