#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern esclave;
	Bureaucrat p1("Mahfoud", 1);
	AForm* rrf = esclave.makeForm("robomy request", "Bender");
	AForm* rrff = esclave.makeForm("robotomy request", "Bender");

	if (rrf)
	{
		std::cout << p1 << std::endl;
		std::cout << *rrf << std::endl;
		std::cout << std::endl;

		p1.signForm(*rrf);
		std::cout << *rrf << std::endl;
		std::cout << std::endl;

		p1.executeForm(*rrf);
		std::cout << std::endl;

		delete rrf;
	}


	if (rrff)
	{
		std::cout << p1 << std::endl;
		std::cout << *rrff << std::endl;
		std::cout << std::endl;

		p1.signForm(*rrff);
		std::cout << *rrff << std::endl;
		std::cout << std::endl;

		p1.executeForm(*rrff);
		std::cout << std::endl;

		delete rrff;
	}
	return 0;
}