#include "PlugDataSetLoad.h"

DataSet* PlugDataSetLoad::Load(string path, DataSet* dsObj, Logger* lg)
{
	try {
		PlugDataSet* loaded = new PlugDataSet();
		char* buf = new char[50];
		ifstream fin(path);
		fin >> buf;
		fin.close();
		loaded->SetSetData(buf);
		lg->log(__FUNCTION__, "delegate", "load dataset object", "plug", "initialized successful");
		return loaded;
	}
	catch (exception ex) {
		lg->log(__FUNCTION__, "delegate", "load dataset object", "plug", ex.what());	// write exception log
		throw ex;																			// and throw an exception above
	}
}
