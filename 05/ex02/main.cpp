#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
    std::srand(std::time(NULL));


    Bureaucrat intern("Stagiaire", 150);
    Bureaucrat manager("Farid", 24);
    Bureaucrat boss("Directeur", 1);

    ShrubberyCreationForm shrub("jardin");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

	std::cout << std::endl;
	std::cout << std::endl;

    std::cout << intern << std::endl;
    std::cout << manager << std::endl;
    std::cout << boss << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;
    std::cout << std::endl;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "--- TEST 1 : FORM PAS SIGNE ---" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    try
    {
        boss.executeAForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        pardon.execute(boss);
    }
    catch (std::exception& e)
    {
        std::cerr << "Attrape en direct : " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "---TEST 2 : SIGNATURES PAR DIFFERENTS GRADES ---" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    try
    {
        intern.signForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        manager.signForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        manager.signForm(robot);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        manager.signForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;


	std::cout << "-------------------------" << std::endl;
    std::cout << "--- FORMULAIRES SIGNES---" << std::endl;    
	std::cout << "-------------------------" << std::endl;

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;
    std::cout << std::endl;


    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "--- TEST 3 : EXECUTION PAR UN GRADE TROP BAS ---" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    try
    {
        manager.executeAForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        pardon.execute(manager);
    }
    catch (std::exception& e)
    {
        std::cerr << "Error message : " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "--- TEST 4 : EXECUTIONS VALIDES PAR LE BOSS ---" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    try
    {
        boss.executeAForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        boss.executeAForm(robot);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
    {
        boss.executeAForm(robot);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
    {
        boss.executeAForm(robot);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        boss.executeAForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;    

    return 0;
}