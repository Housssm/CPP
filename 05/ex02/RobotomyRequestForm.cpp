#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

RobotomyRequestAForm::RobotomyRequestAForm() : AForm("RobotomyRequestAForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestAForm constructor called" << std::endl;
}

RobotomyRequestAForm::RobotomyRequestAForm(const std::string& target) : AForm("RobotomyRequestAForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestAForm constructor called" << std::endl;
}

RobotomyRequestAForm::RobotomyRequestAForm(const RobotomyRequestAForm& other) : AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestAForm copy constructor called" << std::endl;
}

RobotomyRequestAForm& RobotomyRequestAForm::operator=(const RobotomyRequestAForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "RobotomyRequestAForm operator called" << std::endl;
	return *this;
}

RobotomyRequestAForm::~RobotomyRequestAForm()
{
	std::cout << "RobotomyRequestAForm destructor called" << std::endl;
}

void RobotomyRequestAForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << " *drilling noises* " << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy on " << this->_target << " failed" << std::endl;
}