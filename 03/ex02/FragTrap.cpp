#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	this->_hithPoint = 100;
	this->_energyPoint = 100;
	this->_attackPoint = 50;

	std::cout << "FragTrap " << name << " constructor called" << std::endl;

}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap " << _name << "copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		FragTrap::operator=(other);
	}
	std::cout << "FragTrap operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " joyfully requests: Give me a high five, guys!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << this->_name << " can't attack no HP or energy left!" << std::endl;
		return ;
	}	
	this->_energyPoint -= 1;
	std::cout << this->_name<< " attacks " << target << ", causing " << this->_attackPoint <<" points of damage!" << std::endl;
}