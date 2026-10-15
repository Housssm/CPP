#pragma once
#include <iostream>

class	Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal &operator=(const Animal& other);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
		
	protected:
		std::string type;
};