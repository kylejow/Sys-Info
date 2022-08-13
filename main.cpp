/* references:
json              https://github.com/nlohmann/json
hardware info     https://docs.microsoft.com/en-us/windows/win32/sysinfo/getting-hardware-information?redirectedfrom=MSDN
ram usage         https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-memorystatusex
ram usage         https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex
Cpu usage (Jeremy Friesner) https://stackoverflow.com/questions/23143693/retrieving-cpu-load-percent-total-in-windows-with-c
*/
#include <thread>
#include <atomic>

#include "Hardware_Classes.h"

int GetPolling(void);
void PrintRamUsage(MEMORYSTATUSEX &memStat);
void PrintCpuUsage(void);
static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
static unsigned long long FileTimeToInt64(const FILETIME & ft);
float GetCPULoad();
void stopProgram(std::atomic_bool& stop);

int main(){
   //system information
   const char* infile = "Hardware_Classes.vbs";
   nlohmann::ordered_json Sys_Info = Hardware_Classes(infile);

   //ram usage
   MEMORYSTATUSEX memStat;
   memStat.dwLength = sizeof (memStat);

   std::atomic_bool stop;

   std::string input;
   while(1){
      stop = false;
      system("cls");
      cout << "1. Print System Info\n"
           << "2. Monitor RAM usage\n"
           << "3. Monitor Cpu usage\n"
           << "4. Monitor all usage\n"
           << "\n\nq to exit" << endl;
      cin >> input;
      if(input == "1"){
         system ("cls");
         for(auto iter1 = Sys_Info.begin(); iter1 != Sys_Info.end(); ++iter1){
            cout << iter1.key() << ": \n";
            for(auto iter2 = Sys_Info[iter1.key()].begin(); iter2 != Sys_Info[iter1.key()].end(); ++iter2){
               cout << "    " << iter2.key() << ": "<< (*iter2).get<std::string>() << "\n";
            }
         }
         cout << "\n\n";
         system("pause");
      }else if(input == "2"){
         int polling = GetPolling();
         std::thread stopThread(stopProgram, std::ref(stop));
         while(!stop){
            system ("cls");
            GlobalMemoryStatusEx(&memStat);
            PrintRamUsage(memStat);
            cout << "\n\n\nPress enter to exit" << endl;
            Sleep(polling);
         }
         stopThread.join();
      }else if(input == "3"){
         int polling = GetPolling();
         std::thread stopThread(stopProgram, std::ref(stop));
         while(!stop){
            system ("cls");
            PrintCpuUsage();
            cout << "\n\n\nPress enter to exit" << endl;
            Sleep(polling);
         }
         stopThread.join();
      }else if(input == "4"){
         int polling = GetPolling();
         std::thread stopThread(stopProgram, std::ref(stop));
         while(!stop){
            system ("cls");
            GlobalMemoryStatusEx(&memStat);
            PrintRamUsage(memStat);
            cout << "\n";
            PrintCpuUsage();
            cout << "\n\n\nPress enter to exit" << endl;
            Sleep(polling);
         }
         stopThread.join();
      }else if(input == "q")
         break;
   }
   system ("cls");
   return 0;
}

int GetPolling(void){
   system ("cls");
   int polling;
   cout << "Enter polling rate in milliseconds: ";
   cin >> polling;
   return polling;
}

void PrintRamUsage(MEMORYSTATUSEX &memStat){
   DWORDLONG total_ram = memStat.ullTotalPhys/1048576;
   DWORDLONG used_ram = total_ram - memStat.ullAvailPhys/1048576;
   cout << "RAM: " << used_ram  << "/" << total_ram << " MB (" << memStat.dwMemoryLoad << "%)";
}

void PrintCpuUsage(){
   cout << "Cpu: " << GetCPULoad()*50 << "%";
}

static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks){
   static unsigned long long _previousTotalTicks = 0;
   static unsigned long long _previousIdleTicks = 0;

   unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
   unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;

   float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);

   _previousTotalTicks = totalTicks;
   _previousIdleTicks = idleTicks;
   return ret;
}

static unsigned long long FileTimeToInt64(const FILETIME & ft){
   return (((unsigned long long)(ft.dwHighDateTime))<<32)|((unsigned long long)ft.dwLowDateTime);
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.  Returns -1.0 on error.
float GetCPULoad(){
   FILETIME idleTime, kernelTime, userTime;
   return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime)+FileTimeToInt64(userTime)) : -1.0f;
}

void stopProgram(std::atomic_bool& stop){
   cin.ignore(256,'\n');
   std::cin.get();
   stop = true;
   return;
}