#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(75), _gradeToExecute(75)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const std::string&name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1 )
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other)  : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{	
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if ( this != &other)
		_isSigned = other._isSigned;
	std::cout << "Form operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string&	Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

int		Form::getGradeToSign() const
{
	return _gradeToSign;
}

int		Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << " the grade to sign is :" << form.getGradeToSign() << " the grade to execute is :" << form.getGradeToExecute() << " the form is signed : " << form.getIsSigned() << ".";
	return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is to high" ;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is to low";
}

const char* Form::FormNotSignedException::what() const throw()
{
	return "Form not signed because the grade is to low";
}




void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if ( bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}
