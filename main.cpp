/* references:
https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-system_info
https://github.com/nlohmann/json
*/

#include "Hardware_Classes.h"

int main(){
   const char* infile = "Hardware_Classes.vbs";
   nlohmann::ordered_json cpu = Hardware_Classes(infile);
   std::string input;
   while(1){
      system ("cls");
      cout << "1. Print System Info" << endl;
      cout << "\n\nq to exit" << endl;
      cin >> input;
      if(input == "1"){
         system ("cls");
         for (auto it = cpu.begin(); it != cpu.end(); ++it) {
            std::cout << it.key() << ": " << (*it).get<std::string>() << endl;
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