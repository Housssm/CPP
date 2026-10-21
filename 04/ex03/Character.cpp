#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const std::string& name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other): _name(other._name)
{
	for (int i = 0, i < 4; i ++)
	{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other._name
		for (int i = 0, i < 4; i ++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i]
				this->_inventory = NULL
			}
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character copy operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0, i < 4; i ++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{

		}
	}
	return ;
}
void Character::unequip(int idx);
void Character::use(int idx, ICharacter& target);