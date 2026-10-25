#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat bur1;
	Bureaucrat bur2(7);
	Bureaucrat bur3("Mahfoud", 1);
	std::cout << std::endl;

	std::cout << bur1 << std::endl;
	std::cout << bur2 << std::endl;
	std::cout << bur3 << std::endl;
	std::cout << std::endl;

	try
		{bur1.decrementGrade();}
	catch (std::exception& e)
		{std::cerr << e.what() << std::endl;}

	try
		{bur2.incrementGrade();}
	catch (std::exception& e)
		{std::cerr << e.what() << std::endl;}
	
	try
		{bur3.incrementGrade();}
	catch (std::exception& e)
		{std::cerr << e.what() << std::endl;}
	std::cout << std::endl;

	std::cout << bur1 << std::endl;
	std::cout << bur2 << std::endl;
	std::cout << bur3 << std::endl;
	std::cout << std::endl;
	
	/*************************************************************/
	std::cout << "\nTEST LIMITES\n" << std::endl;

	try
		{Bureaucrat bur4("Alice", 159);}
	catch (std::exception &e)
		{std::cerr << "Exception attrapée : " << e.what() << std::endl;}

	try
		{Bureaucrat bur5("Pierette", 0);}
	catch (std::exception &e)
		{std::cerr << "Exception attrapée : " << e.what() << std::endl;}

	/*************************************************************/
	std::cout << "\n TEST COPIES\n" << std::endl;
	
	Bureaucrat bur6(bur2);
	std::cout << bur2 << std::endl;
	std::cout << bur6 << std::endl;
	std::cout << std::endl;

	bur1 = bur2;
	std::cout << bur6 << std::endl;
	std::cout << std::endl;

	return 0;
}