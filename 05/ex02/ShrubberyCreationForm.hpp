#include "AForm.hpp"

class ShrubberyCreationAForm : public AForm
{
	public :
		ShrubberyCreationAForm();
		ShrubberyCreationAForm(const std::string& target);
		ShrubberyCreationAForm(const ShrubberyCreationAForm& other);
		ShrubberyCreationAForm& operator=(const ShrubberyCreationAForm& other);
		virtual ~ShrubberyCreationAForm();

		virtual void		execute(Bureaucrat const& executor) const;
	
	private : 
		std::string 	_target;
};
