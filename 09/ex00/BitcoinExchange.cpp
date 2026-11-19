#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>n

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
}
bool	BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const;
double	BitcoinExchange::getEchangeRate(const std::string& date) const;