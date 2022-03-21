#include "Account.hpp"
#include <iostream>
#include <iomanip>

// 静的メンバ変数は、インスタンスを生成しなくても呼び出すことができる。
// 静的メンバ変数の宣言はhppで、初期化はソースファイルで行われる。
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// public func

int	Account::getNbAccounts( void )
{

}
int	Account::getTotalAmount( void )
{

}
int	Account::getNbDeposits( void )
{

}
int	Account::getNbWithdrawals( void )
{

}
void	Account::displayAccountsInfos( void )
{

}

Account::Account( int initial_deposit )
{

}
Account::~Account( void )
{

}

void	Account::makeDeposit( int deposit )
{

}
bool	Account::makeWithdrawal( int withdrawal )
{

}
int		Account::checkAmount( void ) const
{

}
void	Account::displayStatus( void ) const
{

}

// private func

void	Account::_displayTimestamp( void )
{

}

Account::Account( void )
{

}
