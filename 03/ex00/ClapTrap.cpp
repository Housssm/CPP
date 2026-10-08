#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string name): _name(name)
{
	_hithPoint = 10;
	_energyPoint = 10;
	_attackPoint = 0;

	std::cout << "le nom de lhumain est: " << _name <<" il a " << _hithPoint << " de pv, " << _energyPoint<< " denergie, " << _attackPoint << " de point dattack\n" << std::endl;
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

// void attack(const std::string& target);
// void takeDamage(unsigned int amount);
// void beRepaired(unsigned int amount);
// void getHit();
// void getEnergy();
// void getAttack();
// void getName();

// std::string		_name;
// int				_hithPoint;//10
// int				_energyPoint;//10
// int				_attackPoint;//0

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hithPoint -= amount;
	std::cout <<  this->_name <<"took " << amount << "of dammage" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
		return ;
	std::cout << "ClapTrap " << this->_name<< " attacks " << target << ", causing " << this->_attackPoint <<" points of damage!" << std::endl;
	this->_energyPoint -= 1;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hithPoint == 0 || this->_energyPoint == 0)
	return ;
	this->_hithPoint += amount;
	this->_energyPoint -= 1;
	std::cout << this->_name << " repaired himself, loosing 1pt of energy and gained " << amount << " pt of health" << std::endl;
}

