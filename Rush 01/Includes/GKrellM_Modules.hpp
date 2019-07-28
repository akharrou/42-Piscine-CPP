/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Modules.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 10:56:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 14:56:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULES_HPP
# define MODULES_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <string>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMonitorModule.hpp"
# include "GKrellM.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct GeneralInfo_Module :
	public IMonitorModule {

	std::string name;

	private:
		GeneralInfo_Module( const GeneralInfo_Module & src );
		GeneralInfo_Module & operator = ( const GeneralInfo_Module & rhs );

		time_t timestr;

		std::string Datetime;
		std::string Username;
		std::string Hostname;
		std::string OS_Name;
		std::string OS_Release;
		std::string Platform;

	public:

		GeneralInfo_Module( void );
		~GeneralInfo_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct CPU_Module :
	public IMonitorModule {

	std::string name;

	private:
		CPU_Module(const CPU_Module &src);
		CPU_Module &operator=(const CPU_Module &rhs);

		std::ifstream CPU_infile;
		std::string   CPU_usage;

		char	*CPU_model;
		int32_t CPU_coreCount;
		int32_t CPU_threadCount;
		int32_t CPU_cacheSize;

	public:
		CPU_Module( void );
		~CPU_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct RAM_Module :
	public IMonitorModule {

	std::string name;

	private:
		RAM_Module( const RAM_Module & src );
		RAM_Module & operator = ( const RAM_Module & rhs );

		std::ifstream RAM_infile;
		std::string   RAM_usage;

	public:
		RAM_Module( void );
		~RAM_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Network_Module :
	public IMonitorModule {

	std::string name;

	private:
		Network_Module( const Network_Module & src );
		Network_Module & operator = ( const Network_Module & rhs );

		std::ifstream NETWORK_infile;
		std::string   NETWORK_activity;

	public:
		Network_Module( void );
		~Network_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Processes_Module :
	public IMonitorModule {

	std::string name;

	private:
		Processes_Module( const Processes_Module & src );
		Processes_Module & operator = ( const Processes_Module & rhs );

		std::ifstream PROCESSES_infile;
		std::string   PROCESSES_activity;

	public:
		Processes_Module( void );
		~Processes_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Zaz_Module :
	public IMonitorModule {

	std::string name;

	private:
		Zaz_Module( const Zaz_Module & src );
		Zaz_Module & operator = ( const Zaz_Module & rhs );

		std::string unicornFrame[5];
		std::string unicorn;

	public:
		Zaz_Module( void );
		~Zaz_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MODULES_HPP */
