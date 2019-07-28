/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Modules.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 10:56:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:27:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULES_HPP
# define MODULES_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "GKrellM.hpp"
# include "AMonitorModule.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct GeneralInfo_Module :
	public AMonitorModule {

	private:
		GeneralInfo_Module( void );

		time_t timestr;

		std::string Datetime;
		std::string Username;
		std::string Hostname;
		std::string OS_Name;
		std::string OS_Release;
		std::string Platform;

	public:
		GeneralInfo_Module( screen_t );
		~GeneralInfo_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct CPU_Module :
	public AMonitorModule {

	private:
		CPU_Module( void );

		std::ifstream CPU_infile;
		std::string   CPU_usage;

		char	*CPU_model;
		int32_t CPU_coreCount;
		int32_t CPU_threadCount;
		int32_t CPU_cacheSize;

	public:
		CPU_Module( screen_t );
		~CPU_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct RAM_Module :
	public AMonitorModule {

	private:
		RAM_Module( void );

		std::ifstream RAM_infile;
		std::string   RAM_usage;

	public:
		RAM_Module( screen_t );
		~RAM_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Network_Module :
	public AMonitorModule {

	private:
		Network_Module( void );

		std::ifstream NETWORK_infile;
		std::string   NETWORK_activity;

	public:
		Network_Module( screen_t );
		~Network_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Processes_Module :
	public AMonitorModule {

	private:
		Processes_Module( void );

		std::ifstream PROCESSES_infile;
		std::string   PROCESSES_activity;

	public:
		Processes_Module( screen_t );
		~Processes_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Zaz_Module :
	public AMonitorModule {

	private:
		Zaz_Module( void );

		std::string unicornFrame[5];
		std::string unicorn;

	public:
		Zaz_Module( screen_t );
		~Zaz_Module( void );

		void	update ();
		void	render ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MODULES_HPP */
