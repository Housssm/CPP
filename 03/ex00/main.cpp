// #include "ClapTrap.hpp"
// #include <iostream>

// int main()
// {
// 	ClapTrap a("Mahfoud");
// 	ClapTrap b("Mahjoub");
// 	ClapTrap c = b;
// 	b = a;




// 	return 0;
// }


#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Initialisation ---" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    // On modifie l'état de 'a' pour qu'il ne soit plus aux valeurs par défaut
    a.takeDamage(4);  // HP passe à 6
    a.attack("target"); // Energy passe à 9

    std::cout << "\n--- Test Opérateur d'affectation (b = a) ---" << std::endl;
    b = a;

    std::cout << "\n--- Vérification du comportement de b ---" << std::endl;
    // Si b a bien copié les stats de 'a' (6 HP, 9 Energy, nom "Alpha"),
    // il doit réagir en conséquence :
    b.attack("un mannequin");
    b.beRepaired(2);

    std::cout << "\n--- Test d'auto-assignation (a = a) ---" << std::endl;
    a = a; // Ne doit ni crasher ni altérer l'état

    std::cout << "\n--- Fin du programme (destructions) ---" << std::endl;
    return 0;
}