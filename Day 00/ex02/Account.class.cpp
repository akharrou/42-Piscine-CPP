// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Mon Jul 15 11:36:43 2019                      //
//                Last update : Mon Jul 15 3:25:01 2019                       //
//                Made by : akharrou                                          //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                           Account Class Definition                         //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Account.class.hpp"


/* CONSTRUCTORS / DECONSTRUCTORS — — — — — — — — — — — — — — — — — — — — — — */

Account::Account( int initial_deposit ) :
	_accountIndex(Account::_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:"  << _accountIndex << ";"
			  << "amount:"  << _amount       << ";"
			  << "created"  <<
	std::endl;
}

Account::Account( void ) :
	_accountIndex(Account::_nbAccounts++),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:"  << _accountIndex << ";"
			  << "amount:"  << _amount       << ";"
			  << "created"  <<
	std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:"  << _accountIndex << ";"
			  << "amount:"  << _amount       << ";"
			  << "closed"   <<
	std::endl;
}


/* MEMBER FUNCTIONS — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:"      << _accountIndex     << ";"
			  << "p_amount:"    << _amount           << ";"
			  << "deposit:"     << deposit           << ";"
			  << "amount:"      << _amount + deposit << ";"
			  << "nb_deposits:" << 1                 <<
	std::endl;

	_amount += deposit;
	++_nbDeposits;

	_totalAmount += deposit;
	++_totalNbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:"             << _accountIndex << ";"
			  << "p_amount:"           << _amount       << ";"
	<< std::flush;

	if (_amount - withdrawal < 0) {

		std::cout << "withdrawal:refused" << std::endl;
		return (false);

	} else {

		_amount -= withdrawal;
		++_nbWithdrawals;

		_totalAmount -= withdrawal;
		++_totalNbWithdrawals;

		std::cout << "withdrawal:"     << withdrawal    << ";"
				  << "amount:"         << _amount       << ";"
				  << "nb_withdrawals:" << 1             <<
		std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	_checkAmountCallCount++;
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:"      << _accountIndex  << ";"
			  << "amount:"      << _amount        << ";"
			  << "deposits:"    << _nbDeposits    << ";"
			  << "withdrawals:" << _nbWithdrawals <<
	std::endl;
}


/* STATIC CLASS FUNCTIONS — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Account::_displayTimestamp( void )
{
	time_t		rawtime;
	struct tm	*date;
	std::string	datestr;

	rawtime = time(&rawtime);
	date = localtime(&rawtime);
	std::cout <<
		"["                                                       <<
		std::to_string(1900 + date->tm_year)                      <<
		((std::to_string(date->tm_mon).length() < 2) ? "0" : "")  <<
		std::to_string(date->tm_mon)                              <<
		((std::to_string(date->tm_mday).length() < 2) ? "0" : "") <<
		std::to_string(date->tm_mday)                             <<
		"_"                                                       <<
		((std::to_string(date->tm_hour).length() < 2) ? "0" : "") <<
		std::to_string(date->tm_hour)                             <<
		((std::to_string(date->tm_min).length() < 2) ? "0" : "")  <<
		std::to_string(date->tm_min)                              <<
		((std::to_string(date->tm_sec).length() < 2) ? "0" : "")  <<
		std::to_string(date->tm_sec)                              <<
		"]"                                                       <<
	std::flush;
	return ;
}

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:"   << getNbAccounts()    << ";"
			  << "total:"       << getTotalAmount()   << ";"
			  << "deposits:"    << getNbDeposits()    << ";"
			  << "withdrawals:" << getNbWithdrawals() <<
	std::endl;
}


/* STATIC CLASS VARIABLES — — — — — — — — — — — — — — — — — — — — — — — — — — */

int	Account::_nbAccounts           = 0;
int	Account::_totalAmount          = 0;
int	Account::_totalNbDeposits      = 0;
int	Account::_totalNbWithdrawals   = 0;

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — - */

int	Account::_checkAmountCallCount = 0;

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — - */
