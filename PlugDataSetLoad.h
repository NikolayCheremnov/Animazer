#pragma once

// common
#include "Logger.h"

//special
#include "PlugDataSet.h"

using namespace std;

class PlugDataSetLoad 
{
public:
    DataSet* Load(string path, Logger* lg);
};

