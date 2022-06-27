/* references:
https://docs.microsoft.com/en-us/windows/win32/sysinfo/getting-hardware-information
https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-system_info
*/

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

int main(){
   // Copy the hardware information to the SYSTEM_INFO structure. 
   SYSTEM_INFO siSysInfo;
   GetSystemInfo(&siSysInfo);

   std::string input;
   while(1){
      system ("cls");
      cout << "1. Print System Info" << endl;
      cout << "\n\nq to exit" << endl;
      cin >> input;
      if(input == "1"){
         system ("cls");
         WORD arch = siSysInfo.wProcessorArchitecture;
         cout << "CPU Architecture: ";
         if(std::to_string(arch) == "9")
            cout << "x64 (AMD or Intel)" << endl;
         else if(std::to_string(arch) == "5")
            cout << "ARM" << endl;
         else if(std::to_string(arch) == "12")
            cout << "ARM64" << endl;
         else if(std::to_string(arch) == "6")
            cout << "Intel Itanium-based" << endl;
         else if(std::to_string(arch) == "0")
            cout << "x86" << endl;
         else
            cout << "Unknown architecture." << endl;
         cout << "Number of Logical Processors: " << siSysInfo.dwNumberOfProcessors << endl;
         cout << "Revision: " << siSysInfo.wProcessorRevision << endl;
         cout << "\n\n\n";
         system("pause");
      }
      else if(input == "q"){
         break;
      }

   }
   system ("cls");
   
   /*
   // Display the contents of the SYSTEM_INFO structure. 
   printf("Hardware information: \n");  
   printf("  OEM ID: %u\n", siSysInfo.dwOemId);
   printf("  Number of processors: %u\n", 
      siSysInfo.dwNumberOfProcessors); 
   printf("  Page size: %u\n", siSysInfo.dwPageSize); 
   printf("  Processor type: %u\n", siSysInfo.dwProcessorType); 
   printf("  Minimum application address: %lx\n", 
      siSysInfo.lpMinimumApplicationAddress); 
   printf("  Maximum application address: %lx\n", 
      siSysInfo.lpMaximumApplicationAddress); 
   printf("  Active processor mask: %u\n", 
      siSysInfo.dwActiveProcessorMask); 
      */
}