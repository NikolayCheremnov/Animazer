#pragma once
#include "IProcessor.h"

class PlugProcessor :
    public IProcessor
{
private:
    string ID;
    bool isPrepared = false;
public:
    PlugProcessor();
    void ProcessorPreparing(DataSet* data, Logger* lg);
    string Process(Image* processed, Logger* lg);
};

