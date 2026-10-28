#include "AForm.hpp"

class PresidentialPardonAForm : public AForm
{
	public :
		PresidentialPardonAForm();
		PresidentialPardonAForm(const std::string& target);
		PresidentialPardonAForm(const PresidentialPardonAForm& other);
		PresidentialPardonAForm& operator=(const PresidentialPardonAForm& other);
		virtual ~PresidentialPardonAForm();

		virtual void		execute(Bureaucrat const& executor) const;
	
	private : 
		std::string 	_target;
};
