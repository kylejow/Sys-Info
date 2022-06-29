/* references:
https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-system_info
https://github.com/nlohmann/json
*/

#include "Win32_Processor.h"

int main(){
   std::string input;
   while(1){
      system ("cls");
      cout << "1. Print System Info" << endl;
      cout << "\n\nq to exit" << endl;
      cin >> input;
      if(input == "1"){
         system ("cls");
         const char* cpu_vbs = "Win32_Processor.vbs";
         nlohmann::ordered_json cpu = Win32_Processor(cpu_vbs);
         for (auto it = cpu.begin(); it != cpu.end(); ++it) {
            std::cout << it.key() << ": " << *it << endl;
         }
         cout << "\n\n\n";
         system("pause");
      }
      else if(input == "q"){
         break;
      }

   }
   system ("cls");
}