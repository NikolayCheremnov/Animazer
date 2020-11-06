#include "ProxyDataSetLoad.h"

ProxyDataSetLoad::ProxyDataSetLoad()
{
	ID = "someID";
	LoadDataSetAction = new PlugDataSetLoad();
}

ProxyDataSetLoad::ProxyDataSetLoad(string ID, IDataSetLoad* LoadDataSetAction)
{
	this->ID = ID;
	if (typeid(LoadDataSetAction).name() == typeid(this).name()) // exclude proxy chain
		throw exception("proxy cannot include the proxy subject");
	this->LoadDataSetAction = LoadDataSetAction;
}

ProxyDataSetLoad::~ProxyDataSetLoad()
{
	if (LoadDataSetAction != nullptr)
		delete LoadDataSetAction;
}

DataSet* ProxyDataSetLoad::Load(string path, DataSet* dsObj, Logger* lg)
{
	if (dsObj != nullptr) { 
		lg->log(__FUNCTION__, "proxy", "perform dataset saving", ID, "loading is not approved");
		throw exception("old dataset not saved. try to save old dataset");
	}
	lg->log(__FUNCTION__, "proxy", "perform dataset saving", ID, "loading is approved");
	return LoadDataSetAction->Load(path, dsObj, lg);
}
