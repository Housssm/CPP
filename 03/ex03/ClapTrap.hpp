#pragma once
#include <iostream>

class ClapTrap
{
	public :

		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap& other);
		virtual ~ClapTrap();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getHit();
		unsigned int getEnergy();
		unsigned int getAttack();
	
	protected: 
		std::string					_name;
		unsigned int				_hithPoint;
		unsigned int				_energyPoint;
		unsigned int				_attackPoint;
		
};
