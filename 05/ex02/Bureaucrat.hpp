#pragma once
#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				signForm(Form& form);
		void				incrementGrade();
		void				decrementGrade();
		void				executeForm(AForm const& form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private :
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat& bureaucrat);
