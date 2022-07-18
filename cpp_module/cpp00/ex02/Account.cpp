#include "Account.hpp"
#include <time.h>
#include "iostream"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;	
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}
int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	t_now;
	struct tm* t;

	time(&t_now);
	t = (struct tm*)localtime(&t_now);
	std::cout << "[" << t->tm_year + 1900;
	if (t->tm_mon + 1 < 10)
		std::cout << "0" << t->tm_mon + 1;
	else
		std::cout << t->tm_mon + 1;
	if (t->tm_mday + 1 < 10)
		std::cout << "0" << t->tm_mday + 1;
	else
		std::cout << t->tm_mday + 1;
	std::cout << "_";
	if (t->tm_hour + 1 < 10)
		std::cout << "0" << t->tm_hour + 1;
	else
		std::cout << t->tm_hour + 1;
	if (t->tm_min + 1 < 10)
		std::cout << "0" << t->tm_min + 1;
	else
		std::cout << t->tm_min + 1;
	if (t->tm_sec + 1 < 10)
		std::cout << "0" << t->tm_sec + 1;
	else
		std::cout << t->tm_sec + 1;
	std::cout << "] ";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawal:" << _nbWithdrawals << std::endl;
		return (0);
	}
	else
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (1);
	}
}
int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}