#pragma once
#include <iostream>

class ClapTrap
{
	public :

		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getHit();
		unsigned int getEnergy();
		unsigned int getAttack();


	private:

		std::string		_name;
		unsigned int				_hithPoint;//10
		unsigned int				_energyPoint;//10
		unsigned int				_attackPoint;//0
		
};
