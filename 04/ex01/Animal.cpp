#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}


Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "Animal constructor copy called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
	this->type = other.type;
	}
	std::cout << "Animal constructor called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal is scared of you" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}