#include "Hardware_Classes.h"

nlohmann::ordered_json Hardware_Classes(const char* filename){
    system(filename);
    nlohmann::ordered_json Hardware_Classes;
    ifstream file("Hardware_Classes.txt");
    std::string line;
    getline(file, line);
    Hardware_Classes["Name"] = line;
    getline(file, line);
    Hardware_Classes["Operating System"] = line;
    getline(file, line);
    Hardware_Classes["Architecture"] = line;
    getline(file, line);
    Hardware_Classes["Manufacturer"] = line;
    getline(file, line);
    Hardware_Classes["Processor Name"] = line;
    getline(file, line);
    Hardware_Classes["Number of Cores"] = line;
    getline(file, line);
    Hardware_Classes["Base Clock Speed"] = line;
    file.close();
    remove("Hardware_Classes.txt");
    return Hardware_Classes;
    //cout << Hardware_Classes.dump(2) << endl;
}  