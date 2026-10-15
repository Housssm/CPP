#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal(), _brain(new(Brain))
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}


Dog::Dog(const Dog &other): Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog constructor copy called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (other._brain)
		{
			if (this->_brain)
				*this->_brain = *other._brain;
			else
				this->_brain = new Brain(*other._brain);
		}
		else
		{
			delete (this->_brain);
			this->_brain = NULL;
		}
	}
	std::cout << "Dog constructor called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf Ouaf " << std::endl;
}

std::string Dog::getType() const
{
	return type;
}

void Dog::setIdea(const std::string& idea, int index)
{
	if (_brain)
		this->_brain->setIdeas(idea, index);
}
std::string	Dog::getIdea(int index) const
{
	if (_brain)
		return this->_brain->getIdeas(index);
	return "";
}