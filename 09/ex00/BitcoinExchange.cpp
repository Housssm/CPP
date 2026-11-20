#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	this->loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}


std::string BitcoinExchange::trim(const std::string& str) const
{
	std::string::size_type first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	std::string::size_type last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

void	BitcoinExchange::processInputFile(const std::string& filename) const
{
	std::ifstream input(filename.c_str());
	if (!input.is_open())
		{throw std::runtime_error("Error: could not open file.");}

	std::string line;
	bool isFirstLine = true;

	while(std::getline(input, line))
	{
		if (trim(line).empty())
			continue;

		if (isFirstLine)
		{
			isFirstLine = false;
			if (trim(line) == "data | value")
				continue;
		}

		std::string::size_type location = line.find('|');
		if (location == std::string::npos)
		{
			std::cout << "Error: bad input => " <<  line << std::endl;
			continue;
		}

		std::string dateStr = trim(line.substr(0, location));
		std::string valueStr = trim(line.substr(location + 1));
		if (!isValidDate(dateStr))
		{
			std::cout << "Error: bad input => " + dateStr << std::endl;
			continue;
		}
		double convertedValue = 0.0;
		if (!isValidValue(valueStr, convertedValue))
			continue;
		
		double btcValue = getExchangeRate(dateStr);
		if (btcValue < 0.0)
			continue;
		std::cout << dateStr + " => "<< convertedValue << " = " << (btcValue * convertedValue) << std::endl;
	}
	if (isFirstLine)
		{throw std::runtime_error("Error: file is empty.");}

}

void	BitcoinExchange::loadDatabase(const std::string& dbPath)
{
	std::ifstream dataCopy(dbPath.c_str());
	if (!dataCopy.is_open())
	{throw std::runtime_error("Error: could not open database file.");}

	std::string line;
	if (!std::getline(dataCopy, line))
	{throw std::runtime_error("Error: database file is empty.");}

	while(std::getline(dataCopy, line))
	{
		if (line.empty())
			continue;
	
		std::string::size_type location = line.find(',');
		if (location == std::string::npos)
			throw std::runtime_error("Error: invalid format in database.");

		std::string dateStr = line.substr(0, location);
		std::string valueStr = line.substr(location + 1);
		if (!isValidDate(dateStr))
			throw std::runtime_error("Error: bad input => " + dateStr);

		std::istringstream iss(valueStr);
		double convertedValue = 0.0;

		
		if (!(iss >> convertedValue) || !iss.eof() || convertedValue < 0.0)
			throw std::runtime_error("Error: bad input => " + dateStr);
		_data.insert(std::make_pair(dateStr, convertedValue));
	}
	if (_data.empty())
		throw std::runtime_error("Error: database contains no valid data.");

}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			i++;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
		int year = std::atoi(date.substr(0,4).c_str());
		int month = std::atoi(date.substr(5,2).c_str());
		int day = std::atoi(date.substr(8,2).c_str());

		if (year < 2009)
			return false;
		if (month < 1 || month > 12 || day < 1)
			return false;
		int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (isLeap)
			daysInMonth[1] = 29;
		if (day > daysInMonth[month - 1])
			return false;
		return true;
}

bool	BitcoinExchange::isValidValue(const std::string& valueStr, double& convertedValue) const
{
	if (valueStr.empty())
	{
		std::cout << "Error: bad input => " + valueStr << std::endl;
		return false;
	}
	std::istringstream iss(valueStr);
	if (!(iss >> convertedValue) || !iss.eof())
	{
		std::cout << "Error: bad input => " + valueStr << std::endl;
		return false;
	}
	else if (convertedValue < 0.0)
	{
		std::cout << "Error: not a positive number." <<std::endl;
		return false;
	}
	else if (convertedValue > 1000)
	{
		std::cout << "Error: too large a number." <<std::endl;
		return false;
	}
	return true;
}

double	BitcoinExchange::getExchangeRate(const std::string& date) const
{
	double btcValue = -1.0;
	std::map<std::string, double>::const_iterator itlow = _data.lower_bound(date);
	if (itlow != _data.end() && itlow->first == date)
		btcValue = itlow->second;
	else if(itlow != _data.begin())
	{
		--itlow;
		btcValue = itlow->second;
	}
	else
		std::cout << "Error: on data for => " << date << std::endl;
	return btcValue;
}