#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string name): _name(name)
{
	_hithPoint = 10;
	_energyPoint = 10;
	_attackPoint = 0;

	std::cout << "This robot's name is: " << _name <<" he got " << _hithPoint << " of HP, " << _energyPoint<< " of energy, " << _attackPoint << " of attack point\n" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hithPoint = 10;
	_energyPoint = 10;
	_attackPoint = 0;
	
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Operator called" << std::endl;
	if(this != &other)
	{
		this->_name = other._name;
		this->_hithPoint = other._hithPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackPoint = other._attackPoint;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called " << this->_name << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hithPoint >= amount)
		this->_hithPoint -= amount;
	else
		this->_hithPoint = 0;
	std::cout <<  this->_name <<" took " << amount << " of damage" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack: no hit points or energy points left!" << std::endl;
		return ;
	}
	this->_energyPoint -= 1;
	std::cout << this->_name<< " attacks " << target << ", causing " << this->_attackPoint <<" points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack: no hit points or energy points left!" << std::endl;
		return ;
	}
	this->_hithPoint += amount;
	this->_energyPoint -= 1;
	std::cout << this->_name << " repaired himself, losing 1pt of energy and gained " << amount << " pt of health" << std::endl;
}

unsigned int ClapTrap::getEnergy()
{
	return _energyPoint;
}

unsigned int ClapTrap::getHit()
{
	return _hithPoint;
}

unsigned int ClapTrap::getAttack()
{
	return _attackPoint;
}