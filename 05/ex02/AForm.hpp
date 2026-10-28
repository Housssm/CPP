#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm(const std::string& name, int gradeSign, int gradeExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class AFormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	private : 
		const std::string 	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);