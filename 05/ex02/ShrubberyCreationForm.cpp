#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationAForm::ShrubberyCreationAForm() : AForm("ShrubberyCreationAForm", 145, 137) , _target("Default")
{
	std::cout << "ShrubberyCreationAForm constructor called" << std::endl;
}

ShrubberyCreationAForm::ShrubberyCreationAForm(const std::string& target) : AForm("ShrubberyCreationAForm", 145, 137) , _target(target)
{
	std::cout << "ShrubberyCreationAForm constructor called" << std::endl;
}

ShrubberyCreationAForm::ShrubberyCreationAForm(const ShrubberyCreationAForm& other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationAForm copy constructor called" << std::endl;
}

ShrubberyCreationAForm& ShrubberyCreationAForm::operator=(const ShrubberyCreationAForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "ShrubberyCreationAForm operator called" << std::endl;
	return *this;
}

ShrubberyCreationAForm::~ShrubberyCreationAForm()
{
	std::cout << "ShrubberyCreationAForm destructor called" << std::endl;
}

void	ShrubberyCreationAForm::execute(Bureaucrat const& executor) const
{	
	if (!this->getIsSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error opening file " << filename << std::endl;
		return;
	}
	outfile <<		 "___________\n"
			<<		"/			\\\n"
			<<		"|			|\n"
			<<		"|			|\n"
			<<		"\\			/\n"
			<<		 "-_________-\n"
			<<		 	"|  |\n"
			<<		 	"|  |\n"
			<<		 	"|  |\n"
			<<		    "/  \\\n";
	outfile.close();
}




