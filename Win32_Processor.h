#ifndef WIN32_PROCESSOR_H // include guard
#define WIN32_PROCESSOR_H

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

json Win32_Processor(const char* filename);

#endif