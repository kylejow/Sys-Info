/* references:
https://github.com/nlohmann/json
*/

#include "Hardware_Classes.h"

int main(){
   const char* infile = "Hardware_Classes.vbs";
   nlohmann::ordered_json Sys_Info = Hardware_Classes(infile);
   std::string input;
   while(1){
      system("cls");
      cout << "1. Print System Info" << endl;
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
      }
      else if(input == "q"){
         break;
      }
   }
   system ("cls");
   return 0;
}