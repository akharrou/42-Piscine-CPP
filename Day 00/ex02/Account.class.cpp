// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Mon Jul 15 11:36:43 2019                      //
//                Last update : Mon Jul 15 11:36:43 2019                      //
//                Made by : akharrou                                          //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                           Account Class Definition                         //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ressources/Account.class.hpp"


/* CONSTRUCTORS / DECONSTRUCTORS — — — — — — — — — — — — — — — — — — — — — — */

Account::Account( int initial_deposit ) :
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
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
		"] "                                                      <<
		"index:"	<< Account::_nbAccounts << ";"                <<
		"amount:"	<< initial_deposit 		<< ";"                <<
		"created"   <<
	std::endl;
}

Account::Account( void ) :
	_accountIndex(Account::_nbAccounts),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
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
		"] "                                                      <<
		"index:"	<< Account::_nbAccounts << ";"                <<
		"amount:"	<< 0 		<< ";"                            <<
		"created"   <<
	std::endl;
}

Account::~Account( void )
{

}


/* ACCESSORS (static class functions) — — — — — — — — — — — — — — — — — — — */

int		Account::getNbAccounts( void )
{

	return (/* int */);
}

int		Account::getTotalAmount( void )
{

	return (/* int */);
}

int		Account::getNbDeposits( void )
{

	return (/* int */);
}

int		Account::getNbWithdrawals( void )
{

	return (/* int */);
}

void		Account::displayAccountsInfos( void )
{

}


/* OTHER MEMBER FUNCTIONS — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

	return (/* bool */);
}

int		Account::checkAmount( void ) const
{

	return (/* int */);
}


/* STATIC CLASS FUNCTION — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Account::displayStatus( void ) const
{

}


/* STATIC CLASS VARIABLES — — — — — — — — — — — — — — — — — — — — — — — — — — */

int	_nbAccounts         = 0;
int	_totalAmount        = 0;
int	_totalNbDeposits    = 0;
int	_totalNbWithdrawals = 0;
