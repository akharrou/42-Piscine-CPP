/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:05:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 00:05:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <stdlib.h>
#include <unistd.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysctl.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

using namespace std;
using namespace std::chrono;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int main() {

    /* sysctlbyname(const char *name, void *oldp, size_t *oldlenp, void *newp, size_t newlen) */

	struct utsname uts;
	size_t len = 100;

	char	*CPU_model;
	int32_t CPU_coreCount;
	int32_t CPU_threadCount;
	int32_t CPU_cacheSize;

	int32_t l1dcachesize;
	int32_t l1icachesize;
	int32_t l2cachesize;
	int32_t l3cachesize;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	uname(&uts);

	sysctlbyname("hw.l1dcachesize", &l1dcachesize, &len, NULL, 0);
	sysctlbyname("hw.l1icachesize", &l1icachesize, &len, NULL, 0);
	sysctlbyname("hw.l2cachesize", &l2cachesize, &len, NULL, 0);
	sysctlbyname("hw.l3cachesize", &l3cachesize, &len, NULL, 0);

	sysctlbyname("machdep.cpu.core_count", &CPU_coreCount, &len, NULL, 0);
	sysctlbyname("machdep.cpu.thread_count", &CPU_threadCount, &len, NULL, 0);
	sysctlbyname("machdep.cpu.cache.size", &CPU_cacheSize, &len, NULL, 0);

	sysctlbyname("machdep.cpu.brand_string", NULL, &len, NULL, 0);
	CPU_model = (char *)malloc(len);
	sysctlbyname("machdep.cpu.brand_string", CPU_model, &len, NULL, 0);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	std::ifstream infile;
	std::string line;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	duration<double> time_span;
	std::time_t t;

	while (1) {

		t1 = high_resolution_clock::now();

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
		std::cout << "/* GENERAL INFORMATION */\n\n";

		std::cout << "Datetime : " << std::ctime(&(t = system_clock::to_time_t(system_clock::now()))) << "\n";

		cout << "Username : "   << getenv("USER")           << "\n";
		cout << "Hostname : "   << getenv("HOSTNAME")       << "\n" << "\n";

		cout << "OS Name : "    << uts.sysname              << "\n";
		cout << "OS Release : " << uts.release              << "\n";
		cout << "Platform : "   << uts.machine              << "\n";

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
		std::cout << "/* CPU INFORMATION */\n\n";

		cout << "CPU Model : "           << CPU_model                 << "\n";
		cout << "CPU Core Count : "      << CPU_coreCount             << "\n";
		cout << "CPU Thread Count : "    << CPU_threadCount           << "\n";
		cout << "CPU Cache Size : "      << CPU_cacheSize << "KB"     << "\n" << "\n";

		cout << "L1d Cache Size : "      << l1dcachesize  << "B"      << "\n";
		cout << "L1i Cache Size : "      << l1icachesize  << "B"      << "\n";
		cout << "L2  Cache Size : "      << l2cachesize   << "B"      << "\n";
		cout << "L3  Cache Size : "      << l3cachesize   << "B"      << "\n";

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
		std::cout << "/* CPU / PROCESS / MEMORY / NETWORK  --  ACTIVITY INFORMATION */\n\n";

		system("top -F -n0 -l1 | grep \"Processes\" > /tmp/processes.txt");
		system("top -F -n0 -l1 | grep \"CPU usage\" > /tmp/cpu_usage.txt");
		system("top -F -n0 -l1 | grep \"PhysMem\"   > /tmp/mem_usage.txt");
		system("top -F -n0 -l1 | grep \"Network\"   > /tmp/networks.txt");

		infile.open(("/tmp/processes.txt"));
		if (infile.is_open()) {
			std::getline(infile, line, '\0');
			std::cout << line;
			infile.close();
		}

		infile.open(("/tmp/cpu_usage.txt"));
		if (infile.is_open()) {
			std::getline(infile, line, '\0');
			std::cout << line;
			infile.close();
		}

		infile.open(("/tmp/mem_usage.txt"));
		if (infile.is_open()) {
			std::getline(infile, line, '\0');
			std::cout << line;
			infile.close();
		}

		infile.open(("/tmp/networks.txt"));
		if (infile.is_open()) {
			std::getline(infile, line, '\0');
			std::cout << line;
			infile.close();
		}

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		do {
			t2 = high_resolution_clock::now();
			time_span = duration_cast<duration<double>>(t2 - t1);
		} while ( time_span.count() < 1.0 /* second */ );

	}

	return 0;
}
