#include "PlugProcessor.h"

PlugProcessor::PlugProcessor()
{
    ID = "plug";
}

void PlugProcessor::ProcessorPreparing(DataSet* data, Logger* lg)
{
    isPrepared = true;
    lg->log(__FUNCTION__, "successor", "processor preparing", ID, "successful prepared");
}

string PlugProcessor::Process(Image* processed, Logger* lg)
{
    if (!isPrepared) {
        lg->log(__FUNCTION__, "successor", "image processing", ID, "processor is not ready");
        return "the processor is not ready";
    }
    lg->log(__FUNCTION__, "successor", "image processing", ID, "successful processed");
    return "some_animal";
}
