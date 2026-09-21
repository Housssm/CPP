	// static int	getNbAccounts( void );
	// static int	getTotalAmount( void );
	// static int	getNbDeposits( void );
	// static int	getNbWithdrawals( void );
	// static void	displayAccountsInfos( void );

	// Account( int initial_deposit );
	// ~Account( void );

	// void	makeDeposit( int deposit );
	// bool	makeWithdrawal( int withdrawal );
	// int		checkAmount( void ) const;
	// void	displayStatus( void ) const;

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
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] index:" << Account::getNbAccounts() << ";amount:" << checkAmount() << ";created"<< std::endl; 
}

Account::~Account( void )
{
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] index:" << Account::getNbAccounts() << ";amount:" << checkAmount() << ";created"<< std::endl; 

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
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		return true;
	}
	else
		return false;
}

int	Account::checkAmount(  void ) const
{
	return _amount;
}


void	Account::displayStatus( void ) const
{
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] index:" << Account::getNbAccounts() << ";amount:" << Account::getTotalAmount() << ";deposits:"<< Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl; 

}


void	Account::displayAccountsInfos( void )
{
	std::cout << "[";
	_displayTimestamp();
	std::cout<< "] accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:"<< Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl; 

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