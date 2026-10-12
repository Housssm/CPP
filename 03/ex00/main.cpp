#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	std::cout << "PV: " << a.getHit() << ", energy: " << a.getEnergy() << std::endl;
	a.takeDamage(4);
	a.attack("target");
	std::cout << "PV: " << a.getHit() << ", energy: " << a.getEnergy() << std::endl;

	std::cout << "\n--- Test Opérateur d'affectation (b = a) ---" << std::endl;
	b = a;

	std::cout << "\n--- Vérification du comportement de b ---" << std::endl;
	b.attack("un mannequin");
	b.beRepaired(2);
	std::cout << "PV: " << b.getHit() << ", energy: " << b.getEnergy() << std::endl;


	std::cout << "\n--- Test d'auto-assignation (a = a) ---" << std::endl;
	a = a;

	return 0;
}