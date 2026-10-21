#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
		_inventory[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if(this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{	
				delete _inventory[i];
				this->_inventory[i] = NULL;
			}
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	std::cout << "MateriaSource operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])	
				delete _inventory[i];
		}
	std::cout << "MateriaSource copy destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{	
			_inventory[i] = m;
			return;
		}
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}