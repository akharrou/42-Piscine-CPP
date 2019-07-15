
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Age {

	public:
		int _age;

		Age(int age_init) : _age(age_init) { }
};

int	main(void) {

	// typedef std::vector<Age>		ages_t;

	// int	const		ageconsts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	// size_t const	ageconsts_size( sizeof(ageconsts) / sizeof(int) );
	// ages_t			ages( ageconsts, ageconsts + ageconsts_size );

	// for (ages_t::iterator it = ages.begin(); it != ages.end(); ++it)
	// {
	// 	std::cout << "Age: " << it->_age << std::endl;
	// }

	// typedef std::vector<Account::t>							  accounts_t;
	// typedef std::vector<int>								  ints_t;
	// typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	// int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	// size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	// accounts_t				accounts( amounts, amounts + amounts_size );
	// accounts_t::iterator 	acc_begin	= accounts.begin();
	// accounts_t::iterator 	acc_end		= accounts.end();

	// int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	// size_t const		d_size( sizeof(d) / sizeof(int) );
	// ints_t				deposits( d, d + d_size );
	// ints_t::iterator 	dep_begin	= deposits.begin();
	// ints_t::iterator 	dep_end		= deposits.end();

	// int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	// size_t const		w_size( sizeof(w) / sizeof(int) );
	// ints_t				withdrawals( w, w + w_size );
	// ints_t::iterator 	wit_begin	= withdrawals.begin();
	// ints_t::iterator 	wit_end		= withdrawals.end();

	// Account::displayAccountsInfos();
	// std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// for ( acc_int_t it( acc_begin, dep_begin );
	// 	  it.first != acc_end && it.second != dep_end;
	// 	  ++(it.first), ++(it.second) ) {

	// 	(*(it.first)).makeDeposit( *(it.second) );
	// }

	// Account::displayAccountsInfos();
	// std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// for ( acc_int_t it( acc_begin, wit_begin );
	// 	  it.first != acc_end && it.second != wit_end;
	// 	  ++(it.first), ++(it.second) ) {

	// 	(*(it.first)).makeWithdrawal( *(it.second) );
	// }

	// Account::displayAccountsInfos();
	// std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	time_t		rawtime;
	struct tm	*date;
	std::string	datestr;

	rawtime = time(&rawtime);
	date = localtime(&rawtime);

	std::cout <<
		"[" <<
		std::to_string(1900 + date->tm_year) <<
		((std::to_string(date->tm_mon).length() < 2) ? "0" : "") <<
		std::to_string(date->tm_mon)         <<
		((std::to_string(date->tm_mday).length() < 2) ? "0" : "") <<
		std::to_string(date->tm_mday)        <<
		"_"                                  <<
		((std::to_string(date->tm_hour).length() < 2) ? "0" : "") <<
		std::to_string(date->tm_hour)        <<
		((std::to_string(date->tm_min).length() < 2) ? "0" : "") <<
		std::to_string(date->tm_min)         <<
		((std::to_string(date->tm_sec).length() < 2) ? "0" : "") <<
		std::to_string(date->tm_sec)         <<
		"] " <<
	std::endl;

	return 0;
}
