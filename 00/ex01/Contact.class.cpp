#include "Contact.class.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(const std::string& str)
{
	_first_name = str;
}
void	Contact::setLastName(const std::string& str)
{
	_last_name = str;
}

void	Contact::setNickName(const std::string& str)
{
	_nickname = str;
}

void	Contact::setPhoneNumber(const std::string& str)
{
	_phone_number = str;
}

void	Contact::setDarkestSecret(const std::string& str)
{
	_darkest_secret = str;
}


std::string	Contact::getFirstName() const
{
	return _first_name;
};

std::string	Contact::getLastName() const
{
	return _last_name;
};
std::string	Contact::getNickName() const
{
	return _nickname;
};
std::string	Contact::getPhoneNumber() const
{
	return _phone_number;
};
std::string	Contact::getDarkestSecret() const
{
	return _darkest_secret;
};