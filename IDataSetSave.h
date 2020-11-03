#pragma once

// internal
#include <string>
// common
#include "Logger.h"
#include "DataSet.h"

// data set save interface
class IDataSetSave
{
public:
	virtual void Save(std::string path, DataSet* saved, Logger* lg) = 0;
}; 

