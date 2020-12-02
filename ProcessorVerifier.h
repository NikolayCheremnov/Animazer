#pragma once
#include "IProcessor.h"

// decorator
class ProcessorVerifier :
    public IProcessor
{
protected:
    IProcessor* processor = nullptr;    // decorated
    string ID;

public:
    // constructors and destructor
    ProcessorVerifier(string ID, IProcessor* processor);
    ~ProcessorVerifier() {
        if (processor != nullptr)
            delete processor;
    }
    // virtual override (maybe you don't need to)
    //virtual void ProcessorPreparing(DataSet* data, Logger* lg) = 0;
    //virtual string Process(Image* processed, Logger* lg) = 0;
};

