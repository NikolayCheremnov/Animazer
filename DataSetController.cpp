#include "DataSetController.h"

DataSetController::DataSetController()
{
	ID = "some_id";
	SaveDataSetAction = new PlugDataSetSave();
	LoadDataSetAction = new PlugDataSetLoad();
}

DataSetController::~DataSetController()
{
	if (dsObj != nullptr)
		delete dsObj;
	if (SaveDataSetAction != nullptr)
		delete SaveDataSetAction;
	if (LoadDataSetAction != nullptr)
		delete LoadDataSetAction;
}

void DataSetController::PerformDataSetSaving(string path, Logger *lg)
{
	lg->log(__FUNCTION__, "proxy", "perform dataset saving", ID, "saving is approved");
	SaveDataSetAction->Save(path, dsObj, lg);
	delete dsObj;
	dsObj = nullptr;
}

void DataSetController::PerformDataSetLoading(string path, Logger* lg)
{
	if (dsObj != nullptr) {
		lg->log(__FUNCTION__, "proxy", "perform dataset saving", ID, "loading is not approved");
		throw exception("old dataset not saved. try to save old dataset");
	}
	lg->log(__FUNCTION__, "proxy", "perform dataset saving", ID, "loading is approved");
	dsObj = LoadDataSetAction->Load(path, lg);
}
