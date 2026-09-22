#pragma once
#include <iostream>
#include <string>

class Contact
{
	public:
	Contact();
	~Contact();
	
	void	setFirstName(const std::string& str);
	void	setLastName(const std::string& str);
	void	setNickName(const std::string& str);
	void	setPhoneNumber(const std::string& str);
	void	setDarkestSecret(const std::string& str);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	private :
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_phone_number;
	std::string		_darkest_secret;

};