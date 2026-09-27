#pragma once

#include<iostream>

class Harl
{
	public :
		Harl();
		~Harl();
		int find_idx(std::string level);
		void ignore(const std::string& prompt);

	private :
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};