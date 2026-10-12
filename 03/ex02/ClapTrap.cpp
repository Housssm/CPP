#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string name): _name(name)
{
	_hithPoint = 10;
	_energyPoint = 10;
	_attackPoint = 0;

	std::cout << "ClapTrap constructor called" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hithPoint = other._hithPoint;
	_energyPoint = other._energyPoint;
	_attackPoint = other._attackPoint;
	
	std::cout << "ClapTrap copy constructor called" << std::endl;
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
	std::cout << "ClapTrap destructor called " << this->_name << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hithPoint - amount > 0)
		this->_hithPoint -= amount;
	else
		this->_hithPoint -= 0;
	std::cout <<  this->_name <<" took " << amount << " of dammage" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << this->_name << " can't attack no HP or energy left!" << std::endl;
		return ;
	}
	this->_energyPoint -= 1;
	std::cout << this->_name<< " attacks " << target << ", causing " << this->_attackPoint <<" points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
		return ;
	this->_hithPoint += amount;
	this->_energyPoint -= 1;
	std::cout << this->_name << " repaired himself, loosing 1pt of energy and gained " << amount << " pt of health" << std::endl;
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