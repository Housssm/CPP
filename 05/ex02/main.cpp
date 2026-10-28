#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main ()
{
	Bureaucrat	bur3("Mahfoud", 50);
	ShrubberyCreationAForm f1("Nicolas");
	PresidentialPardonAForm f2("Pierre");
	ShrubberyCreationAForm f3("Louis");
	std::cout << std::endl;
	


	// try
	// 	{AForm f4("Pierette", -2, 50);}
	// catch (std::exception &e)
	// 	{std::cerr << "Exception attrapée : " << e.what() << std::endl;}
	// try
	// 	{AForm f6("Pierette", 180, 50);}
	// catch (std::exception &e)
	// 	{std::cerr << "Exception attrapée : " << e.what() << std::endl;}
	// try
	// 	{AForm f4("Pierette", 2, -90);}
	// catch (std::exception &e)
	// 	{std::cerr << "Exception attrapée : " << e.what() << std::endl;}
	// try
	// 	{AForm f6("Pierette", 10, 1850);}
	// catch (std::exception &e)
	// 	{std::cerr << "Exception attrapée : " << e.what() << std::endl;}
	// std::cout << std::endl;

	std::cout << bur3 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << std::endl;

	// try
	// 	{bur3.signAForm(f1);}
	// catch (std::exception& e)
	// 	{std::cerr << e.what() << std::endl;}
	// std::cout << std::endl;

	// try
	// 	{bur3.signAForm(f2);}
	// catch (std::exception& e)
	// 	{std::cerr << e.what() << std::endl;}
	// std::cout << std::endl;

	// try
	// 	{f3.beSigned(bur3);}
	// catch (std::exception& e)
	// 	{std::cerr << e.what() << std::endl;}
	// std::cout << std::endl;


	// std::cout << f1 << std::endl;
	// std::cout << f2 << std::endl;
	// std::cout << f3 << std::endl;
	// std::cout << std::endl;

	return 0;
}