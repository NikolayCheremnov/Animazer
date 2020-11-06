#pragma once

// common
#include "IDataSetLoad.h"

//special
#include "PlugDataSet.h"

using namespace std;

class PlugDataSetLoad :
    public IDataSetLoad
{
public:
    DataSet* Load(string path, DataSet* dsObj, Logger* lg);
};

