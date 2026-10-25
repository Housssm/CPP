#pragma once
#include <iostream>

class Form
{
	public :
		Form();
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		void	getName();
		bool	getIsSigned();
		void	getToSign();
		void	getToExecute();
		void	beSigned(const Bureaucrat& bureaucrat);

		class
	
	private : 
		const std::string 	_name;
		bool				_isSigned;
		const int			_formToSigne;
		const int			_formToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& form);