#include "AForm.hpp"

class RobotomyRequestAForm : public AForm
{
	public :
		RobotomyRequestAForm();
		RobotomyRequestAForm(const std::string& target);
		RobotomyRequestAForm(const RobotomyRequestAForm& other);
		RobotomyRequestAForm& operator=(const RobotomyRequestAForm& other);
		virtual ~RobotomyRequestAForm();

		virtual void		execute(Bureaucrat const& executor) const;
	
	private : 
		std::string 	_target;
};
