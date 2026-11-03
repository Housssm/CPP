#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}



static AForm* shrubber(const std::string& target)
{
	return new ShrubberyCreationForm(target);	
}

static AForm* robot(const std::string& target)
{
	return new RobotomyRequestForm(target);	
}

static AForm* president(const std::string& target)
{
	std::cout << "intern creates PresidentialPardonForm" << std::endl;
	return new PresidentialPardonForm(target);	
}

AForm* Intern::makeForm(const std::string& name,const std::string& target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	typedef AForm* (*pf)(const std::string&);
	pf ftab[3];
	ftab[0] = &shrubber;
	ftab[1] = &robot;
	ftab[2] = &president;

	for (int i = 0; i <=2 ; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ftab[i](target);		
		}
	}
	std::cout << "This form: " << name << " do not exist" << std::endl;
	return NULL;
}
