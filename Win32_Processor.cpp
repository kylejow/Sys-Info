/*References
https://github.com/nlohmann/json
*/

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "json.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using json = nlohmann::json;

int main(){
    system("Win32_Processor.vbs");
    json Win32_Processor;
    
    ifstream file("Win32_Processor.txt");
    std::string line;
    
    getline(file, line);
    Win32_Processor["Name"] = line;
    getline(file, line);
    Win32_Processor["Operating System"] = line;
    getline(file, line);
    Win32_Processor["Architecture"] = line;
    getline(file, line);
    Win32_Processor["Number of Logical Cores"] = line;
    getline(file, line);
    Win32_Processor["Manufacturer"] = line;
    getline(file, line);
    Win32_Processor["Processor Name"] = line;
    getline(file, line);
    Win32_Processor["Number of Cores"] = line;
    getline(file, line);
    Win32_Processor["Base Clock Speed"] = line;
    file.close();
    remove("Win32_Processor.txt");
    cout << Win32_Processor.dump(2) << endl;

}  