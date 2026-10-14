// #include "ClapTrap.hpp"
// #include "ScavTrap.hpp"
// #include "FragTrap.hpp"

// int main()
// {
// 	// ClapTrap a("Alpha");
// 	// ClapTrap b("Beta");

// 	// std::cout << "PV: " << a.getHit() << ", energy: " << a.getEnergy() << std::endl;
// 	// a.takeDamage(4);
// 	// a.attack("target");
// 	// std::cout << "PV: " << a.getHit() << ", energy: " << a.getEnergy() << std::endl;

// 	// std::cout << "\n--- Test Opérateur d'affectation (b = a) ---" << std::endl;
// 	// b = a;

// 	// std::cout << "\n--- Vérification du comportement de b ---" << std::endl;
// 	// b.attack("un mannequin");
// 	// b.beRepaired(2);
// 	// std::cout << "PV: " << b.getHit() << ", energy: " << b.getEnergy() << std::endl;


// 	// std::cout << "\n--- Test d'auto-assignation  ---" << std::endl;
// 	// a = a;

// 	// std::cout << "\n--- Test scavtrap  ---\n" << std::endl;
	
// 	// ScavTrap sa("Scav");

// 	// std::cout << "PV: " << sa.getHit() << ", energy: " << sa.getEnergy() << std::endl;
// 	// sa.guardGate();
// 	// sa.attack("A");


// 	// std::cout << "\n--- Test fragtrap  ---\n" << std::endl;
// 	// FragTrap fg("Frag");
// 	// fg.highFivesGuys();
// 	// fg.attack("ScavTrap");

// 	return 0;
// }

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "  1. Test de Construction & Chaining    " << std::endl;
    std::cout << "========================================" << std::endl;
    {
        // Vérifie l'ordre de construction :
        // ClapTrap (1 SEULE fois) -> ScavTrap -> FragTrap -> DiamondTrap
        DiamondTrap dt("Monster");

        std::cout << "\n--- Vérification de whoAmI() ---" << std::endl;
        // Doit afficher à la fois "Monster" et "Monster_clap_name"
        dt.whoAmI();

        std::cout << "\n--- Vérification des Statistiques ---" << std::endl;
        // Attendu :
        // - HP : 100 (FragTrap)
        // - Energy : 50 (ScavTrap)
        // - Attack : 30 (FragTrap)
        std::cout << "PV     : " << dt.getHit() << " (attendu: 100)" << std::endl;
        std::cout << "Energy : " << dt.getEnergy() << " (attendu: 50)" << std::endl;
        std::cout << "Attack : " << dt.getAttack() << " (attendu: 30)" << std::endl;

        std::cout << "\n--- Vérification de l'Attaque ---" << std::endl;
        // Doit appeler l'attaque de ScavTrap, enlever 1 pt d'énergie et infliger 30 pts
        dt.attack("un mannequin d'entrainement");
        std::cout << "Energy restante : " << dt.getEnergy() << " (attendu: 49)" << std::endl;

        std::cout << "\n--- Vérification des Capacités Spéciales Héritées ---" << std::endl;
        dt.guardGate();      // Hérité de ScavTrap
        dt.highFivesGuys();  // Hérité de FragTrap

        std::cout << "\n--- Sortie de scope : Destruction ---" << std::endl;
        // Ordre inverse : DiamondTrap -> FragTrap -> ScavTrap -> ClapTrap (1 SEULE fois)
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "  2. Forme Canonique (Copie & Affectation)" << std::endl;
    std::cout << "========================================" << std::endl;
    {
        DiamondTrap original("Prime");
        original.takeDamage(20);

        std::cout << "\n--- Test Constructeur de Recopie ---" << std::endl;
        DiamondTrap copy(original);
        copy.whoAmI();
        std::cout << "PV de la copie : " << copy.getHit() << " (attendu: 80)" << std::endl;

        std::cout << "\n--- Test Opérateur d'Affectation (=) ---" << std::endl;
        DiamondTrap assigned("Dummy");
        assigned = original;
        assigned.whoAmI();
        std::cout << "PV après assignation : " << assigned.getHit() << " (attendu: 80)" << std::endl;

        std::cout << "\n--- Sortie de scope ---" << std::endl;
    }

    return 0;
}

