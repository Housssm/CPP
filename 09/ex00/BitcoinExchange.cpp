#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <string>

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

void	BitcoinExchange::processInputFile(const std::string& filename) const
{

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
		std::string rateStr = line.substr(location + 1);
		if (!isValidDate(dateStr))
			throw std::runtime_error("Error : bad input => " + dateStr);

		std::istringstream iss(rateStr);
		double convertedValue = 0.0;
		if (!(iss >> convertedValue) || !iss.eof() || convertedValue < 0.0)
			throw std::runtime_error("Error : bad input => " + dateStr);
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


bool	BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const;
double	BitcoinExchange::getEchangeRate(const std::string& date) const;