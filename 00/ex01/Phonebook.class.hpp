#pragma once

#include <iostream>
#include "Contact.class.hpp"


class PhoneBook
{
	private :
	Contact	_contacts[8];
	int		_index;
	int		_total;

	public :
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContacts()const;
	void	displayContact(std::string index)const;
};
