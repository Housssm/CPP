#include "Phonebook.class.hpp"

int	main()
{
	PhoneBook	Phonebook;

	std::string command;

	while (true)
	{
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
