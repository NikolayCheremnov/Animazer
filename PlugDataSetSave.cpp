#include "PlugDataSetSave.h"

void PlugDataSetSave::Save(string path, DataSet* saved, Logger* lg)
{
	try {
		PlugDataSet* dsObj = (PlugDataSet*)saved;	// type coercion
		ofstream fout(path);
		fout << dsObj->GetSetData();
		fout.close();
		lg->log(__FUNCTION__, "delegate", "save dataset object", "plug", "saved successful");
	}
	catch (exception ex) {
		lg->log(__FUNCTION__, "delegate", "save dataset object", "plug", ex.what());			// write exception log
		throw ex;																			// and throw an exception above
	}
}
