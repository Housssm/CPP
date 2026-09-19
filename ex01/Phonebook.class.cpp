#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "Phonebook.class.hpp"

PhoneBook::PhoneBook(): _index(0), _total(0)
{
}

PhoneBook::~PhoneBook()
{
}


static std::string formate(const std::string& prompt)
{
	if (prompt.length() > 10)
		return (prompt.substr(0,9) + ".");
	return (prompt);
}
static std::string	getInput(const std::string& prompt)
{
	std::string	input;

	while(true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return "";
		if (!input.empty() && input.find_first_not_of(" \t\n\r") != std::string::npos)
			return (input);
		std::cout << "Field cannot empty. Please try again" << std::endl;
	}
}

void	PhoneBook::addContact()
{
	std::string first = getInput("Enter first name:");
	if (std::cin.eof()) return ;

	std::string last = getInput("Enter lastname:");
	if (std::cin.eof()) return;

	std::string nick = getInput("Enter nickname :");
	if (std::cin.eof()) return ;

	std::string number = getInput("Enter phone number :");
	if (std::cin.eof()) return ;

	std::string dark = getInput("Enter darkest secret :");
	if (std::cin.eof()) return ;

	_contacts[_index].setFirstName(first);
	_contacts[_index].setLastName(last);
	_contacts[_index].setNickName(nick);
	_contacts[_index].setPhoneNumber(number);
	_contacts[_index].setDarkestSecret(dark);

	_index = (_index + 1) % 8;
	if (_total < 8)
		_total++;
	std::cout << "Contact successfully added!" << std::endl;
}

void	PhoneBook::searchContacts() const
{
	if (_total == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	for (int i = 0; i < _total; i++)
	{	
		std::cout <<  "|" << i << "|"; 
		std::cout << std::setw(10) << formate(_contacts[i].getFirstName()) << "|"; 
		std::cout << std::setw(10) << formate(_contacts[i].getLastName())  << "|";
		std::cout << std::setw(10) << formate(_contacts[i].getNickName())  << "|" << std::endl;
	}
	std::string index = getInput("Enter the contact's index: ");
	if (std::cin.eof())
		return ;
	std::stringstream inpt(index);
	int idx = -1;
	if ( !(inpt >> idx) || !inpt.eof() || idx < 0 || idx >= _total )
	{	
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	else
	{

		std::cout << "First name :" << _contacts[idx].getFirstName() << std::endl; 
		std::cout << "Last name :" <<_contacts[idx].getLastName() << std::endl ;
		std::cout << "Nickname :" <<_contacts[idx].getNickName()  <<  std::endl;
		std::cout << "Phone number : :" <<_contacts[idx].getNickName() <<  std::endl;
		std::cout << "Darkest secret :" <<_contacts[idx].getNickName() <<  std::endl;

	}
}



