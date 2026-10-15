#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(), _brain(new(Brain))
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Cat constructor copy called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
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
			delete(this->_brain);
			this->_brain = NULL;
		}
	}
	std::cout << "Cat constructor called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete(_brain);
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}

void Cat::setIdea(const std::string& idea, int index)
{
	if (_brain)
		this->_brain->setIdeas(idea, index);
}
std::string	Cat::getIdea(int index) const
{
	if (_brain)
		return this->_brain->getIdeas(index);
	return "";
	
}
