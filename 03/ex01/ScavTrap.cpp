#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_hithPoint = 100;
	this->_energyPoint = 50;
	this->_attackPoint = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{

	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " <<  this->_name <<" is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack no HP or energy left!" << std::endl;
		return ;
	}	
	this->_energyPoint -= 1;
	std::cout << "ScavTrap " << this->_name<< " attacks " << target << ", causing " << this->_attackPoint <<" points of damage!" << std::endl;
}