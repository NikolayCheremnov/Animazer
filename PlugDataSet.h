#pragma once
#include "DataSet.h"
class PlugDataSet :
    public DataSet
{
private:
    char* setData = nullptr;

public:
    // constructors and destructor
    PlugDataSet();
    ~PlugDataSet();

    // setters and getters
    char* GetSetData() { return setData; }
    void SetSetData(char* val);
};

