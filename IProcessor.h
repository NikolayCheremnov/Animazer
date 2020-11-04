#pragma once

// common
#include "DataSet.h"
#include "Image.h"
#include "Logger.h"

class IProcessor
{
public:
	virtual void ProcessorPreparing(DataSet* data, Logger* lg) = 0;
	virtual string Process(Image* processed, Logger* lg) = 0;
};

