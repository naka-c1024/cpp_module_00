#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// 静的メンバ変数は、インスタンスを生成しなくても呼び出すことができる。
// 静的メンバ変数の宣言はhppで、初期化はソースファイルで行われる。
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// public func

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts); // 静的メンバ変数だからthisは使えない
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	std::cout << "index:" << getNbAccounts()
		<< ";amount:" << initial_deposit
		<< ";created" << std::endl;

	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
}
Account::Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << getNbAccounts()
		<< ";amount:" << "0"
		<< ";created" << std::endl;

	this->_accountIndex = _nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
}
Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit << ";";

	this->_amount += deposit;
	(this->_nbDeposits)++;
	_totalNbDeposits ++;
	_totalAmount += deposit;

	std::cout << "amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = this->_amount;
	this->_amount -= withdrawal;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:";
	if (checkAmount())
	{
		(this->_nbWithdrawals)++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals ++;
		std::cout << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		return (true);
	}
	else
	{
		this->_amount = p_amount;
		std::cout << "refused" << std::endl;
		return (false);
	}
}
int		Account::checkAmount( void ) const
{
	return (this->_amount >= 0);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

// private func

void	Account::_displayTimestamp( void )
{
	time_t t = time(nullptr);
	const tm* localTime = localtime(&t);

	std::cout << "[";
	std::cout << localTime->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_sec;
	std::cout << "] ";
}
