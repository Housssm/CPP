#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public :
		Cat();
		Cat(const Cat& other);
		Cat &operator=(const Cat& other);
		~Cat();

		void			makeSound()const ;
		std::string		getType() const;
		void			setIdea(const std::string& idea, int index);
		std::string		getIdea(int index) const;

	private :
		Brain*	_brain;
};