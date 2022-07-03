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
    Computer["Computer"]["Physical Memory"] = line;
    getline(file, line);
    Computer["Cpu"]["Manufacturer"] = line;
    getline(file, line);
    Computer["Cpu"]["Name"] = line;
    getline(file, line);
    Computer["Cpu"]["Number of Cores"] = line;
    getline(file, line);
    Computer["Cpu"]["Base Clock Speed"] = line;
    getline(file, line);

    int num_gpus = std::stoi(line);
    for(int i = 0; i < num_gpus; i++){
        getline(file, line);
        Computer["Gpu"][std::to_string(i+1)] = line;
    }

    getline(file, line);
    Computer["Motherboard"]["Manufacturer"] = line;
    getline(file, line);
    Computer["Motherboard"]["Name"] = line;
    file.close();
    remove("Hardware_Classes.txt");
    return Computer;
    //cout << Hardware_Classes.dump(2) << endl;
}  