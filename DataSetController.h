#pragma once

//external
#include <string>
// common
#include "DataSet.h"
#include "IDataSetSave.h"
#include "IDataSetLoad.h"

// special
#include "PlugDataSet.h"
#include "PlugDataSetSave.h"
#include "PlugDataSetLoad.h"

class DataSetController
{
private:
	string ID;
	DataSet* dsObj = nullptr;
	IDataSetSave* SaveDataSetAction = nullptr;
	IDataSetLoad* LoadDataSetAction = nullptr;
public:
	// constructors and destructor
	DataSetController();
	~DataSetController();
	// setters and getters
	DataSet* GetDataSet() { return dsObj; }
	// perform methods
	void PerformDataSetSaving(string path, Logger* lg);
	void PerformDataSetLoading(string path, Logger* lg);
};

