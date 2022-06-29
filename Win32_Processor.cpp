#include "Win32_Processor.h"

nlohmann::ordered_json Win32_Processor(const char* filename){
    system(filename);
    nlohmann::ordered_json Win32_Processor;
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
    return Win32_Processor;
    //cout << Win32_Processor.dump(2) << endl;
}  