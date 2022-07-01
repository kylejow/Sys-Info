#include "Hardware_Classes.h"

nlohmann::ordered_json Hardware_Classes(const char* filename){
    system(filename);
    nlohmann::ordered_json Computer;
    ifstream file("Hardware_Classes.txt");
    std::string line;
    getline(file, line);
    Computer["Computer"]["Name"] = line;
    getline(file, line);
    Computer["Computer"]["Operating System"] = line;
    getline(file, line);
    Computer["Computer"]["Architecture"] = line;
    getline(file, line);
    Computer["Cpu"]["Manufacturer"] = line;
    getline(file, line);
    Computer["Cpu"]["Processor Name"] = line;
    getline(file, line);
    Computer["Cpu"]["Number of Cores"] = line;
    getline(file, line);
    Computer["Cpu"]["Base Clock Speed"] = line;
    file.close();
    remove("Hardware_Classes.txt");
    return Computer;
    //cout << Hardware_Classes.dump(2) << endl;
}  