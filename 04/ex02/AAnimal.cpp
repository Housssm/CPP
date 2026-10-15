#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	type = "AAnimal";
	std::cout << "AAnimal constructor called" << std::endl;
}


AAnimal::AAnimal(const AAnimal &other)
{
	this->type = other.type;
	std::cout << "AAnimal constructor copy called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
	this->type = other.type;
	}
	std::cout << "AAnimal constructor called" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal is scared of you" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}