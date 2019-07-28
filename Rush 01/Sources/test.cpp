
#include <iostream>

#include <stdlib.h>
#include <unistd.h>

#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysctl.h>

#include <fstream>
#include <chrono>
#include <ctime>

#include <cpuid.h>

using namespace std;
using namespace std::chrono;

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.
float GetCPULoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
      unsigned long long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}

static double ParseMemValue(const char * b)
{
   while((*b)&&(isdigit(*b) == false)) b++;
   return isdigit(*b) ? atof(b) : -1.0;
}

// Returns a number between 0.0f and 1.0f, with 0.0f meaning all RAM is available, and 1.0f meaning all RAM is currently in use
float GetSystemMemoryUsagePercentage()
{
   FILE * fpIn = popen("/usr/bin/vm_stat", "r");
   if (fpIn)
   {
      double pagesUsed = 0.0, totalPages = 0.0;
      char buf[512];
      while(fgets(buf, sizeof(buf), fpIn) != NULL)
      {
         if (strncmp(buf, "Pages", 5) == 0)
         {
            double val = ParseMemValue(buf);
            if (val >= 0.0)
            {
               if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
               totalPages += val;
            }
         }
         else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0) break;  // Stop at "Translation Faults", we don't care about anything at or below that
      }
      pclose(fpIn);

      if (totalPages > 0.0) return (float) (pagesUsed/totalPages);
   }
   return -1.0f;  // indicate failure
}

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
