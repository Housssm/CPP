#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <list>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "\n------no more space--------" << std::endl;	
	try
	{	
		sp.addNumber(6);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------no span--------" << std::endl;	
	Span sp2 = Span(1);
	sp2.addNumber(8);
	try
	{	
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{	
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------10 000--------" << std::endl;	

	Span sp3 = Span(10000);
	std::srand(std::time(NULL));
	std::vector<int> range;
	for (int i = 0; i < 10000; i++)
	{
		range.push_back(std::rand());
	}
	sp3.addNumber(range.begin(), range.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	try
	{	
		sp3.addNumber(6);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------list--------" << std::endl;	

	std::list<int> myList;
	myList.push_back(10);
	myList.push_back(12);
	myList.push_back(14);

	Span sp4 = Span(3);
	sp4.addNumber(myList.begin(), myList.end());
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;
	
	return 0;
}