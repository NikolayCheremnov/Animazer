#pragma once

#include <string>

class IDataSetSaver
{
public:
	IDataSetSaver();
	virtual void SaveDataSet(std::string path) = 0;
};

