#pragma once
#include "ProcessorVerifier.h"
class PlugProcessorVerifier :
    public ProcessorVerifier
{
public:
    // constructors and destructor
    PlugProcessorVerifier(string ID, IProcessor* processor) : ProcessorVerifier(ID, processor) {};
    //
    void ProcessorPreparing(DataSet* data, Logger* lg);
    string Process(Image* processed, Logger* lg);
    // internal data verification methods
    bool Verification(DataSet* data) { return true; }      
    bool Verification(Image* img) { return true; } 
};

