#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "---------------------" << std::endl;
	std::cout << "--- Test scavtrap  ---" << std::endl;
	std::cout << "---------------------" << std::endl;
	
	ScavTrap sa("Scav");

	std::cout << "PV: " << sa.getHit() << ", energy: " << sa.getEnergy() << std::endl;
	sa.guardGate();
	sa.attack("A");

	return 0;
}