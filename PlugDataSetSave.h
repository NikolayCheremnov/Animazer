#pragma once

// external

// common
#include "IDataSetSave.h"
// special
#include "PlugDataSet.h"

class PlugDataSetSave :
    public IDataSetSave
{
public:
    void Save(string path, DataSet* saved, Logger* lg);
};

