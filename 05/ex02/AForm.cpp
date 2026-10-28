#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(75), _gradeToExecute(75)
{
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const std::string&name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1 )
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other)  : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{	
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if ( this != &other)
		_isSigned = other._isSigned;
	std::cout << "AForm operator called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

const std::string&	AForm::getName() const
{
	return _name;
}

bool	AForm::getIsSigned() const
{
	return _isSigned;
}

int		AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int		AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << AForm.getName() << " the grade to sign is :" << AForm.getGradeToSign() << " the grade to execute is :" << AForm.getGradeToExecute() << " the AForm is signed : " << AForm.getIsSigned() << ".";
	return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is to high" ;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is to low";
}

const char* AForm::AFormNotSignedException::what() const throw()
{
	return "AForm not signed because the grade is to low";
}




void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if ( bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}
