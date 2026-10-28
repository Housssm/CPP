#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

PresidentialPardonAForm::PresidentialPardonAForm() : AForm("PresidentialPardonAForm", 25, 5) , _target("Default")
{
	std::cout << "PresidentialPardonAForm constructor called" << std::endl;
}

PresidentialPardonAForm::PresidentialPardonAForm(const std::string& target) : AForm("PresidentialPardonAForm", 25, 5) , _target(target)
{
	std::cout << "PresidentialPardonAForm constructor called" << std::endl;
}

PresidentialPardonAForm::PresidentialPardonAForm(const PresidentialPardonAForm& other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonAForm copy constructor called" << std::endl;
}

PresidentialPardonAForm& PresidentialPardonAForm::operator=(const PresidentialPardonAForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "PresidentialPardonAForm operator called" << std::endl;
	return *this;
}

PresidentialPardonAForm::~PresidentialPardonAForm()
{
	std::cout << "PresidentialPardonAForm destructor called" << std::endl;
}

void	PresidentialPardonAForm::execute(Bureaucrat const& executor) const
{	
	if (!this->getIsSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}




