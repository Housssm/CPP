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
		void getHit();
		void getEnergy();
		void getAttack();


	private:

		std::string		_name;
		int				_hithPoint;//10
		int				_energyPoint;//10
		int				_attackPoint;//0
		
};
