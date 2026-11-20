#pragma once
#include <iostream>
#include <map>


class BitcoinExchange
{
	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		void	processInputFile(const std::string& filename) const;

	private:
		std::map<std::string, double>	_data;

		void		loadDatabase(const std::string& dbPath);
		bool		isValidDate(const std::string& date) const;
		bool		isValidValue(const std::string& valueStr, double& value) const;
		double		getExchangeRate(const std::string& date) const;
		std::string trim(const std::string& str) const;
		
};