#pragma once

// external

// common
#include "Logger.h"
#include "DataSet.h"

// data set load interface
class IDataSetLoad
{
public:
	virtual DataSet* Load(std::string path, DataSet* dsObj, Logger* lg) = 0;
};

