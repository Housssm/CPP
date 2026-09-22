#include "Phonebook.class.hpp"

int	main(int ac,char **av)
{
	PhoneBook	Phonebook;

	std::string command;
	(void)av;
	if (ac > 1)
		return (0);

	while (true)
	{
		std::cout << "Enter a command :\n" << std::endl;
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			Phonebook.addContact();
		else if (command == "SEARCH")
		{
			Phonebook.searchContacts();
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Enter a correct prompt" << std::endl;
	}
	return 0;
}
