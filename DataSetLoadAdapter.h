#pragma once

// common
#include "IDataSetLoad.h"

// special
#include "PlugDataSetLoad.h"

class DataSetLoadAdapter :
    public IDataSetLoad
{
private:
    PlugDataSetLoad* PlugLoadDataSetAction;

public:
    DataSetLoadAdapter() { PlugLoadDataSetAction = new PlugDataSetLoad(); }
    ~DataSetLoadAdapter() { delete PlugLoadDataSetAction; }

    DataSet* Load(std::string path, DataSet* dsObj, Logger* lg) {
        lg->log(__FUNCTION__, "adaptor", "load dataset object", "plug adapter", "dataset load adapter is working");	// write log
        return PlugLoadDataSetAction->Load(path, lg);
    }
};

