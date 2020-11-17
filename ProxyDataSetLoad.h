#pragma once

// common
#include "IDataSetLoad.h"

// special
#include "DataSetLoadAdapter.h"

class ProxyDataSetLoad :
    public IDataSetLoad
{
private:
    string ID;
    IDataSetLoad* LoadDataSetAction = nullptr;
public:
    // constructors and destructor
    ProxyDataSetLoad();
    ProxyDataSetLoad(string ID, IDataSetLoad* LoadDataSetAction);   // custom constructor
    ~ProxyDataSetLoad();    // need for subject cleaning
    // request
    DataSet* Load(string path, DataSet* dsObj, Logger* lg);
};

