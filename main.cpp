/* references:
json              https://github.com/nlohmann/json
hardware info     https://docs.microsoft.com/en-us/windows/win32/sysinfo/getting-hardware-information?redirectedfrom=MSDN
ram usage         https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-memorystatusex
ram usage         https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex
*/

#include "Hardware_Classes.h"

int main(){
   //system information
   const char* infile = "Hardware_Classes.vbs";
   nlohmann::ordered_json Sys_Info = Hardware_Classes(infile);

   //ram usage
   MEMORYSTATUSEX memStat;
   memStat.dwLength = sizeof (memStat);

   std::string input;
   while(1){
      system("cls");
      cout << "1. Print System Info" << endl;
      cout << "2. Monitor RAM usage" << endl;
      cout << "\n\nq to exit" << endl;
      cin >> input;
      if(input == "1"){
         system ("cls");
         for(auto iter1 = Sys_Info.begin(); iter1 != Sys_Info.end(); ++iter1){
            cout << iter1.key() << ": " << endl;
            for(auto iter2 = Sys_Info[iter1.key()].begin(); iter2 != Sys_Info[iter1.key()].end(); ++iter2){
               cout << "    " << iter2.key() << ": "<< (*iter2).get<std::string>() << endl;
            }
         }
         cout << "\n\n";
         system("pause");
      }else if(input == "2"){
         while(1){
            system ("cls");
            GlobalMemoryStatusEx(&memStat);
            cout << memStat.ullAvailPhys/1048576 << "/" << memStat.ullTotalPhys/1048576 << " MB (" << memStat.dwMemoryLoad << "%)" << endl;
            cout << "\n\nCtrl + C to exit" << endl;
            Sleep(50);
         }
      }else if(input == "q"){
         break;
      }
   }
   system ("cls");
   return 0;
}