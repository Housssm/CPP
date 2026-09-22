#include "Account.hpp"
#include <iostream>
#include <ctime>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalNbWithdrawals = 0;
	_totalNbDeposits = 0;
	_totalAmount += initial_deposit;

	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] index:" << Account::_accountIndex << ";amount:" << checkAmount() << ";created"<< std::endl; 
}

Account::~Account( void )
{
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] index:" << Account::_accountIndex << ";amount:" << checkAmount() << ";closed"<< std::endl; 

}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts ;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] index:" << Account::_accountIndex << ";p_amount:" << _amount << ";deposits:"<< deposit << ";amount:" << _amount + deposit << ";nb_deposit:" << _nbDeposits <<std::endl; 
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount+= deposit;

}

bool	Account::makeWithdrawal( int withdrawal )
{

	if (withdrawal <= _amount)
	{

		_nbWithdrawals++;

		std::cout << "[";
		_displayTimestamp();
		std::cout<< "] index:" << Account::_accountIndex << ";p_amount:" << _amount << ";withdrawal:"<< withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals <<std::endl; 
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "[";
		_displayTimestamp();
		std::cout<< "] index:" << Account::_accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" <<std::endl; 
		return (false);
	}
}

int	Account::checkAmount(  void ) const
{
	return _amount;
}


void	Account::displayStatus( void ) const
{
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] index:" << Account::_accountIndex << ";amount:" << _amount << ";deposits:"<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl; 

}


void	Account::displayAccountsInfos( void )
{
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:"<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl; 

}

void	Account::_displayTimestamp(void)
{
  time_t temps;
  struct tm datetime;
  char  format[32];
 
  time(&temps);
  datetime = *localtime(&temps);
 
  strftime(format, 32, "%Y%m%d_%H%M%S", &datetime);
 
  std::cout << format;
}